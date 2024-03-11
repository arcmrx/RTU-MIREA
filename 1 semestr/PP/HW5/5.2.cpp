#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "\x1B[2J\x1B[H";
    int n;
    cout << "Введите натуральное число: ";
    if (!(cin >> n))
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (n < 2)
    {
        cout << "Некорректные данные";
        return 0;
    }

    vector<bool> is_prime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    cout << "Простые числа в диапазоне от 2 до " << n << ":" << endl;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}