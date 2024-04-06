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

void printClockwise(typeX matrix, int n)
{
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; ++i)
        {
            std::cout << matrix.array[top * n + i].value << " ";
        }
        ++top;

        for (int i = top; i <= bottom; ++i)
        {
            std::cout << matrix.array[i * n + right].value << " ";
        }
        --right;

        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
            {
                std::cout << matrix.array[bottom * n + i].value << " ";
            }
            --bottom;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
            {
                std::cout << matrix.array[i * n + left].value << " ";
            }
            ++left;
        }
    }
}

void inputMatrix(typeX &matrix, int n)
{
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n * n; ++i)
    {
        std::cin >> matrix.array[i].value;
    }
    matrix.size = n * n;
}

int main()
{
    int n;
    std::cout << "Введите размер квадратной матрицы: ";
    std::cin >> n;

    typeX matrix;

    inputMatrix(matrix, n);

    std::cout << "Элементы матрицы по часовой стрелке начиная с первой строки:\n";
    printClockwise(matrix, n);

    return 0;
}