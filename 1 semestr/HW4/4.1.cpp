#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  cout << "\x1B[2J\x1B[H";
  setlocale(LC_ALL, "ru");
  cout << "Введите 10 чисел: " << endl;
  int i = 0;
  double sum = 0;
  double digital = 0;

  ofstream file("4.1.txt");
  while (i != 10)
  {
    i += 1;
    cout << i << ") ";
    if (cin >> digital)
    {
      file << digital << "\n";
    }
    else
    {
      cout << "Некорректные данные" << endl;
      return 0;
    }
  }
  file.close();

  ifstream ifile("4.1.txt");
  while (i != 20)
  {
    ifile >> digital;
    sum += digital;
    i += 1;
  }
  ifile.close();

  cout << "Сумма чисел = " << sum << endl;
  return 0;
}