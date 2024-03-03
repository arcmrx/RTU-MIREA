#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "\x1B[2J\x1B[H";
    string text;
    cout << "Введите текст: ";
    getline(cin, text);

    vector<string> sentences;
    int start = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences.push_back(text.substr(start, i - start + 1));
            start = i + 1;
        }
    }

    int min_length = 1000000000;
    int min_index = -1;
    for (int i = 0; i < sentences.size(); i++)
    {
        if (sentences[i].length() < min_length)
        {
            min_length = sentences[i].length();
            min_index = i;
        }
    }

    cout << sentences[min_index] << endl;

    return 0;
}