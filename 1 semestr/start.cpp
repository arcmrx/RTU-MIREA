#include <iostream>

int main()
{
    setlocale(LC_ALL, "");
    std::cout << ("\e[1;1H\e[2J");
    return 0;
}