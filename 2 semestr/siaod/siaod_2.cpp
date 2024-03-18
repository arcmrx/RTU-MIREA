#include <iostream>

typedef unsigned int typeitem;
const unsigned int N = 100;

struct typeX
{
    unsigned int size = 0;
    typeitem array[N] = {};
};

void input_array(typeX *arr)
{
    std::cout << "Введите размер массива: \n";
    std::cin >> arr->size;

    std::cout << "Введите элементы массива: \n";
    for (int i = 0; i < arr->size; i++)
    {
        std::cin >> arr->array[i];
    }
}

void output_array(typeX *arr)
{
    std::cout << "Массив: \n";
    for (int i = 0; i < arr->size; i++)
    {
        std::cout << arr->array[i] << " ";
    }
    std::cout << "\n";
}

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

int findPosition(typeX *arr)
{
    for (int i = 0; i < arr->size; ++i)
    {
        if (digitalRoot(arr->array[i]) == 7)
        {
            return i;
        }
    }
    return -1;
}

void insertBefore7(typeX *arr)
{
    int new_elem;
    std::cout << "Введите вставляемый элемент: \n";
    std::cin >> new_elem;
    if (digitalRoot(new_elem) == 7)
    {
        std::cout << "Новый элемент имеет цифровой корень 7." << std::endl;
        return;
    }
    int position = findPosition(arr);
    if (position == -1)
    {
        std::cout << "Элемент с цифровым корнем 7 не найден." << std::endl;
        return;
    }
    typeX newArr;
    newArr.size = arr->size + 1;
    for (int i = 0, j = 0; i < newArr.size; ++i)
    {
        if (i == position)
        {
            newArr.array[i] = new_elem;
        }
        else
        {
            newArr.array[i] = arr->array[j++];
        }
    }
    *arr = newArr;
    std::cout << "Элемент успешно вставлен перед 7.\n";
}

void remove7RootElem(typeX *arr)
{
    int position = findPosition(arr);
    if (position == -1)
    {
        std::cout << "Элемент с цифровым корнем 7 не найден." << std::endl;
        return;
    }
    typeX newArr;
    newArr.size = arr->size - 1;
    for (int i = 0, j = 0; i < newArr.size; ++i)
    {
        if (j == position)
        {
            ++j;
        }
        newArr.array[i] = arr->array[j++];
    }
    *arr = newArr;
    std::cout << "Элемент успешно удален.\n";
}

int main()
{
    setlocale(LC_ALL, "");
    typeX arr;

    input_array(&arr);
    output_array(&arr);
    insertBefore7(&arr);
    output_array(&arr);
    remove7RootElem(&arr);
    output_array(&arr);
    return 0;
}
