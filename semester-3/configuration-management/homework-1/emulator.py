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
        self.tar = tarfile.open(self.fs_path, 'r')

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
        try:
            if self.current_dir == '/':
                dir_path = '.'
            else:
                dir_path = '.' + self.current_dir
            dir_path = dir_path.rstrip('/')
            items = set()
            for member in self.tar.getmembers():

                if member.name == '.':
                    continue

                member_path = member.name.rstrip('/')

                if dir_path == '.':
                    parts = member_path.split('/')
                    if len(parts) == 2 and parts[0] == '.':
                        items.add(parts[1])

                else:
                    if member_path.startswith(dir_path + '/'):
                        rel_path = member_path[len(dir_path) + 1:]

                        if '/' not in rel_path:
                            items.add(rel_path)

            if items:
                for item in sorted(items):

                    if '.' in item.split('/')[-1]:
                        print("\033[1;35m" + item + "\033[0m" + ' 📄')
                    else:
                        print("\033[1;34m" + item + "\033[0m" + ' 📁')

            else:
                print("No files or directories.")
        except Exception as e:
            print(f"ls: error accessing '{self.current_dir}': {e}")

    def cd(self, path):
        if not path:
            return

        if path == '/':
            self.current_dir = '/'
            return
        if path == '..':
            if self.current_dir == '/':
                return
            parent = os.path.dirname(self.current_dir.rstrip('/'))
            self.current_dir = '/' if parent == '' else parent
            return

        if path.startswith('/'):
            new_dir = path
        else:
            if self.current_dir == '/':
                new_dir = '/' + path
            else:
                new_dir = os.path.normpath(f"{self.current_dir}/{path}")

        new_dir = new_dir.replace('./', '/')

        if self.directory_exists(new_dir):
            self.current_dir = new_dir
        else:
            print(f"cd: no such file or directory: {path}")

    def directory_exists(self, dir_path):
        normalized_path = dir_path.rstrip('/')
        if normalized_path == '':
            return True

        if normalized_path.startswith('/'):
            normalized_path = '.' + normalized_path
        elif not normalized_path.startswith('./'):
            normalized_path = './' + normalized_path

        for member in self.tar.getmembers():
            member_path = member.name.rstrip('/')
            if member_path == normalized_path and member.isdir():
                return True
        return False

    def pwd(self):
        print(self.current_dir)

    def date(self):
        print(datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S'))

    def get_full_path(self, relative_path):
        if relative_path == '/':
            return './'
        return os.path.normpath('./' + self.current_dir.lstrip('/') + '/' + relative_path.lstrip('/'))

    def is_valid_directory(self, path):
        full_path = self.get_full_path(path)
        for member in self.tar.getmembers():
            if member.name.startswith(full_path) and member.isdir():
                return True
        return False


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
