#include <iostream>
#include <cstring>
using namespace std;

void readSentence(char *sentence, int maxLength)
{
    cout << "Введите предложение: ";
    cin.getline(sentence, maxLength);
}

void splitSentence(char *sentence, char **words, int &wordCount)
{
    char *token = strtok(sentence, " ,");
    while (token != nullptr)
    {
        words[wordCount] = new char[strlen(token) + 1];
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(nullptr, " ,");
    }
}

void transformWord(char *word)
{
    int length = strlen(word);
    char lastLetter = word[length - 1];
    for (int i = length - 1; i > 0; i--)
    {
        word[i] = word[i - 1];
    }
    word[0] = lastLetter;

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length;)
        {
            if (word[i] == word[j])
            {
                for (int k = j; k < length; k++)
                {
                    word[k] = word[k + 1];
                }
                length--;
            }
            else
            {
                j++;
            }
        }
    }
}

void printTransformedWords(char **words, int wordCount)
{
    cout << "Преобразованные слова:" << endl;
    for (int i = 0; i < wordCount; i++)
    {
        cout << words[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int maxLength = 100;
    char sentence[maxLength];
    char *words[maxLength / 2];
    int wordCount = 0;

    readSentence(sentence, maxLength);
    splitSentence(sentence, words, wordCount);

    for (int i = 0; i < wordCount; i++)
    {
        transformWord(words[i]);
    }

    printTransformedWords(words, wordCount);

    for (int i = 0; i < wordCount; i++)
    {
        delete[] words[i];
    }

    return 0;
}

// For example, in some places, women cannot freely select their clothing, get education or work in specific jobs.