#include "Task.h"
#include <iostream>

MyObject::MyObject(int value)
{
    availableProperty = value;
    hiddenProperty = 2 * value;
}

void MyObject::changeProperties()
{
    availableProperty += 1;
    hiddenProperty += 4;
}

void MyObject::callHiddenMethod()
{
    hiddenMethod();
}

void MyObject::displayState()
{
    std::cout << "Value of the available property " << availableProperty << "; Value of a hidden property " << hiddenProperty << std::endl;
}

void MyObject::hiddenMethod()
{
    availableProperty += 5;
    hiddenProperty += 7;
}