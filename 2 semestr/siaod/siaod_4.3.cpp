#include <iostream>
#include <vector>

// АТД для точек
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
    // Лирка
    setlocale(LC_ALL, "");
    std::cout << "\x1B[2J\x1B[H";

    std::vector<Point> points1;
    std::vector<Point> points2;
    std::vector<int> CountsIn1;
    std::vector<int> CountsIn2;

    // Вводим координаты точек первого множества
    std::cout << "Введите кол-во точек первого множества: ";
    int count1;
    std::cin >> count1;
    for (int i = 1; i <= count1; ++i)
    {
        Point p1;
        std::cout << "Ввдите X" << i << " и Y" << i << ": ";
        std::cin >> p1.x >> p1.y;
        points1.push_back(p1);
    }

    // Вводим координаты точек второго множества
    std::cout << "Введите кол-во точек второго множества: ";
    int count2;
    std::cin >> count2;
    for (int i = 1; i <= count2; ++i)
    {
        Point p2;
        std::cout << "Ввдите X" << i << " и Y" << i << ": ";
        std::cin >> p2.x >> p2.y;
        points2.push_back(p2);
    }

    // Перебор первого множеств
    int CountIn1 = 0, CountIn2 = 0;
    for (int a = 0; a < count1; a++)
    {
        for (int b = 0; b < count1; b++)
        {
            for (int c = 0; c < count1; c++)
            {
                for (int d = 0; d < count1; d++)
                {
                    // Перебор второго множества
                    for (int i = 0; i < points2.size(); i++)
                    {
                        Point A = points1[a], B = points1[b], C = points1[c], D = points1[d], P2 = points2[i];
                        if ((a != b) && (a != c) && (a != d) && (b != c) && (b != d) && (c != d))
                        {
                            if (isInsideTriangle(A, B, C, D))
                            {
                                CountIn1++;
                            }

                            if (isInsideTriangle(A, B, C, P2))
                            {
                                CountIn2++;
                            }

                            CountsIn1.push_back(CountIn1);
                            CountsIn2.push_back(CountIn2);
                            
                            for (int g = 0; g < CountsIn1.size(); g++)
                            {
                                if ((CountsIn1[g] == CountsIn2[g]) && (CountsIn1[g] != 0) && (CountsIn2[g] != 0) && (a != b) && (a != c) && (a != d) && (b != c) && (b != d) && (c != d))
                                {
                                    std::cout << "\nКоординаты вершин треугольника:\n"
                                              << points1[a].x << " " << points1[a].y << "\n"
                                              << points1[b].x << " " << points1[b].y << "\n"
                                              << points1[c].x << " " << points1[c].y << "\n"
                                              << "\nКоординаты точкек первого множества внутри треугольника:\n"
                                              << points1[d].x << " " << points1[d].y << "\n"
                                              << "\nКоординаты точкек Второго множества внутри треугольника:\n"
                                              << points2[i].x << " " << points2[i].y << "\n";
                                    return 0;
                                }
                            }
                        }
                    }
                    CountIn1 = 0, CountIn2 = 0;
                }
            }
        }
    }
    return 0;
}