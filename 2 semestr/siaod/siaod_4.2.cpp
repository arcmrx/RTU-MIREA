#include <iostream>
#include <vector>

struct typeX
{
    unsigned int size = 0;
    std::vector<int> array = {};
};

void printClockwise(const typeX &matrix, int n)
{
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; ++i)
        {
            std::cout << matrix.array[top * n + i] << " ";
        }
        ++top;

        for (int i = top; i <= bottom; ++i)
        {
            std::cout << matrix.array[i * n + right] << " ";
        }
        --right;

        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
            {
                std::cout << matrix.array[bottom * n + i] << " ";
            }
            --bottom;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
            {
                std::cout << matrix.array[i * n + left] << " ";
            }
            ++left;
        }
    }
}

typeX inputMatrix(int n)
{
    typeX matrix;
    matrix.size = n * n;
    matrix.array.resize(n * n);
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n * n; ++i)
    {
        std::cin >> matrix.array[i];
    }
    return matrix;
}

int main()
{
    int n;
    std::cout << "Введите размер квадратной матрицы: ";
    std::cin >> n;

    typeX matrix = inputMatrix(n);

    std::cout << "Элементы матрицы по часовой стрелке начиная с первой строки:\n";
    printClockwise(matrix, n);

    return 0;
}
