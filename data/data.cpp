#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Конструктор с параметрами
    Date(int dayVal, int monthVal, int yearVal) {
        day = dayVal;
        month = monthVal;
        year = yearVal;
    }

    // Геттеры и сеттеры
    int getDay() const {
        return day;
    }

    void setDay(int dayVal) {
        day = dayVal;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int monthVal) {
        month = monthVal;
    }

    int getYear() const {
        return year;
    }

    void setYear(int yearVal) {
        year = yearVal;
    }

    // Вычисление количества дней от начала года
    int toDays() const {
        int days = day;
        for (int i = 1; i < month; i++) {
            if (i == 2) {
                if (isLeapYear(year)) {
                    days += 29;
                }
                else {
                    days += 28;
                }
            }
            else if (i == 4 || i == 6 || i == 9 || i == 11) {
                days += 30;
            }
            else {
                days += 31;
            }
        }
        return days;
    }

    // Вычисление количества месяцев от начала года
    int toMonths() const {
        return month;
    }

    // Вычисление количества лет
    int toYears() const {
        return year;
    }

    // Сложение дат
    Date operator+(const Date& other) const {
        int newDay = day + other.day;
        int newMonth = month + other.month;
        int newYear = year + other.year;

        newMonth += newDay / 31;
        newDay %= 31;
        newYear += newMonth / 12;
        newMonth %= 12;

        return Date(newDay, newMonth, newYear);
    }

    // Вычитание дат
    Date operator-(const Date& other) const {
        int newDay = day - other.day;
        int newMonth = month - other.month;
        int newYear = year - other.year;

        if (newDay < 0) {
            newDay += 31;
            newMonth--;
        }
        if (newMonth < 0) {
            newMonth += 12;
            newYear--;
        }
        if (newYear < 0) {
            newYear--;
        }

        return Date(newDay, newMonth, newYear);
    }

    // Добавление дней, месяцев и лет к текущей дате
    Date addDays(int days) {
        int newDay = day + days;
        int newMonth = month;
        int newYear = year;

        newMonth += newDay / 31;
        newDay %= 31;
        newYear += newMonth / 12;
        newMonth %= 12;

        return Date(newDay, newMonth, newYear);
    }

    // Преобразование даты в строковый формат
    std::string toString() const {
        return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
    }

    // Проверка на равенство дат
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    // Проверка на високосный год
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int main() {
        setlocale(LC_ALL, "Rus");

        int day, month, year;

        std::cout << "Введите день: ";
        std::cin >> day;

        std::cout << "Введите месяц: ";
        std::cin >> month;

        std::cout << "Введите год: ";
        std::cin >> year;

        Date date1(day, month, year);

        std::cout << "Дата 1: " << date1.toString() << std::endl;

        std::cout << "Введите день для второй даты: ";
        std::cin >> day;

        std::cout << "Введите месяц для второй даты: ";
        std::cin >> month;

        std::cout << "Введите год для второй даты: ";
        std::cin >> year;

        Date date2(day, month, year);

        std::cout << "Дата 2: " << date2.toString() << std::endl;
        std::cout << "Дата 1: " << date1.toString() << std::endl;
        std::cout << "Дата 2: " << date2.toString() << std::endl;

        Date sum = date1 + date2;
        std::cout << "Дата 1 + Дата 2 = " << sum.toString() << std::endl;

        Date diff = date1 - date2;
        std::cout << "Дата 1 - Дата 2 = " << diff.toString() << std::endl;

        if (date1 == date2) {
            std::cout << "Дата 1 и Дата 2 равны" << std::endl;
        }
        else {
            std::cout << "Дата 1 и Дата 2 не равны" << std::endl;
        }

        return 0;
}