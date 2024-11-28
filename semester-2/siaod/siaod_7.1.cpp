#include <iostream>  // Подключение библиотеки ввода-вывода
#include <string>    // Подключение библиотеки строк
#include <set>       // Подключение библиотеки множеств
using namespace std; // Использование пространства имен std

// Определение структуры узла
struct Node
{
    char data;  // Данные узла (символ)
    Node *next; // Указатель на следующий узел
};

// Функция вставки узла в начало списка
void insertAtHead(Node *&head, char data)
{
    Node *newNode = new Node{data, head}; // Создание нового узла
    head = newNode;                       // Обновление указателя head
}

// Функция вставки узла в конец списка
void insertAtTail(Node *&head, char data)
{
    Node *newNode = new Node{data, nullptr}; // Создание нового узла
    if (head == nullptr)                     // Если список пуст
    {
        head = newNode; // Новый узел становится головой списка
    }
    else
    {
        Node *current = head;            // Начинаем с головы списка
        while (current->next != nullptr) // Ищем конец списка
        {
            current = current->next; // Переходим к следующему узлу
        }
        current->next = newNode; // Присоединяем новый узел в конец списка
    }
}

// Функция создания списка из строки
Node *createList(const string &data)
{
    Node *head = nullptr; // Изначально список пуст
    for (char ch : data)  // Для каждого символа в строке
    {
        insertAtHead(head, ch); // Вставляем символ в начало списка
    }
    return head; // Возвращаем указатель на голову списка
}

// Функция вывода списка
void printList(Node *head)
{
    Node *current = head;      // Начинаем с головы списка
    while (current != nullptr) // Пока не достигнут конец списка
    {
        cout << current->data << " "; // Выводим данные текущего узла
        current = current->next;      // Переходим к следующему узлу
    }
    cout << endl; // Печатаем новую строку в конце списка
}

// 1. Определение самой длинной последовательности одинаковых символов
pair<Node *, int> findLongestSequence(Node *head)
{
    Node *maxStart = nullptr; // Указатель на начало самой длинной последовательности
    int maxLength = 0;        // Длина самой длинной последовательности

    Node *current = head;      // Начинаем с головы списка
    while (current != nullptr) // Пока не достигнут конец списка
    {
        Node *sequenceStart = current;    // Начало текущей последовательности
        char currentChar = current->data; // Текущий символ
        int length = 0;                   // Длина текущей последовательности

        while (current != nullptr && current->data == currentChar) // Пока символы совпадают
        {
            length++;                // Увеличиваем длину последовательности
            current = current->next; // Переходим к следующему узлу
        }

        if (length > maxLength) // Если текущая последовательность длиннее найденной ранее
        {
            maxLength = length;       // Обновляем максимальную длину
            maxStart = sequenceStart; // Обновляем указатель на начало последовательности
        }
    }

    return {maxStart, maxLength}; // Возвращаем указатель на начало и длину самой длинной последовательности
}

// 2. Удаление всех подряд идущих одинаковых символов, оставляя только один
void removeConsecutiveDuplicates(Node *head)
{
    if (head == nullptr) // Если список пуст
        return;

    Node *current = head;            // Начинаем с головы списка
    while (current->next != nullptr) // Пока не достигнут конец списка
    {
        if (current->data == current->next->data) // Если текущий и следующий символы одинаковы
        {
            Node *temp = current->next;          // Временный указатель на следующий узел
            current->next = current->next->next; // Пропускаем следующий узел
            delete temp;                         // Удаляем следующий узел
        }
        else
        {
            current = current->next; // Переходим к следующему узлу
        }
    }
}

// 3. Создание нового списка из цифр исходного списка в порядке возрастания без повторений
Node *createSortedDigitList(Node *head)
{
    set<char> digits;     // Множество для хранения уникальных цифр
    Node *current = head; // Начинаем с головы списка

    while (current != nullptr) // Пока не достигнут конец списка
    {
        if (isdigit(current->data)) // Если текущий символ - цифра
        {
            digits.insert(current->data); // Добавляем цифру в множество
        }
        current = current->next; // Переходим к следующему узлу
    }

    Node *newHead = nullptr;  // Изначально новый список пуст
    for (char digit : digits) // Для каждой цифры в множестве
    {
        insertAtTail(newHead, digit); // Вставляем цифру в конец нового списка
    }

    return newHead; // Возвращаем указатель на голову нового списка
}

// Тестирование
int main()
{

    // Установка языка и очистка терминала
    setlocale(LC_ALL, "");        // Устанавливаем локаль (настройки языка)
    std::cout << "\x1B[2J\x1B[H"; // Очистка терминала

    // Вводим исходный список
    string data;                   // Строка для ввода данных
    cout << "Введите список: ";    // Вывод приглашения к вводу
    cin >> data;                   // Ввод строки
    Node *list = createList(data); // Создаем список из введенной строки
    cout << "Исходный список: ";   // Вывод заголовка
    printList(list);               // Печать списка

    // 1. Определение самой длинной последовательности одинаковых символов
    auto [start, length] = findLongestSequence(list); // Находим самую длинную последовательность
    cout << "Самая длинная последовательность одинаковых символов начинается с '"
         << start->data << "' и имеет длину " << length << "." << endl; // Вывод результата

    // 2. Удаление всех подряд идущих одинаковых символов, оставляя только один
    removeConsecutiveDuplicates(list); // Удаляем подряд идущие дубликаты
    cout << "Список после удаления подряд идущих одинаковых символов: ";
    printList(list); // Печать обновленного списка

    // 3. Создание нового списка из цифр исходного списка в порядке возрастания без повторений
    Node *digitList = createSortedDigitList(list); // Создаем новый список из уникальных цифр
    cout << "Новый список из цифр в порядке возрастания без повторений: ";
    printList(digitList); // Печать нового списка

    // Освобождаем память
    while (list != nullptr) // Пока исходный список не пуст
    {
        Node *temp = list; // Временный указатель на текущий узел
        list = list->next; // Переход к следующему узлу
        delete temp;       // Удаление текущего узла
    }

    while (digitList != nullptr) // Пока новый список не пуст
    {
        Node *temp = digitList;      // Временный указатель на текущий узел
        digitList = digitList->next; // Переход к следующему узлу
        delete temp;                 // Удаление текущего узла
    }

    return 0; // Завершаем программу
}
