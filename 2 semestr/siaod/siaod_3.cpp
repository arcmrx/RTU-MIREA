#include <iostream>
#include <vector>
#include <cmath>

typedef unsigned int typeitem;

struct typeX
{
    unsigned int size = 0;
    std::vector<typeitem> array = {};
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
    for (unsigned int i = 0; i < size; ++i)
    {
        typeitem num;
        std::cin >> num;
        arr.array.push_back(num);
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
            newArray.array.push_back(num);
            newArray.size++;
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

    return 0;
}
