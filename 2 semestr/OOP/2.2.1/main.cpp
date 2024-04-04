#include <iostream>
#include "Task.h"

int main()
{
    int i_data;
    std::cin >> i_data;

    MyObject obj(i_data);

    obj.displayState();

    obj.changeProperties();

    obj.displayState();

    std::cin >> i_data;
    obj.availableProperty *= i_data;

    obj.displayState();

    obj.callHiddenMethod();

    obj.displayState();

    return 0;
}