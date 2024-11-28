#include <iostream>
#include <string>
using namespace std;

int d(char x)
{
    switch (x)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
    return 0;
}

int convert(string x)
{
    int i, l, j, r, k, a;
    j = 0;
    r = 0;
    k = 0;
    a = 0;
    l = x.length();

    for (i = l; i >= 0; i--)
    {
        if (d(x[i]) >= j)
        {
            if (d(x[i]) == j)
            {
                k++;
                r += d(x[i]);

                if (k == 4)
                {
                    return 0;
                }
            }
            else
            {
                r += d(x[i]);
                j = d(x[i]);
            }
        }

        else if ((j - d(x[i])) % 5 == 0)
        {
            return 0;
        }
        else
        {
            if (a == 0)
            {
                r -= d(x[i]);
                j = d(x[i]);
                a++;
            }
            else
            {
                return 0;
            }
        }
    }
    return r;
}

int main()
{
    cout << "\x1B[2J\x1B[H";
    setlocale(LC_ALL, " ");
    string s;
    int r;
    cout << "Введите римское цисло: ";
    cin >> s;
    r = convert(s);
    if (convert(s) == 0)
    {
        cout << "Некорректные данные ";
        return 0;
    }

    cout << r << endl;
    return 0;
}