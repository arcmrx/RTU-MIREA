#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

// Функция для преобразования слова согласно условиям задачи
string transformWord(string word)
{
    // Перенос последней буквы в начало слова
    char lastChar = word.back(); // Сохраняем последний символ
    word.erase(word.size() - 1); // Удаляем последний символ из строки
    word = lastChar + word;      // Добавляем сохраненный последний символ в начало строки

    // Удаление повторяющихся букв
    word.erase(std::unique(word.begin(), word.end()), word.end()); // Избавляемся от дубликатов

    return word; // Возвращаем преобразованное слово
}

// Функция для разделения строки на слова
void splitString(const string &str, vector<string> &words)
{
    stringstream ss(str); // Создаем поток из строки
    string word;
    while (getline(ss, word, ' ')) // Извлекаем слова из потока, разделенные пробелами
    {
        // Удаление запятых из слова
        word.erase(remove(word.begin(), word.end(), ','), word.end()); // Удаляем запятые из слова
        words.push_back(word);                                         // Добавляем слово в вектор
    }
}

// Функция для вывода преобразованных слов на экран
void printTransformedWords(const vector<string> &words)
{
    cout << "Преобразованные слова:\n";
    for (const auto &word : words)
    {
        cout << transformWord(word) << endl; // Выводим преобразованное слово на экран
    }
}

int main()
{
    string sentence;
    cout << "Введите предложение: ";
    getline(cin, sentence); // Получаем предложение от пользователя

    vector<string> words;
    splitString(sentence, words); // Разделяем предложение на слова

    printTransformedWords(words); // Выводим преобразованные слова на экран

    return 0;
}
