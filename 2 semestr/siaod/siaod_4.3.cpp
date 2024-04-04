#include <iostream>
#include <vector>
#include <cmath>

struct Point
{
    double x;
    double y;
};

void fillPointsVector(std::vector<Point> &points, int size)
{
    points.resize(size);
    std::cout << "Enter points:\n";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> points[i].x >> points[i].y;
    }
}

bool isBalancedTriangle(const Point &p1, const Point &p2, const Point &p3, const std::vector<Point> &set1, const std::vector<Point> &set2)
{
    int set1Count = 0, set2Count = 0;
    for (const Point &point : set1)
    {
        double area = 0.5 * ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
        double area1 = 0.5 * ((point.x - p1.x) * (p2.y - p1.y) - (p2.x - p1.x) * (point.y - p1.y));
        double area2 = 0.5 * ((p2.x - p1.x) * (point.y - p1.y) - (point.x - p1.x) * (p2.y - p1.y));
        double area3 = 0.5 * ((point.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (point.y - p1.y));
        if ((area1 >= 0 && area2 >= 0 && area3 >= 0) || (area1 <= 0 && area2 <= 0 && area3 <= 0))
        {
            ++set1Count;
        }
    }
    for (const Point &point : set2)
    {
        double area = 0.5 * ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
        double area1 = 0.5 * ((point.x - p1.x) * (p2.y - p1.y) - (p2.x - p1.x) * (point.y - p1.y));
        double area2 = 0.5 * ((p2.x - p1.x) * (point.y - p1.y) - (point.x - p1.x) * (p2.y - p1.y));
        double area3 = 0.5 * ((point.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (point.y - p1.y));
        if ((area1 >= 0 && area2 >= 0 && area3 >= 0) || (area1 <= 0 && area2 <= 0 && area3 <= 0))
        {
            ++set2Count;
        }
    }
    return set1Count == set2Count;
}

void findBalancedTriangle(const std::vector<Point> &points1, const std::vector<Point> &points2)
{
    int n = points1.size();
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                if (isBalancedTriangle(points1[i], points1[j], points1[k], points1, points2))
                {
                    std::cout << "Found balanced triangle:\n";
                    std::cout << "(" << points1[i].x << ", " << points1[i].y << "), ";
                    std::cout << "(" << points1[j].x << ", " << points1[j].y << "), ";
                    std::cout << "(" << points1[k].x << ", " << points1[k].y << ")\n";
                    return;
                }
            }
        }
    }
    std::cout << "No balanced triangle found.\n";
}

int main()
{
    int size1, size2;
    std::cout << "Enter the number of points in the first set: ";
    std::cin >> size1;
    std::cout << "Enter the number of points in the second set: ";
    std::cin >> size2;

    std::vector<Point> points1, points2;
    fillPointsVector(points1, size1);
    fillPointsVector(points2, size2);

    findBalancedTriangle(points1, points2);

    return 0;
}
