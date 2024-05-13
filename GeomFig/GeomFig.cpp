#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <stdexcept>

class Shape {
private:

    struct Point {
        double X;
        double Y;
        Point(double X, double Y);
        void display();
    };

    std::vector<Point> points;
    unsigned count = 0;


public:
    Shape() {}
    void addPoint(double x, double y);
    void popPoint();
    void deletePoint(int index);
    void displayPoints();
    unsigned getCount() const;
    double getArea();
    double getPerimeter();
};

Shape::Point::Point(double x, double y) {
    X = x;
    Y = y;
}

void Shape::Point::display() {
    std::cout << this->X << " " << this->Y;
}

void Shape::addPoint(double x, double y) {
    Point point(x, y);
    points.emplace_back(point);
    count++;
}

void Shape::popPoint() {
    points.pop_back();
    count--;
}

void Shape::deletePoint(int index) {
    if (points.size() > index)
        points.erase(points.begin() + index);
}

void Shape::displayPoints() {
    for (Point& p : points) {
        p.display();
        std::cout << std::endl;
    }
}

unsigned Shape::getCount() const { return count; }

double Shape::getArea() {
    if (count < 3) {
        throw std::runtime_error("Нужно минимум 3 точки!");
    }
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < count - 1; i++) {
        sum1 += points[i].X * points[i + 1].Y;
        sum2 += points[i].Y * points[i + 1].X;
    }
    sum1 += points[count - 1].X * points[0].Y;
    sum2 += points[count - 1].Y * points[0].X;

    return std::abs((sum1 - sum2) / 2);
}

double Shape::getPerimeter() {
    if (count < 3) {
        throw std::runtime_error("Нужно минимум 3 точки!");
    }
    double result = 0;

    for (int i = 0; i < count; i++) {
        result += sqrt(pow((points[i].X - points[(i + 1) % count].X), 2) + pow((points[i].Y - points[(i + 1) % count].Y), 2));
    }
    return result;
}

int main() {
    Shape someShape;
    someShape.addPoint(1, 3);
    someShape.addPoint(3, 5);
    someShape.addPoint(45, 5);

    std::cout << "Perimeter: " << someShape.getPerimeter() << std::endl;
    std::cout << "Area: " << someShape.getArea() << std::endl;

    std::vector<Shape> shapes;
    std::vector<std::unique_ptr<Shape>> shapePtrs;

    shapePtrs.push_back(std::make_unique<Shape>(Shape()));
    shapePtrs.push_back(std::make_unique<Shape>(Shape()));
    shapePtrs.push_back(std::make_unique<Shape>(Shape()));
    shapePtrs.push_back(std::make_unique<Shape>(Shape()));

    shapePtrs[1]->addPoint(2, 4);
    shapePtrs[1]->addPoint(3, 8);
    shapePtrs[1]->addPoint(4, 9);

    std::cout << "Area from pointer: " << shapePtrs[1]->getArea() << std::endl;

    return 0;
}