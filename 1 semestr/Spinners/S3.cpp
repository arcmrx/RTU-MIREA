#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout << "\x1B[2J\x1B[H";
    int N, M;
    cout << "Введите M, N:" << endl;
    if (!(cin >> N >> M))
    {
        cout << "Некорректные данные";
        return 0;
    }
    if (N > 75000 or M > 75000 or N < 1 or M < 1)
    {
        cout << "Некорректные данные";
        return 0;
    }
    cout << ((N + 1) * N / 2) * ((M + 1) * M / 2) <<endl;

}