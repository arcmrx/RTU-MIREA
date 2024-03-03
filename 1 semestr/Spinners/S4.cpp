#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "\x1B[2J\x1B[H";
    vector<int> v(9, 0);
    int n;
    cout << "Введите кол-во свободных мест" << endl;
    if (!(cin >> n))
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (n < 0 or n > 54)
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (n == 0)
    {
        cout << "0";
        return 0;
    }
    int max = 0;
    int flag = 1000;
    int f = 0;
    cout << "Введите номера свободных мест" << endl;
    for (int i = 0; i < n; i++)
    {
        int m;
        if (!(cin >> m))
        {
            cout << "Некорректные данные";
            return 0;
        }
        if (m <= 0 or m > 54)
        {
            cout << "Некорректные данные";
            return 0;
        }
        if (1 <= m && m <= 4 || m == 53 || m == 54)
        {
            v[0] += 1;
        }
        else if (5 <= m && m <= 8 || m == 51 || m == 52)
        {
            v[1] += 1;
        }
        else if (9 <= m && m <= 12 || m == 49 || m == 50)
        {
            v[2] += 1;
        }
        else if (13 <= m && m <= 16 || m == 47 || m == 48)
        {
            v[3] += 1;
        }
        else if (17 <= m && m <= 20 || m == 45 || m == 46)
        {
            v[4] += 1;
        }
        else if (21 <= m && m <= 24 || m == 43 || m == 44)
        {
            v[5] += 1;
        }
        else if (25 <= m && m <= 28 || m == 41 || m == 42)
        {
            v[6] += 1;
        }
        else if (29 <= m && m <= 32 || m == 39 || m == 40)
        {
            v[7] += 1;
        }
        else if (33 <= m && m <= 36 || m == 37 || m == 38)
        {
            v[8] += 1;
        }
    }
    cout << "[";
    for (int i = 0; i < 9; i++)
    {
        cout << v[i];
        if (i != 8)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    for (int i = 0; i < 9; i++)
    {
        if (v[i] == 6)
        {
            f += 1;
        }
        if (flag > max)
        {
            max = f;
        }
        else
        {
            flag = 0;
        }
    }
    cout << max << endl;
    return 0;
}