#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Circle {
	double x;
	double y;
	double radius;
	char label;

	Circle(double x_, double y_, double radius_, char label_) 
	{
		x = x_;
		y = y_;
		radius = radius_;
		label = label_;
	}

	// 3.2 Найти расстояние от центра окружности до (0, 0)
	double range_from_center() 
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	// 4.2 Найти расстояние между двумя окружностями
	double range_between_centers(const Circle& circ)
	{
		return sqrt(pow(abs(x - circ.x), 2) + pow(abs(y - circ.y), 2));
	}

	// 5.2 Найти расстояние от окружности до оси X
	double range_to_x()
	{
		return max(abs(y) - radius, (double)0);
	}

	// 6.2 Найти расстояние от окружности до (0, 0)
	double range_from_circle()
	{
		return max(sqrt(pow(x, 2) + pow(y, 2)) - radius, (double)0);
	}

	// 7.2 Проверка на возможность вписать данную окружность в полученную через аргумент
	bool is_inscribed(const Circle& circ)
	{
		return radius < circ.radius;
	}

	// 8.2 Проверка на пересечение двух окружностей
	bool is_intersect(const Circle& circ)
	{
		double dist = range_between_centers(circ);
		
		return (dist <= radius + circ.radius && radius + dist >= circ.radius && circ.radius + dist >= radius);
	}

	void print()
	{
		cout << label << ":\tx = " << x << "\ty = " << y << "\tradius = " << radius << "\n";
	}
};

// 1. Отразить все окружности относительно оси Y
void mirror_y(vector <Circle>& ar)
{
	unsigned int size = ar.size();
	for (unsigned int i = 0; i < size; i++) {
		ar.push_back({ -ar[i].x, ar[i].y, ar[i].radius, ar[i].label });
	}
}

// 2. Отразить все окружности из нижней полуплоскости в верхнюю
void half_mirror_x(vector <Circle>& ar)
{
	unsigned int size = ar.size();
	for (unsigned int i = 0; i < size; i++) {
		if (ar[i].y < 0) {
			ar.push_back({ ar[i].x, -ar[i].y, ar[i].radius, ar[i].label });
		}
	}
}

// 3.1 Найти расстояние от центра окружности до (0, 0)
double range_from_center(const Circle& circ)
{
	return sqrt(pow(circ.x, 2) + pow(circ.y, 2));
}

// 4.1 Найти расстояние между центрами двух окружностей
double range_between_centers(const Circle& a, const Circle& b)
{
	return sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
}

// 5.1 Найти расстояние от окружности до оси X
double range_to_x(const Circle& circ)
{
	return max(abs(circ.y) - circ.radius, (double)0);
}

// 6.1 Найти расстояние от окружности до (0, 0)
double range_from_circle(const Circle& circ)
{
	return max(sqrt(pow(circ.x, 2) + pow(circ.y, 2)) - circ.radius, (double)0);
}

// 7.1 Проверка на возможность вписать первую окружность во вторую
bool is_inscribed(const Circle& a, const Circle& b)
{
	return a.radius < b.radius;
}

// 8.1 Проверка на пересечение двух окружностей
bool is_intersect(const Circle& a, const Circle& b)
{
	double dist = range_between_centers(a, b);

	return (dist <= a.radius + b.radius && a.radius + dist >= b.radius && b.radius + dist >= a.radius);
}

int main()
{
	vector <Circle> ar;
	ar.push_back({ -10, 5, 3, 'A' });
	ar.push_back({ 3, 6, 2, 'B' });
	ar.push_back({ 8, -8, 4, 'C' });
	ar.push_back({ -5, 5, 2, 'D' });
	ar.push_back({ -5, 5, 2.01, 'E' });
	ar.push_back({ -10, 5, 3, 'F' });
	ar.push_back({ -10, 5, 2.9, 'G' });
	ar.push_back({ -5, 5, 1.99, 'H' });
	ar.push_back({ -10, 5, 3.01, 'I' });

	// 1. Отразить все окружности относительно оси Y
	mirror_y(ar);

	// 2. Отразить все окружности из нижней полуплоскости в верхнюю
	half_mirror_x(ar);

	// 3.1 Найти расстояние от центра окружности до (0, 0), реализация через функцию
	cout << range_from_center(ar[0]) << "\t";

	// 3.2 Найти расстояние от центра окружности до (0, 0), реализация через метод
	cout << ar[0].range_from_center() << "\n";

	// 4.1 Найти расстояние между центрами двух окружностей, реализация через функцию
	cout << range_between_centers(ar[0], ar[1]) << "\t";

	// 4.2 Найти расстояние между двумя окружностями, реализация через метод
	cout << ar[0].range_between_centers(ar[1]) << "\n";

	// 5.1 Найти расстояние от окружности до оси X, реализация через функцию:
	cout << range_to_x(ar[0]) << "\t";

	// 5.2 Найти расстояние от окружности до оси X, реализация через метод
	cout << ar[0].range_to_x() << "\n";

	// 6.1 Найти расстояние от окружности до (0, 0), реализация через функцию
	cout << range_from_circle(ar[0]) << "\t";

	// 6.2 Найти расстояние от окружности до (0, 0), реализация через метод
	cout << ar[0].range_from_circle() << "\n";

	// 7.1 Проверка на возможность вписать первую окружность во вторую, реализация через функцию
	cout << is_inscribed(ar[0], ar[1]) << "\t";

	// 7.2 Проверка на возможность вписать данную окружность в полученную через аргумент, реализация через метод
	cout << ar[0].is_inscribed(ar[1]) << "\n";

	// 8.1 Проверка на пересечение двух окружностей, реализация через функцию
	cout << is_intersect(ar[0], ar[1]) << "\t";

	// 8.2 Проверка на пересечение двух окружностей, реализация через метод
	cout << ar[0].is_intersect(ar[1]) << "\n";

	// Дополнительныет тесты для пункта 8
	ar[0].print();
	ar[3].print();
	cout << ar[0].is_intersect(ar[3]) << "\n";
	ar[4].print();
	cout << ar[0].is_intersect(ar[4]) << "\n";
	ar[7].print();
	cout << ar[0].is_intersect(ar[7]) << "\n";
	ar[5].print();
	cout << ar[0].is_intersect(ar[5]) << "\n";
	ar[6].print();
	cout << ar[0].is_intersect(ar[6]) << "\n";
	ar[8].print();
	cout << ar[0].is_intersect(ar[8]) << "\n";

	return 0;
}
