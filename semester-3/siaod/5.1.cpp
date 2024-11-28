#include <iostream>
#include <bitset>

using namespace std;

// Задача 1: Операция побитового ИЛИ с маской
void task1()
{
    unsigned int a = 0xFF;
    cout << "Число в 10й сс: " << a << endl;
    cout << "В 2й сс: " << bitset<32>(a) << endl;

    int mask = (0 << 18) | (0 << 15) | (0 << 2);

    a |= mask;

    bitset<32> binary(a);
    cout << "Новое значение: " << a << endl;
    cout << "В 2й сс: " << binary << endl;
}

// Задача 2: Операция побитового И с маской
void task2()
{
    unsigned int a;
    cout << "Введите число: ";
    cin >> a;

    bitset<32> binary(a);
    cout << "Число в 2м формате: " << binary << endl;

    int mask = (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2);

    a &= mask;

    bitset<32> newbinary(a);
    cout << "Новое число в 2м формате: " << newbinary << endl;
    cout << "Новое значение в 10м формате: " << a << endl;
}

// Задача 3: Сдвиг влево на 5 позиций (умножение на 32)
void task3()
{
    unsigned int a;
    cout << "Введите число: ";
    cin >> a;

    bitset<32> binary(a);
    cout << "Число в 2м формате: " << binary << endl;

    a <<= 5;

    bitset<32> newbinary(a);
    cout << "Новое число в 2м формате: " << newbinary << endl;
    cout << "Новое значение в 10м формате: " << a << endl;
}

// Задача 4: Сдвиг вправо на 5 позиций (деление на 32)
void task4()
{
    unsigned int a;
    cout << "Введите число: ";
    cin >> a;

    bitset<32> binary(a);
    cout << "Число в 2м формате: " << binary << endl;

    a >>= 5;

    bitset<32> newbinary(a);
    cout << "Новое число в 2м формате: " << newbinary << endl;
    cout << "Новое значение в 10м формате: " << a << endl;
}

// Задача 5: Инверсия 11, 13 и 17 позиции
void task5()
{
    int a;
    cout << "Введите число: ";
    cin >> a;

    bitset<32> binary(a);
    cout << "Число в 2м формате: " << binary << endl;

    int mask = (1 << 11) | (1 << 13) | (1 << 17);

    a ^= mask;

    bitset<32> newbinary(a);
    cout << "Новое число в 2м формате: " << newbinary << endl;
    cout << "Новое значение в 10м формате: " << a << endl;
}

int main()
{
    setlocale(LC_ALL, "");
    std::cout << "\x1B[2J\x1B[H";

    int choice;
    do
    {
        cout << "\nВыберите задачу (1-5) или 0 для выхода: " << endl;
        cout << "1 - Задание 1 (Операция побитового ИЛИ с маской)" << endl;
        cout << "2 - Задание 2 (Операция побитового И с маской)" << endl;
        cout << "3 - Задание 3 (Сдвиг влево на 5 позиций)" << endl;
        cout << "4 - Задание 4 (Сдвиг вправо на 5 позиций)" << endl;
        cout << "5 - Задание 5 (Инверсия заданных битов)" << endl;
        cout << "0 - Выход" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }

    } while (choice != 0);

    return 0;
}

