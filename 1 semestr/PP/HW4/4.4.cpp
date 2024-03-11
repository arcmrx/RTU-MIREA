#include <iostream>
using namespace std;

int main()
{
    cout << "\x1B[2J\x1B[H";
    setlocale(LC_ALL, "ru");
    for (int i = 0; i < 8; i++)
    {
        cout << "  *  *  *  *  *  *";
        cout << "__________________________" << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "____________________________________________" << endl;
    }
    return 0;
}