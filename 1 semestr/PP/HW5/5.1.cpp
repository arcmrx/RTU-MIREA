#include <iostream>
#include <cmath>
using namespace std;

int minuss(int a, int b)
{
    while (a > 0 and b > 0)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a + b;
}

int devision(int a, int b)
{
    while (a > 0 and b > 0)
        if (a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}

int main()
{
    cout << "\x1B[2J\x1B[H";
    double a, b;
    cout << "Введите a: ";
    if (!(cin >> a))
    {
        cout << "Некорректные данные";
        return 0;
    }
    cout << "Введите b: ";
    if (!(cin >> b))
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (a == 0 or b == 0)
    {
        cout << "Некорректные данные" << endl;
    }
    else
    {
        cout << "Вычитание = " << minuss(abs(a), abs(b)) << endl
             << "Деление = " << devision(abs(a), abs(b)) << endl;
    }
}