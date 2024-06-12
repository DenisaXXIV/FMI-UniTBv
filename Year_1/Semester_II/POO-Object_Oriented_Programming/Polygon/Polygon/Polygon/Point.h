#pragma once
class Point
{
	float x, y;
public:
	Point();
	Point(float,float);

	void read();
	void print();

	float distance(Point p);

	bool operator==(const Point& p);

	float getX();
	float getY();
};

