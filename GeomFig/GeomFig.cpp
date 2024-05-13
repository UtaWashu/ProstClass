#include <iostream>
#include <cmath>

using namespace std;

// Структура для хранения координат точки
struct Point {
	int x;
	int y;
};

// Функция для вычисления расстояния между двумя точками
double distance(Point p1, Point p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
	setlocale(LC_ALL, "Rus");
	// Ввод координат точек
	Point A, B, C;
	cout << "Введите координаты точки A (x y): ";
	cin >> A.x >> A.y;
	cout << "Введите координаты точки B (x y): ";
	cin >> B.x >> B.y;
	cout << "Введите координаты точки C (x y): ";
	cin >> C.x >> C.y;

	// Вычисление сторон треугольника
	double AB = distance(A, B);
	double BC = distance(B, C);
	double AC = distance(A, C);

	// Вычисление периметра
	double perimeter = AB + BC + AC;

	// Вычисление полупериметра
	double semiperimeter = perimeter / 2;

	// Вычисление площади треугольника по формуле Герона
	double area = sqrt(semiperimeter * (semiperimeter - AB) * (semiperimeter - BC) * (semiperimeter - AC));

	// Вывод результатов
	cout << "Периметр треугольника: " << perimeter << endl;
	cout << "Площадь треугольника: " << area << endl;

	return 0;
}