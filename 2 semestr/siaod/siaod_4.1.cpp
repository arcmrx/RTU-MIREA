#include <iostream>

struct typeitem
{
    int value;
};

struct typeX
{
    unsigned int size = 0;
    typeitem array[100];
};

void printClockwise(typeitem matrix[][100], int n)
{
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; ++i)
        {
            std::cout << matrix[top][i].value << " ";
        }
        ++top;

        for (int i = top; i <= bottom; ++i)
        {
            std::cout << matrix[i][right].value << " ";
        }
        --right;

        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
            {
                std::cout << matrix[bottom][i].value << " ";
            }
            --bottom;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
            {
                std::cout << matrix[i][left].value << " ";
            }
            ++left;
        }
    }
}

void inputMatrix(typeitem matrix[][100], int n)
{
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> matrix[i][j].value;
        }
    }
}

int main()
{
    int n;
    std::cout << "Введите размер квадратной матрицы: ";
    std::cin >> n;

    typeitem matrix[100][100];

    inputMatrix(matrix, n);

    std::cout << "Элементы матрицы по часовой стрелке начиная с первой строки:\n";
    printClockwise(matrix, n);

    return 0;
}
