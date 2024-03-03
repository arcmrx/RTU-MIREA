#include <iostream>
using namespace std;
int main()
{
    cout << "\x1B[2J\x1B[H";
    int n, k;
    cout << "Введите N мест : " << endl;
    if (!(cin >> n))
    {
        cout << "Некорректные данные";
        return 0;
    }
    cout << "Введите K школьников : " << endl;
    if (!(cin >> k))
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (n == 0)
    {
        cout << "Мест нет";
        return 0;
    }
    if (n < 0)
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (k == 0)
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (k < 0)
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (n < k)
    {
        cout << "Некорректные данные";
        return 0;
    }
    while (k != 1)
    {
        n = (n - k % 2) / 2;
        k /= 2;
    }
    cout << (n - 1) / 2 << " " << n / 2 << endl;
    return 0;
}