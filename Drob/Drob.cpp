#include <iostream>

using namespace std;

// Класс для представления обыкновенной дроби
class Fraction {
public:
	int numerator; // числитель
	int denominator; // знаменатель

	// Метод для сложения двух дробей
	Fraction addFractions(Fraction b) {
		Fraction result;
		result.numerator = this->numerator * b.denominator + b.numerator * this->denominator;
		result.denominator = this->denominator * b.denominator;
		return result;
	}

	// Метод для вычитания двух дробей
	Fraction subtractFractions(Fraction b) {
		Fraction result;
		result.numerator = this->numerator * b.denominator - b.numerator * this->denominator;
		result.denominator = this->denominator * b.denominator;
		return result;
	}

	// Метод для умножения двух дробей
	Fraction multiplyFractions(Fraction b) {
		Fraction result;
		result.numerator = this->numerator * b.numerator;
		result.denominator = this->denominator * b.denominator;
		return result;
	}

	// Метод для деления двух дробей
	Fraction divideFractions(Fraction b) {
		Fraction result;
		result.numerator = this->numerator * b.denominator;
		result.denominator = this->denominator * b.numerator;
		return result;
	}

	// Метод для сравнения двух дробей
	bool compareFractions(Fraction b) {
		return (this->numerator * b.denominator == b.numerator * this->denominator);
	}
};

int main() {
	setlocale(LC_ALL, "Rus");
	Fraction a, b;

	// Ввод значений для первой дроби
	cout << "Введите числитель первой дроби: ";
	cin >> a.numerator;
	cout << "Введите знаменатель первой дроби: ";
	cin >> a.denominator;

	// Ввод значений для второй дроби
	cout << "Введите числитель второй дроби: ";
	cin >> b.numerator;
	cout << "Введите знаменатель второй дроби: ";
	cin >> b.denominator;

	// Сложение дробей
	Fraction sum = a.addFractions(b);
	cout << "Сумма дробей: " << sum.numerator << "/" << sum.denominator << endl;

	// Вычитание дробей
	Fraction diff = a.subtractFractions(b);
	cout << "Разность дробей: " << diff.numerator << "/" << diff.denominator << endl;

	// Умножение дробей
	Fraction product = a.multiplyFractions(b);
	cout << "Произведение дробей: " << product.numerator << "/" << product.denominator << endl;

	// Деление дробей
	Fraction quotient = a.divideFractions(b);
	cout << "Частное дробей: " << quotient.numerator << "/" << quotient.denominator << endl;

	// Сравнение дробей
	if (a.compareFractions(b)) {
		cout << "Дроби равны" << endl;
	}
	else {
		cout << "Дроби не равны" << endl;
	}

	return 0;
}