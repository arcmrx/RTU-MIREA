#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    cout << "\x1B[2J\x1B[H";
    setlocale(LC_ALL, "ru");
    ofstream readfile("5.3.13.txt");
    if (!readfile.is_open())
    {
        cout << "Файл не может быть открыт!";
    }
    string s;
    cout << "Введите тeкст:" << endl;
    getline(cin, s);
    readfile << s;
    readfile.close();

    ifstream copfile("5.3.13.txt");

    getline(copfile, s);
    cout << s << endl;
    copfile.close();
}