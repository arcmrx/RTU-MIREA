#include <iostream>
#include <cmath>
using namespace std;

double a, b, c, h, r, p, S;
double rect(double a, double b)
{
	if (a <= 0 or b <= 0)
	{
		return -1;
	}
	return a * b;
}

double trin(double a, double b, double c)
{
	if (a <= 0 or b <= 0 or c <= 0 or a + b <= c or a + c <= b or b + c <= a)
	{
		return -1;
	}
	p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double circle(double r)
{
	if (r <= 0)
	{
		return -1;
	}
	return M_PI * pow(r, 2);
}

int main()
{
	cout << "\x1B[2J\x1B[H";
	setlocale(LC_ALL, "ru");
	int select;
	cout << "1 (прямоугольник) / 2 (треугольник) / 3 (круг): ";
	if (!(cin >> select))
	{
		printf("\e[1;1H\e[2J");
		cout << "Некорректные данные";
		return 0;
	}
	if (select < 1 or select > 3)
	{
		printf("\e[1;1H\e[2J");
		cout << "Некорректные данные";
		return 0;
	}
	switch (select)
	{
	case 1:
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
		S = rect(a, b);
		if (S == -1)
		{
			printf("\e[1;1H\e[2J");
			cout << "Некорректные данные";
			return 0;
		}
		cout << "S прямоугольникa = " << S;
		return (0);
	case 2:
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
		cout << "c = ";
		cin >> c;
		S = trin(a, b, c);
		if (S == -1)
		{
			printf("\e[1;1H\e[2J");
			cout << "Некорректные данные";
			return 0;
		}
		cout << "S треугольникa = " << S << endl;
		return (0);
	case 3:
		cout << "r = ";
		cin >> r;
		S = circle(r);
		if (S == -1)
		{
			printf("\e[1;1H\e[2J");
			cout << "Некорректные данные";
			return 0;
		}
		cout << "S кругa = " << S << endl;
		return (0);
	}
}