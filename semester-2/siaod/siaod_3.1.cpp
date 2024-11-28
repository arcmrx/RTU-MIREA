#include <iostream>
#include <cmath>

typedef unsigned int typeitem;

struct typeX
{
    unsigned int size = 0;
    typeitem *array = nullptr;
};

int digitalRoot(int num)
{
    while (num > 9)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

void fillArrayFromKeyboard(typeX &arr, unsigned int size)
{
    std::cout << "Введите " << size << " чисел:\n";
    arr.array = (typeitem *)malloc(size * sizeof(typeitem));
    if (arr.array == nullptr)
    {
        std::cerr << "Ошибка выделения памяти!\n";
        exit(1);
    }
    for (unsigned int i = 0; i < size; ++i)
    {
        typeitem num;
        std::cin >> num;
        arr.array[i] = num;
        arr.size++;
    }
}

typeX formArrayWithSingleDigitRoots(const typeX &originalArray)
{
    typeX newArray;

    for (unsigned int i = 0; i < originalArray.size; ++i)
    {
        int num = originalArray.array[i];
        if (digitalRoot(num) < 10)
        {
            newArray.array = (typeitem *)realloc(newArray.array, (newArray.size + 1) * sizeof(typeitem));
            if (newArray.array == nullptr)
            {
                std::cerr << "Ошибка выделения памяти!\n";
                exit(1);
            }
            newArray.array[newArray.size++] = num;
        }
    }

    return newArray;
}

void printArray(const typeX &arr)
{
    for (unsigned int i = 0; i < arr.size; ++i)
    {
        std::cout << arr.array[i] << " ";
    }
    std::cout << "\n";
}

void freeArray(typeX &arr)
{
    free(arr.array);
    arr.array = nullptr;
    arr.size = 0;
}

int main()
{
    typeX originalArray;

    unsigned int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    fillArrayFromKeyboard(originalArray, size);

    typeX newArray = formArrayWithSingleDigitRoots(originalArray);

    std::cout << "Новый массив с однозначными цифровыми корнями:\n";
    printArray(newArray);

    freeArray(originalArray);
    freeArray(newArray);

    return 0;
}