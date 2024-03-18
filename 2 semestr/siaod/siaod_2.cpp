#include <iostream>
#include <cmath>

struct TypeSomething
{
    int size;
    int *arr;
    bool inserted_is_7_root = false;
    int inserted_index;

    void input_array()
    {
        std::cout << "Введите размер массива: \n";
        std::cin >> size;
        arr = new int[size];
        std::cout << "Введите элементы массива: \n";
        for (int i = 0; i < size; i++)
        {
            std::cin >> arr[i];
        }
    }

    void output_array()
    {
        std::cout << "Массив: \n";
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
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

    int findPosition()
    {
        for (int i = 0; i < size; ++i)
        {
            if (digitalRoot(arr[i]) == 7)
            {
                return i;
            }
        }
        return -1;
    }

    void insertBefore7()
    {
        int new_elem;
        std::cout << "Введите вставляемый элемент: \n";
        std::cin >> new_elem;
        if (digitalRoot(new_elem) == 7)
        {
            inserted_is_7_root = true;
        }
        int position = findPosition();
        if (position == -1)
        {
            std::cout << "Элемент с цифровым корнем 7 не найден." << std::endl;
            return;
        }
        inserted_index = position;
        size++;
        int *new_arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            if (i < position)
            {
                new_arr[i] = arr[i];
            }
            else if (i == position)
            {
                new_arr[i] = new_elem;
            }
            else
            {
                new_arr[i] = arr[i - 1];
            }
        }
        delete[] arr;
        arr = new_arr;
    }

    void remove7RootElem()
    {
        int position = findPosition();
        if (position == -1)
        {
            std::cout << "Элемент с цифровым корнем 7 не найден." << std::endl;
            return;
        }
        if (!inserted_is_7_root)
        {
            size--;
            int *new_arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                if (i < position)
                {
                    new_arr[i] = arr[i];
                }
                else
                {
                    new_arr[i] = arr[i + 1];
                }
            }
            delete[] arr;
            arr = new_arr;
        }
        else
        {
            size -= 2;
            int *new_arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                if (i < position && i < inserted_index)
                {
                    new_arr[i] = arr[i];
                }
                else if (i < position || i < inserted_index)
                {
                    new_arr[i] = arr[i + 1];
                }
                else
                {
                    new_arr[i] = arr[i + 2];
                }
            }
            delete[] arr;
            arr = new_arr;
        }
        std::cout << "Массив после удаления элемент:\n";
    }
};

int main()
{
    TypeSomething array;
    array.input_array();
    array.output_array();
    array.insertBefore7();
    array.output_array();
    array.remove7RootElem();
    array.output_array();
    return 0;
}
