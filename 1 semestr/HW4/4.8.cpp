#include <iostream>
using namespace std;

int main()
{
    cout << "\x1B[2J\x1B[H";
    setlocale(LC_ALL, "ru");
    double matrix_a[3][4] = {
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0}};

    double matrix_b[4][2] = {
        {1.20, 0.50},
        {2.80, 0.40},
        {5.00, 1.00},
        {2.00, 1.50}};

    double matrix_c[3][2];

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            for (int i = 0; i < 4; i++)
            {
                matrix_c[x][y] += matrix_a[x][i] * matrix_b[i][y];
            }
        }
    }

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            cout << matrix_c[x][y] << "     ";
        }
        cout << endl;
    }
    cout << endl;

    int maxSeller = 0, minSeller = 0;
    double maxMoney = 0, minMoney = 10000000, maxComss = 0, minComss = 10000000, sumMoney = 0, sumComss = 0, SumMoneyResult = 0;
    for (int x = 0; x < 3; x++)
    {
        if (matrix_c[x][0] > maxMoney)
        {
            maxSeller = x + 1;
            maxMoney = matrix_c[x][0];
        }
        if (matrix_c[x][0] < minMoney)
        {
            minSeller = x + 1;
            minMoney = matrix_c[x][0];
        }
    }
    cout << "Продавец " << maxSeller << " Выручка(Макс): " << maxMoney << endl
         << "Продавец " << minSeller << " Выручка(Мин): " << minMoney << endl;

    maxSeller = 0, minSeller = 0;
    for (int x = 0; x < 3; x++)
    {
        if (matrix_c[x][1] > maxComss)
        {
            maxSeller = x + 1;
            maxComss = matrix_c[x][1];
        }
        if (matrix_c[x][1] < minComss)
        {
            minSeller = x + 1;
            minComss = matrix_c[x][1];
        }
    }
    cout << "Продавец " << maxSeller << " Комиссионные(Макс): " << maxComss << endl
         << "Продавец " << minSeller << " Комиссионные(Мин): " << minComss << endl;

    for (int x = 0; x < 3; x++)
    {
        sumMoney += matrix_c[x][0];
    }
    cout << "Выручка(Сумма): " << sumMoney << endl;

    for (int x = 0; x < 3; x++)
    {
        sumComss += matrix_c[x][1];
    }
    cout << "Комиссионные(Сумма): " << sumComss << endl;

    for (int x = 0; x < 3; x++)
    {
        SumMoneyResult += matrix_c[x][0] + matrix_c[x][1];
    }
    cout << "Общая сумма денег: " << SumMoneyResult << endl
         << endl;
}