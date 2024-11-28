#include <iostream>
using namespace std;

int main()
{
    cout << "\x1B[2J\x1B[H";
    setlocale(LC_ALL, "ru");
    int m1 = 37, b1 = 3, c1 = 64, m2 = 25173, b2 = 13849, c2 = 65537, i, temp_i1 = 0, temp_i2 = 0;
    cout << "Введите число i: ";
    if (!(cin >> i))
    {
        cout << "Некорректные данные";
        return 0;
    }
    int s1[i], s2[i];
    s1[0] = 0;
    s2[0] = 0;

    while (temp_i1 != i + 1)
    {
        cout << temp_i1 << ") " << s1[temp_i1] << endl;
        s1[temp_i1 + 1] = (m1 * s1[temp_i1] + b1) % c1;
        temp_i1 += 1;
    }
    cout << endl;
    while (temp_i2 != i + 1)
    {
        cout << temp_i2 << ") " << s2[temp_i2] << endl;
        s2[temp_i2 + 1] = (m2 * s2[temp_i2] + b2) % c2;
        temp_i2 += 1;
    }
    cout << endl;
    cout << temp_i1 << ") " << s1[temp_i1] << endl;
    cout << temp_i2 << ") " << s2[temp_i2] << endl;
    return 0;
}