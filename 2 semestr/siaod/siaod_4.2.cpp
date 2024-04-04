#include <iostream>
#include <vector>

struct typeitem
{
    int value;
};

struct typeX
{
    unsigned int size = 0;
    std::vector<typeitem> array = {};
};

void printClockwise(const std::vector<std::vector<int>> &matrix)
{
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; ++i)
        {
            std::cout << matrix[top][i] << " ";
        }
        ++top;

        for (int i = top; i <= bottom; ++i)
        {
            std::cout << matrix[i][right] << " ";
        }
        --right;

        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
            {
                std::cout << matrix[bottom][i] << " ";
            }
            --bottom;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
            {
                std::cout << matrix[i][left] << " ";
            }
            ++left;
        }
    }
}

std::vector<std::vector<int>> inputMatrix(int n)
{
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}

int main()
{
    int n;
    std::cout << "Введите размер квадратной матрицы: ";
    std::cin >> n;

    std::vector<std::vector<int>> matrix = inputMatrix(n);

    std::cout << "Элементы матрицы по часовой стрелке начиная с первой строки:\n";
    printClockwise(matrix);

    return 0;
}