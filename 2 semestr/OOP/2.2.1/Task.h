#ifndef TASK_H
#define TASK_H

class MyObject
{
private:
    int hiddenProperty;

public:
    int availableProperty;

    MyObject(int value);

    void changeProperties();

    void callHiddenMethod();

    void displayState();

private:
    void hiddenMethod();
};

#endif // TASK_H