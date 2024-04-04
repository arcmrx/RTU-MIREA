#include <iostream>

struct Matrix
{
    int size;
    int data[100][100];
};

void printClockwise(const Matrix &matrix)
{
    int top = 0, bottom = matrix.size - 1;
    int left = 0, right = matrix.size - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; ++i)
        {
            std::cout << matrix.data[top][i] << " ";
        }
        ++top;

        for (int i = top; i <= bottom; ++i)
        {
            std::cout << matrix.data[i][right] << " ";
        }
        --right;

        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
            {
                std::cout << matrix.data[bottom][i] << " ";
            }
            --bottom;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
            {
                std::cout << matrix.data[i][left] << " ";
            }
            ++left;
        }
    }
}

Matrix inputMatrix()
{
    Matrix matrix;
    std::cout << "Введите размер квадратной матрицы: ";
    std::cin >> matrix.size;

    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < matrix.size; ++i)
    {
        for (int j = 0; j < matrix.size; ++j)
        {
            std::cin >> matrix.data[i][j];
        }
    }
    return matrix;
}

int main()
{
    Matrix matrix = inputMatrix();

    std::cout << "Элементы матрицы по часовой стрелке начиная с первой строки:\n";
    printClockwise(matrix);

    return 0;
}
