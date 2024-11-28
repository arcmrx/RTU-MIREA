import os
import sys
import csv
import tarfile
import datetime

class ShellEmulator:
    def __init__(self, hostname, fs_path):
        self.hostname = hostname
        self.fs_path = fs_path
        self.current_dir = '/'
        self.fs_root = '/Path/to/output/folder/'
        self.load_filesystem()

    def load_filesystem(self):
        if not os.path.exists(self.fs_root):
            os.makedirs(self.fs_root)
        with tarfile.open(self.fs_path, 'r') as tar:
            tar.extractall(self.fs_root)

    def run(self):
        while True:
            command = input(f"{self.hostname}:{self.current_dir}$ ").strip()
            if command == 'exit':
                break
            elif command == 'ls':
                self.ls()
            elif command.startswith('cd '):
                self.cd(command[3:])
            elif command == 'pwd':
                self.pwd()
            elif command == 'date':
                self.date()
            else:
                print(f"Command not found: {command}")

    def ls(self):
        path = os.path.join(self.fs_root, self.current_dir.lstrip('/'))
        try:
            for item in os.listdir(path):
                print(item)
        except FileNotFoundError:
            print(f"ls: cannot access '{self.current_dir}': No such file or directory")

    def cd(self, path):
        if path == '/':
            self.current_dir = '/'
        elif path == '..':
            self.current_dir = os.path.dirname(self.current_dir.rstrip('/'))
            if not self.current_dir:
                self.current_dir = '/'
        else:
            new_dir = os.path.join(self.current_dir, path).rstrip('/')
            if os.path.isdir(os.path.join(self.fs_root, new_dir.lstrip('/'))) and path!= '.' and path!="./" and path!="../":
                self.current_dir = new_dir
            else:
                print(f"cd: no such file or directory: {path}")

    def pwd(self):
        print(self.current_dir)

    def date(self):
        print(datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S'))

def read_config(config_path):
    with open(config_path, 'r') as file:
        reader = csv.reader(file)
        next(reader)
        for row in reader:
            return row[0], row[1]

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python emulator.py <config.csv>")
        sys.exit(1)

    config_path = sys.argv[1]
    hostname, fs_path = read_config(config_path)
    emulator = ShellEmulator(hostname, fs_path)
    emulator.run()