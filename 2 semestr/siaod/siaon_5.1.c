#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000 // Определяем максимальную длину строки

// Функция для ввода строки
void inputString(char *str, int maxLen)
{
    printf("Введите строку: ");
    fgets(str, maxLen, stdin);      // Считываем строку из ввода пользователя
    str[strcspn(str, "\n")] = '\0'; // Удаляем символ новой строки, если он есть
}

// Функция для вывода строки
void printString(const char *str)
{
    printf("Строка: %s\n", str); // Печатаем строку
}

// Функция для переноса последней буквы в начало и удаления повторных букв
void transformWord(char *word)
{
    int len = strlen(word); // Получаем длину слова
    if (len == 0)           // Если слово пустое, ничего не делаем
        return;

    // Перенос последней буквы в начало
    char lastChar = word[len - 1];    // Сохраняем последнюю букву
    for (int i = len - 1; i > 0; i--) // Сдвигаем все буквы вправо
    {
        word[i] = word[i - 1];
    }
    word[0] = lastChar; // Ставим последнюю букву на первое место

    // Удаление повторных букв
    int writeIndex = 1; // Индекс для записи уникальных букв
    for (int i = 1; i < len; i++)
    {
        int j;
        for (j = 0; j < writeIndex; j++)
        {
            if (tolower(word[i]) == tolower(word[j])) // Проверяем на наличие дубликатов (без учета регистра)
            {
                break;
            }
        }
        if (j == writeIndex) // Если буква уникальна
        {
            word[writeIndex++] = word[i]; // Записываем её в слово
        }
    }
    word[writeIndex] = '\0'; // Завершаем строку символом конца строки
}

// Функция для выделения слов и их преобразования
void processSentence(char *str, const char *delim)
{
    char *token = strtok(str, delim); // Разделяем строку на слова
    while (token != NULL)
    {
        transformWord(token);        // Преобразуем каждое слово
        printf("%s\n", token);       // Выводим преобразованное слово
        token = strtok(NULL, delim); // Переходим к следующему слову
    }
}

// Функция меню
void menu()
{
    char str[MAX_LEN]; // Переменная для хранения строки
    int choice;        // Переменная для выбора действия пользователя
    while (1)
    {
        printf("\nМеню:\n");
        printf("1. Ввод строки\n");
        printf("2. Вывод строки\n");
        printf("3. Преобразовать строку\n");
        printf("4. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice); // Считываем выбор пользователя
        getchar();            // Убираем символ новой строки после ввода числа

        switch (choice)
        {
        case 1:
            inputString(str, MAX_LEN); // Ввод строки
            break;
        case 2:
            printString(str); // Вывод строки
            break;
        case 3:
            processSentence(str, " ,"); // Преобразование строки
            break;
        case 4:
            return; // Выход из программы
        default:
            printf("Неверный выбор, попробуйте снова.\n"); // Сообщение об ошибочном выборе
            break;
        }
    }
}

int main()
{
    menu(); // Запуск меню
    return 0;
}