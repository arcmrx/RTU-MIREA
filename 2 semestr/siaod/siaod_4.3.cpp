#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    double x, y;
};

// Функция, вычисляющая площадь треугольника по трем точкам
double triangleArea(const Point &A, const Point &B, const Point &C)
{
    return abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}

// Функция, проверяющая, лежит ли точка D внутри треугольника ABC
bool isInsideTriangle(const Point &A, const Point &B, const Point &C, const Point &D)
{
    double ABC = triangleArea(A, B, C);
    double ABD = triangleArea(A, B, D);
    double ACD = triangleArea(A, C, D);
    double BCD = triangleArea(B, C, D);
    return (ABC == ABD + ACD + BCD);
}

int main()
{
    vector<Point> points1;
    // Вводим координаты  точек
    cout << "Введите кол-во точек первого множества: ";
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        Point p;
        cout << "Ввдите X" << i << " и Y" << i << ": ";
        cin >> p.x >> p.y;
        points1.push_back(p);
    }

    Point A = points1[0];
    Point B = points1[1];
    Point C = points1[2];
    Point D = {1, 1};

    if (isInsideTriangle(A, B, C, D))
    {
        cout << "D в ABC.\n";
    }
    else
    {
        cout << "D НЕ в ABC.\n";
    }

    return 0;
}
