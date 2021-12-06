#include <iostream>
#pragma once
class Punct
{
private:
	int x;
	int y;
public:
	Punct(int, int);

	void MijlocAB(Punct*);
	int getX();
	int getY();
	void setX(int);
	void setY(int);

	~Punct();
};

