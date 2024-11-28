#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout << "\x1B[2J\x1B[H";
    setlocale(0, "");
    int M, L3, L4;
    cout << "Введите M (кол-во лопостей):" << endl;
    if (!(cin >> M))
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (M <= 0)
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (M <= 1)
    {
        L3 = 0;
        L4 = 0;
        cout << L3 << endl;
        cout << L4 << endl;
        return 0;
    }
    if (M % 4 == 3)
    {
        L3 = 1;
        L4 = M / 4;
        cout << L3 << endl;
        cout << L4 << endl;
        return 0;
    }
    if (M % 3 == 1)
    {
        L3 = M / 3 - 1;
        L4 = 1;
        cout << L3 << endl;
        cout << L4 << endl;
        return 0;
    }
    if (M % 4 == 0)
    {
        L3 = 0;
        L4 = M / 4;
        cout << L3 << endl;
        cout << L4 << endl;
        return 0;
    }
    if (M % 3 == 0)
    {
        L3 = M / 3;
        L4 = 0;
        cout << L3 << endl;
        cout << L4 << endl;
        return 0;
    }
    else
    {
        L3 = 0;
        L4 = 0;
        cout << L3 << endl;
        cout << L4 << endl;
        return 0;
    }
}
