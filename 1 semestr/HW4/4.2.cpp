#include <iostream>
using namespace std;

int sign(float x)
{
    if (x > 0)
    {
        return 1;
    }
    else if (x == 0)
    {
        return 0;
    }
    return -1;
}

int main()
{
    cout << "\x1B[2J\x1B[H";
    setlocale(LC_ALL, "ru");
    double x = 0;
    cout << "Введите x = ";
    if (cin >> x)
    {
        cout << sign(x) << endl;
    }
    else
    {
        cout << "Некорректные данные";
        return 0;
    }
}