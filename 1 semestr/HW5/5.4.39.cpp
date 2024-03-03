#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  setlocale(LC_ALL, "ru");
  cout << "\x1B[2J\x1B[H";
  ofstream file("5.4.39.txt");
  string text;
  cout << "Введите текст: ";
  getline(cin, text);
  file << text;

  int num_chars = text.length();
  cout << "Количество символов: " << num_chars << endl;

  return 0;
}