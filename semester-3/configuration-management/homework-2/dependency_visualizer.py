import argparse
import subprocess
import os

def get_all_dependencies(package_name, processed=None):
    if processed is None:
        processed = set()

    # If the package has already been processed, skip it (to prevent infinite loops)
    if package_name in processed:
        return {}

    processed.add(package_name)

    result = subprocess.run(['pip3', 'show', package_name],
                            capture_output=True, text=True)
    if result.returncode != 0:
        raise Exception(f"Error retrieving package info for {package_name}: {result.stderr}")

    requires = None
    for line in result.stdout.splitlines():
        if line.startswith("Requires:"):
            requires = line.split(":")[1].strip()
            break

    dependencies = requires.split(", ") if requires else []

    dependency_tree = {package_name: {}}
    for dep in dependencies:
        dependency_tree[package_name][dep] = get_all_dependencies(dep, processed)

    return dependency_tree

def generate_mermaid_graph(tree):
    graph_lines = []

    def traverse_tree(node, parent=None):
        for child, subtree in node.items():
            if parent and parent != child:  # Avoid self-referencing arrows
                graph_lines.append(f"    {parent} --> {child}")
            traverse_tree(subtree, child)

    traverse_tree(tree)
    return "graph TD\n" + "\n".join(graph_lines)

def save_graph_as_png(graph, output_file, visualizer_path):
    with open("graph.mmd", "w") as f:
        f.write(graph)

    subprocess.run([visualizer_path, "-i", "graph.mmd", "-o", output_file], check=True)
    os.remove("graph.mmd")

def main():
    parser = argparse.ArgumentParser(
        description="Visualize Python package dependencies.")
    parser.add_argument("--visualizer-path", required=True,
                        help="Path to the Mermaid CLI tool.")
    parser.add_argument("--package-name", required=True,
                        help="Name of the package to analyze.")
    parser.add_argument("--output-file", required=True,
                        help="Output file for the dependency graph.")
    parser.add_argument("--repo-url", required=False,
                        help="URL of the repository (not used in this implementation).")

    args = parser.parse_args()

    try:
        dependency_tree = get_all_dependencies(args.package_name)
        graph = generate_mermaid_graph(dependency_tree)
        save_graph_as_png(graph, args.output_file, args.visualizer_path)
        print("Dependency graph generated successfully.")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
