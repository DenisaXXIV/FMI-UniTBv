#include <iostream>
#include <algorithm>
#include "Polygon.h"
#include "Point.h"

bool comparePerimeter(Polygon* p1, Polygon* p2) {
    return p1->perimeter() < p2->perimeter();
}

int main()
{
    int numPolygons;

    std::cout << "Enter the number of polygons: ";
    std::cin >> numPolygons;

    Polygon** polygons = new Polygon * [numPolygons];

    for (int i = 0; i < numPolygons; ++i) {
        int numVertices;
        std::cout << "Enter the number of vertices for polygon " << i + 1 << ": ";
        std::cin >> numVertices;
        polygons[i] = new Polygon(numVertices);
        polygons[i]->read();
    }

    std::cout << "\nPolygons:\n";
    for (int i = 0; i < numPolygons; ++i) {
        std::cout << "Polygon " << i + 1 << ":\n";
        polygons[i]->print();
        std::cout << "Perimeter: " << polygons[i]->perimeter() << "\n\n";
    }

    float x, y;
    std::cout << "Enter the coordinates of a point to check if it's a vertex (x y): ";
    std::cin >> x >> y;
    Point p(x, y);

    std::cout << "\nPolygons for which the point is a vertex:\n";
    for (int i = 0; i < numPolygons; ++i) {
        if (polygons[i]->isVertex(p)) {
            std::cout << "Polygon " << i + 1 << ":\n";
            polygons[i]->print();
        }
    }

    std::sort(polygons, polygons + numPolygons, comparePerimeter);

    std::cout << "\nPolygons sorted by perimeter:\n";
    for (int i = 0; i < numPolygons; ++i) {
        std::cout << "Polygon " << i + 1 << ":\n";
        polygons[i]->print();
        std::cout << "Perimeter: " << polygons[i]->perimeter() << "\n\n";
    }

    for (int i = 0; i < numPolygons; ++i) {
        delete polygons[i];
    }
    delete[] polygons;

    return 0;
}
