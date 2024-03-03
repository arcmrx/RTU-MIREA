#include <iostream>
using namespace std;

int main()
{
  cout << "\x1B[2J\x1B[H";
  double n;
  int sum = 0, k;

  cout << "Введите n = ";
  if (!(cin >> n))
  {
    cout << "Некорректные данные";
    return 0;
  }
  if (n != (int)n)
  {
    cout << "Некорректные данные";
    return 0;
  }
  k = int(n);
  if (k < 0)
  {
    k = k * -1;
  }
  while (k != 0)
  {
    sum += k % 10;
    k /= 10;
  }
  cout << "Сумма цифр = " << sum << endl;

  return 0;
}