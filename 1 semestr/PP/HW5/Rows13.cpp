#include <iostream>

using namespace std;

int main()
{
  cout << "\x1B[2J\x1B[H";
  setlocale(LC_ALL, "ru");
  int t;

  cout << "Введите m < 27:" << endl;
  if (!(cin >> t))
  {
    cout << "Некорректные данные";
    return 0;
  }
  if (t < 0 or t >= 27)
  {
    cout << "Некорректные данные";
    return 0;
  }

  int count = 0;
  for (int i = 100; i < 1000; i++)
  {
    int sum = 0;
    int n = i;
    while (n > 0)
    {
      sum += n % 10;
      n /= 10;
    }
    if (sum == t)
    {
      count++;
      cout << i << " ";
    }
  }

  cout << endl;
  cout << "Количество трехзначных целых чисел, сумма цифр которых равна " << t << ": " << count << endl;

  return 0;
}