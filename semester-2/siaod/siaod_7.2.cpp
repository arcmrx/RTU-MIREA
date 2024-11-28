#include <iostream> // Для ввода/вывода
#include <string>   // Для работы со строками

// Описание структуры для хранения информации о книге
struct Book
{
    int ticketNumber;             // Номер читательского билета
    std::string bookTitle;        // Название книги
    std::string issueDate;        // Дата выдачи
    std::string returnDate;       // Дата возврата
    std::string actualReturnDate; // Дата фактического возврата
};

// Узел двунаправленного списка
struct Node
{
    Book data;  // Информация о книге
    Node *prev; // Указатель на предыдущий узел
    Node *next; // Указатель на следующий узел
};

// Класс двунаправленного списка
class DoublyLinkedList
{
private:
    Node *head; // Указатель на начало списка
    Node *tail; // Указатель на конец списка

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {} // Конструктор

    // Вставка узла перед первым узлом
    void insertFront(const Book &book)
    {
        Node *newNode = new Node{book, nullptr, head}; // Создание нового узла
        if (head != nullptr)                           // Если список не пуст
        {
            head->prev = newNode; // Установка указателя на предыдущий узел у текущего первого узла
        }
        else // Если список был пуст
        {
            tail = newNode; // Установка указателя на конец списка
        }
        head = newNode; // Установка указателя на начало списка
    }

    // Вывод списка слева направо
    void displayForward() const // Константный метод, который не изменяет объект
    {
        Node *current = head;      // Указатель на текущий узел
        while (current != nullptr) // Пока не достигнут конец списка
        {
            std::cout << "Номер читательского билета: " << current->data.ticketNumber
                      << ", Название книги: " << current->data.bookTitle
                      << ", Дата выдачи: " << current->data.issueDate
                      << ", Дата возврата: " << current->data.returnDate
                      << ", Дата фактического возврата: " << current->data.actualReturnDate << std::endl;
            current = current->next;
        }
    }

    // Вывод списка справа налево
    void displayBackward() const // Константный метод, который не изменяет объект
    {
        Node *current = tail;      // Указатель на текущий узел
        while (current != nullptr) // Пока не достигнут конец списка
        {
            std::cout << "Номер читательского билета: " << current->data.ticketNumber
                      << ", Название книги: " << current->data.bookTitle
                      << ", Дата выдачи: " << current->data.issueDate
                      << ", Дата возврата: " << current->data.returnDate
                      << ", Дата фактического возврата: " << current->data.actualReturnDate << std::endl;
            current = current->prev;
        }
    }

    // Поиск узла по номеру читательского билета
    Node *search(int ticketNumber) const // Константный метод, который не изменяет объект
    {
        Node *current = head;      // Указатель на текущий узел
        while (current != nullptr) // Пока не достигнут конец списка
        {
            if (current->data.ticketNumber == ticketNumber) // Если найден узел с нужным номером читательского билета
            {
                return current; // Возвращаем указатель на этот узел
            }
            current = current->next; // Переход к следующему узлу
        }
        return nullptr; // Если узел не найден
    }

    // Удаление узлов с совпадающими датами возврата
    void removeMatchingReturnDates()
    {
        Node *current = head;      // Указатель на текущий узел
        while (current != nullptr) // Пока не достигнут конец списка
        {
            if (current->data.returnDate == current->data.actualReturnDate) // Если дата возврата совпадает с фактической датой возврата
            {
                Node *nodeToDelete = current; // Указатель на узел, который нужно удалить
                if (current->prev != nullptr) // Если у узла есть предыдущий узел
                {
                    current->prev->next = current->next; // Установка указателя на следующий узел у предыдущего узла
                }
                else
                {
                    head = current->next; // Установка указателя на начало списка
                }
                if (current->next != nullptr) // Если у узла есть следующий узел
                {
                    current->next->prev = current->prev; // Установка указателя на предыдущий узел у следующего узла
                }
                else
                {
                    tail = current->prev; // Установка указателя на конец списка
                }
                current = current->next; // Переход к следующему узлу
                delete nodeToDelete;     // Удаление узла
            }
            else
            {
                current = current->next; // Переход к следующему узлу
            }
        }
    }

    // Очистка списка
    void clear()
    {
        Node *current = head;      // Указатель на текущий узел
        while (current != nullptr) // Пока не достигнут конец списка
        {
            Node *nextNode = current->next; // Указатель на следующий узел
            delete current;                 // Удаление текущего узла
            current = nextNode;             // Переход к следующему узлу
        }
        head = tail = nullptr; // Установка указателей на начало и конец списка
    }

    ~DoublyLinkedList() // Деструктор
    {
        clear(); // Очистка списка
    }
};

// Функция для тестирования
void testDoublyLinkedList()
{
    DoublyLinkedList list; // Создание объекта двунаправленного списка

    Book book1 = {1, "Книга Один", "2024-01-01", "2024-01-10", "2024-01-10"};
    Book book2 = {2, "Книга Два", "2024-02-01", "2024-02-10", "2024-02-09"};
    Book book3 = {3, "Книга Три", "2024-03-01", "2024-03-10", "2024-03-10"};

    list.insertFront(book1); // Вставка узла перед первым узлом
    list.insertFront(book2); // Вставка узла перед первым узлом
    list.insertFront(book3); // Вставка узла перед первым узлом

    std::cout << "Начальный список (слева направо):" << std::endl;
    list.displayForward();

    std::cout << "\nНачальный список (справа налево):" << std::endl;
    list.displayBackward();

    list.removeMatchingReturnDates();

    std::cout << "\nСписок после удаления совпадающих дат возврата (слева направо):" << std::endl;
    list.displayForward();
}

// Текстовое меню для управления программой
void menu()
{
    DoublyLinkedList list; // Создание объекта двунаправленного списка
    int choice;            // Выбор пользователя
    do
    {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить книгу\n";
        std::cout << "2. Показать книги (слева направо)\n";
        std::cout << "3. Показать книги (справа налево)\n";
        std::cout << "4. Найти книгу по номеру читательского билета\n";
        std::cout << "5. Удалить книги с совпадающими датами возврата\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Book book;
            std::cout << "Введите номер читательского билета: ";
            std::cin >> book.ticketNumber;
            std::cin.ignore();
            std::cout << "Введите название книги: ";
            std::getline(std::cin, book.bookTitle);
            std::cout << "Введите дату выдачи: ";
            std::getline(std::cin, book.issueDate);
            std::cout << "Введите дату возврата: ";
            std::getline(std::cin, book.returnDate);
            std::cout << "Введите дату фактического возврата: ";
            std::getline(std::cin, book.actualReturnDate);
            list.insertFront(book);
            break;
        }
        case 2:
            list.displayForward();
            break;
        case 3:
            list.displayBackward();
            break;
        case 4:
        {
            int ticketNumber;
            std::cout << "Введите номер читательского билета: ";
            std::cin >> ticketNumber;
            Node *node = list.search(ticketNumber);
            if (node != nullptr)
            {
                std::cout << "Найденная книга - Номер читательского билета: " << node->data.ticketNumber
                          << ", Название книги: " << node->data.bookTitle
                          << ", Дата выдачи: " << node->data.issueDate
                          << ", Дата возврата: " << node->data.returnDate
                          << ", Дата фактического возврата: " << node->data.actualReturnDate << std::endl;
            }
            else
            {
                std::cout << "Книга не найдена.\n";
            }
            break;
        }
        case 5:
            list.removeMatchingReturnDates();
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
            break;
        }
    } while (choice != 0);
}

int main()
{
    setlocale(LC_ALL, "");        // Устанавливаем локаль (настройки языка)
    std::cout << "\x1B[2J\x1B[H"; // Очистка терминала

    menu(); // Вызов функции меню
    return 0;
}