import argparse
import pkg_resources
import subprocess
import os

def get_dependencies(package_name):
    dependencies = {}
    distribution = pkg_resources.get_distribution(package_name)
    for requirement in distribution.requires():
        dependencies[requirement.project_name] = get_dependencies(requirement.project_name)
    return dependencies

def generate_mermaid_graph(dependencies, package_name):
    graph = f"graph TD\n    {package_name}\n"
    def add_edges(package, deps, graph):
        for dep, subdeps in deps.items():
            graph += f"    {package} --> {dep}\n"
            graph = add_edges(dep, subdeps, graph)
        return graph
    graph = add_edges(package_name, dependencies, graph)
    return graph

def save_graph(graph, output_file, visualizer_path):
    with open("graph.mmd", "w") as f:
        f.write(graph)
    subprocess.run([visualizer_path, "-i", "graph.mmd", "-o", output_file])
    os.remove("graph.mmd")

def main():
    parser = argparse.ArgumentParser(description="Visualize package dependencies.")
    parser.add_argument("--visualizer-path", required=True, help="Path to the graph visualization tool.")
    parser.add_argument("--package-name", required=True, help="Name of the package to analyze.")
    parser.add_argument("--output-file", required=True, help="Path to the output PNG file.")
    parser.add_argument("--repo-url", required=True, help="URL of the repository.")
    args = parser.parse_args()

    dependencies = get_dependencies(args.package_name)
    graph = generate_mermaid_graph(dependencies, args.package_name)
    save_graph(graph, args.output_file, args.visualizer_path)
    print("Graph generated and saved successfully.")

if __name__ == "__main__":
    main()