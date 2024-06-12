#pragma once
#include "Point.h"

class Polygon
{
	int no; 
	Point* vertices;
public:
	Polygon(int);
	~Polygon();

	void read();
	void print();

	double area();
	double perimeter();
	bool isVertex(Point);
};

