#include <iostream>

using namespace std;

// Структура для представления обыкновенной дроби
struct Fraction {
    int numerator; // числитель
    int denominator; // знаменатель
};

// Функция для сложения двух дробей
Fraction addFractions(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}

// Функция для вычитания двух дробей
Fraction subtractFractions(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}

// Функция для умножения двух дробей
Fraction multiplyFractions(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return result;
}

// Функция для деления двух дробей
Fraction divideFractions(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    return result;
}

// Функция для сравнения двух дробей
bool compareFractions(Fraction a, Fraction b) {
    return (a.numerator * b.denominator == b.numerator * a.denominator);
}

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
    Fraction sum = addFractions(a, b);
    cout << "Сумма дробей: " << sum.numerator << "/" << sum.denominator << endl;

    // Вычитание дробей
    Fraction diff = subtractFractions(a, b);
    cout << "Разность дробей: " << diff.numerator << "/" << diff.denominator << endl;

    // Умножение дробей
    Fraction product = multiplyFractions(a, b);
    cout << "Произведение дробей: " << product.numerator << "/" << product.denominator << endl;

    // Деление дробей
    Fraction quotient = divideFractions(a, b);
    cout << "Частное дробей: " << quotient.numerator << "/" << quotient.denominator << endl;

    // Сравнение дробей
    if (compareFractions(a, b)) {
        cout << "Дроби равны" << endl;
    }
    else {
        cout << "Дроби не равны" << endl;
    }

    return 0;
}