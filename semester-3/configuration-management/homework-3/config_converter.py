import argparse
import re
import xml.etree.ElementTree as ET
from xml.dom import minidom
from typing import Union, List


def parse_constant(line: str):
    """Парсит строку с объявлением константы."""
    name, value = line.split(" is ", 1)
    name = name.strip()
    if value.startswith("(") and value.endswith(")"):
        value = tuple(map(int, re.findall(r"\d+", value)))
    else:
        value = int(value.strip())
    return name, value


def evaluate_expression(expression: str, constants: dict):
    """Вычисляет выражение вида ${константа константа операция}."""
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
    """Обрабатывает входные строки и возвращает результат."""
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
            results.append(tuple(map(int, re.findall(r"\d+", line))))

        else:
            match = re.match(
                r"\(\s*(.*)\s*\)\s*\${(\w+)\s+(\w+)\s+([+])\}", line)
            if match:
                array_str, array_name, constant_name, operation = match.groups()
                array = tuple(map(int, re.findall(r"\d+", array_str)))
                constant = constants.get(constant_name)
                if operation == '+':
                    array = tuple(list(array) + [constant])
                results.append(array)

    return results


def write_output(output_file: str, results: List[Union[int, tuple]]):
    """Записывает результаты в XML-файл с красивым форматированием."""
    root = ET.Element("results")

    for result in results:
        if isinstance(result, int):
            ET.SubElement(root, "result").text = str(result)
        elif isinstance(result, tuple):
            array_elem = ET.SubElement(root, "array")
            for num in result:
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

    results = process_input(input_lines)

    write_output(args.output_file, results)


if __name__ == "__main__":
    main()
