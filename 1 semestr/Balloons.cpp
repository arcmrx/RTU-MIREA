#include <iostream>
#include <algorithm>
using namespace std;

bool generate(int *urna, int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        if (urna[i - 1] == i)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "\x1B[2J\x1B[H";
    int n;
    int k = 0;
    int fac = 1;
    int i;
    cout << "Введите n:" << endl;
    if (!(cin >> n))
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (n < 0)
    {
        cout << "Некорректные данные";
        return 0;
    }
    for (i = 1; i <= n; i++)
    {
        fac = fac * i;
    }
    int urna[n];
    for (int i = 0; i != n; i++)
    {
        urna[i] = i + 1;
    }

    for (int i = 0; i < fac; i++)
    {
        next_permutation(urna, urna + n);
        if (generate(urna, n))
        {
            k++;
        }
    }
    cout << k << endl;
    return 0;
}
