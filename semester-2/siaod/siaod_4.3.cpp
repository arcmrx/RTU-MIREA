#include <iostream>
#include <vector>
struct Point{
    double x, y;
};
double triangleArea(const Point &A, const Point &B, const Point &C){
    return abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}
bool isPointInsideTriangle(const Point &A, const Point &B, const Point &C, const Point &P){
    double ABC = triangleArea(A, B, C);
    double ABP = triangleArea(A, B, P);
    double ACP = triangleArea(A, C, P);
    double BCP = triangleArea(B, C, P);
    return (ABC == ABP + ACP + BCP);
}
void inputPoints(std::vector<Point> &points, int count){
    for (int i = 1; i <= count; ++i){
        Point p;
        std::cout << "Введите X" << i << " и Y" << i << ": ";
        std::cin >> p.x >> p.y;
        points.push_back(p);
    }
}
void iterateTriangles(const std::vector<Point> &points1, const std::vector<Point> &points2, int count1, int count2){
    std::vector<int> CountsIn1;
    std::vector<int> CountsIn2;
    int CountIn1 = 0, CountIn2 = 0;
    for (int a = 0; a < count1; a++){
        for (int b = 0; b < count1; b++){
            for (int c = 0; c < count1; c++){
                for (int d = 0; d < count1; d++){
                    for (int i = 0; i < count2; i++){
                        Point A = points1[a], B = points1[b], C = points1[c], D = points1[d], P2 = points2[i];
                        if ((a != b) && (a != c) && (a != d) && (b != c) && (b != d) && (c != d)){
                            if (isPointInsideTriangle(A, B, C, D)){
                                CountIn1++;
                            }
                            if (isPointInsideTriangle(A, B, C, P2)){
                                CountIn2++;
                            }
                            CountsIn1.push_back(CountIn1);
                            CountsIn2.push_back(CountIn2);
                            for (int g = 0; g < CountsIn1.size(); g++){
                                if ((CountsIn1[g] == CountsIn2[g]) && (CountsIn1[g] != 0) && (CountsIn2[g] != 0) &&
                                 (a != b) && (a != c) && (a != d) && (b != c) && (b != d) && (c != d)){
                                    std::cout << "\nКоординаты вершин треугольника:\n"
                                              << points1[a].x << " " << points1[a].y << "\n"
                                              << points1[b].x << " " << points1[b].y << "\n"
                                              << points1[c].x << " " << points1[c].y << "\n"
                                              << "\nКоординаты точек первого множества внутри треугольника:\n"
                                              << points1[d].x << " " << points1[d].y << "\n"
                                              << "\nКоординаты точек второго множества внутри треугольника:\n"
                                              << points2[i].x << " " << points2[i].y << "\n";
                                    return;
                                }
                            }
                        }
                    }
                    CountIn1 = 0, CountIn2 = 0;
                }
            }
        }
    }
}
int main()
{
    setlocale(LC_ALL, "");
    std::cout << "\x1B[2J\x1B[H";
    std::vector<Point> points1;
    std::vector<Point> points2;
    std::cout << "Введите количество точек первого множества: ";
    int count1;
    std::cin >> count1;
    inputPoints(points1, count1);
    std::cout << "Введите количество точек второго множества: ";
    int count2;
    std::cin >> count2;
    inputPoints(points2, count2);
    iterateTriangles(points1, points2, count1, count2);
    return 0;
}