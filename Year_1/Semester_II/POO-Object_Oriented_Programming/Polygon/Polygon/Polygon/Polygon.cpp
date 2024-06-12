#include "Polygon.h"
#include <iostream>

Polygon::Polygon(int numVertices) : no(numVertices) {
    vertices = new Point[no];
}

void Polygon::read() {
    for (int i = 0; i < no; ++i) {
        std::cout << "Enter vertex " << i + 1 << ": ";
        vertices[i].read();
    }
}

void Polygon::print() {
    for (int i = 0; i < no; ++i) {
        vertices[i].print();
    }
}

double Polygon::perimeter() {
    double perimeter = 0.0;
    for (int i = 0; i < no; ++i) {
        perimeter += vertices[i].distance(vertices[(i + 1) % no]);
    }
    return perimeter;
}

bool Polygon::isVertex(Point p) {
    for (int i = 0; i < no; ++i) {
        if (vertices[i] == p) {
            return true;
        }
    }
    return false;
}

double Polygon::area() {
    double area = 0.0;
    for (int i = 0; i < no; ++i) {
        int j = (i + 1) % no;
        area += vertices[i].getX() * vertices[j].getY();
        area -= vertices[j].getX() * vertices[i].getY();
    }
    return std::abs(area) / 2.0;
}

Polygon::~Polygon() {
    delete[] vertices;
}