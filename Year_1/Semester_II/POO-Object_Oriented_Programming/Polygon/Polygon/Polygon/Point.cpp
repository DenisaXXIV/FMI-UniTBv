#include "Point.h"
#include <iostream>

Point::Point() : x(0), y(0) {}

Point::Point(float xCoord, float yCoord) : x(xCoord), y(yCoord) {}

void Point::read() {
    std::cout << "x=";
    std::cin >> x;
    std::cout << "y=";
    std::cin >> y;
}

void Point::print() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

float Point::distance(Point p) {
    return std::sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

bool Point::operator==(const Point& p) {
    return x == p.x && y == p.y;
}

float Point::getX() {
    return x;
}

float Point::getY() {
    return y;
}
