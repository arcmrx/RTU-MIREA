#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout << "\x1B[2J\x1B[H";
    setlocale(0, "");
    int A, B, C, N;
    cout << "Введите A, B и C (Стоимость основания спиннера, стоимость одной лопости и максимальную стоимость всего спиннера):" << endl;
    if (!(cin >> A >> B >> C))
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (A <= 0 or B <= 0 or C <= 0)
    {
        cout << "Некорректные данные";
        return 0;
    }
    if ((A > C) or (A <= 0) or (B <= 0) or (C <= 0))
    {
        cout << "Некорректные данные";
        return 0;
    }
    N = ((C - A) / B);
    cout << N << endl;
}
