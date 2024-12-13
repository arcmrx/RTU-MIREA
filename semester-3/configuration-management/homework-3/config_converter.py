import argparse
import re
import xml.etree.ElementTree as ET
from xml.dom import minidom
from typing import Union, List


def parse_constant(line: str):
    name, value = line.split(" is ", 1)
    name = name.strip()
    if value.startswith("(") and value.endswith(")"):
        value = tuple(map(int, re.findall(r"\d+", value)))
    else:
        value = int(value.strip())
    return name, value


def resolve_constants(value, constants):
    if isinstance(value, tuple):
        resolved = []
        for el in value:
            if isinstance(el, str) and el.startswith("${") and el.endswith("}"):
                key = el[2:-1].strip()
                if key not in constants:
                    raise ValueError(f"Unresolved constant in array: {el}")
                resolved.append(constants[key])
            elif el in constants:
                resolved.append(constants[el])
            else:
                try:
                    resolved.append(int(el))
                except ValueError:
                    raise ValueError(
                        f"Unresolved constant or invalid element in array: {el}")
        return tuple(resolved)
    if isinstance(value, str) and value.startswith("${") and value.endswith("}"):
        key = value[2:-1].strip()
        if key not in constants:
            raise ValueError(f"Unresolved constant: {value}")
        return constants[key]
    return value


def evaluate_expression(expression: str, constants: dict):
    match = re.match(r"\$\{(\w+)\s+(\w+)\s+([\w+\-*/modmin()]+)\}", expression)
    if not match:
        raise ValueError(f"Invalid expression: {expression}")

    left, right, operation = match.groups()
    left_value = constants.get(left, left)
    right_value = constants.get(right, right)

    if isinstance(left_value, str):
        left_value = int(left_value)
    if isinstance(right_value, str):
        right_value = int(right_value)

    if operation == '+':
        if isinstance(left_value, tuple) and isinstance(right_value, int):
            return tuple(list(left_value) + [right_value])
        elif isinstance(right_value, tuple) and isinstance(left_value, int):
            return tuple([left_value] + list(right_value))
        return left_value + right_value
    elif operation == '-':
        return left_value - right_value
    elif operation == '*':
        return left_value * right_value
    elif operation == 'mod()':
        return left_value % right_value
    elif operation == 'min()':
        return min(left_value, right_value)
    else:
        raise ValueError(f"Unsupported operation: {operation}")


def process_input(input_lines: List[str]) -> List[Union[int, tuple]]:
    constants = {}
    results = []

    for line in input_lines:
        line = line.strip()

        if " is " in line:
            name, value = parse_constant(line)
            constants[name] = value

        elif line.startswith("${") and line.endswith("}"):
            result = evaluate_expression(line, constants)
            results.append(result)

        elif line.startswith("(") and line.endswith(")"):
            elements = re.findall(r"\$\{[^}]+\}|\w+", line)
            array = []
            for el in elements:
                if el.startswith("${"):

                    resolved = resolve_constants(el, constants)
                    if resolved == el:
                        raise ValueError(f"Unresolved constant in array: {el}")
                    array.append(resolved)
                elif el.isdigit():

                    array.append(int(el))
                else:

                    raise ValueError(f"Invalid element in array: {el}")
            results.append(tuple(array))

        else:
            raise ValueError(f"Invalid syntax: {line}")

    return results


def write_output(output_file: str, results: List[Union[int, tuple]]):
    root = ET.Element("results")

    for result in results:
        if isinstance(result, int):
            ET.SubElement(root, "item").text = str(result)
        elif isinstance(result, tuple):
            array_elem = ET.SubElement(root, "array")
            for num in result:
                if isinstance(num, tuple):
                    nested_array_elem = ET.SubElement(array_elem, "array")
                    for nested_num in num:
                        ET.SubElement(nested_array_elem,
                                      "item").text = str(nested_num)
                else:
                    ET.SubElement(array_elem, "item").text = str(num)

    rough_string = ET.tostring(root, encoding="utf-8")
    parsed = minidom.parseString(rough_string)
    pretty_xml = parsed.toprettyxml(indent="  ")

    xml_declaration = '<?xml version="1.0" encoding="utf-8"?>\n'
    with open(output_file, "w", encoding="utf-8") as f:
        f.write(xml_declaration + pretty_xml.split("\n", 1)[1])


def main():
    parser = argparse.ArgumentParser(
        description="Process a custom configuration language.")
    parser.add_argument("--input-file", required=True,
                        help="Path to the input text file.")
    parser.add_argument("--output-file", required=True,
                        help="Path to the output XML file.")
    args = parser.parse_args()

    with open(args.input_file, "r", encoding="utf-8") as f:
        input_lines = f.readlines()

    try:
        results = process_input(input_lines)
    except ValueError as e:
        print(f"Error: {e}")
        return

    write_output(args.output_file, results)


if __name__ == "__main__":
    main()
