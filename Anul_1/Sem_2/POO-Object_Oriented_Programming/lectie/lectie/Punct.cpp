#include "Punct.h"

void Punct::MijlocAB(Punct* nou)
{
	std::cout << "M(" << (x + nou->getX()) / 2 << ";" << (y + nou->getY()) / 2<<")";
}

int Punct::getX()
{
	return x;
}

int Punct::getY()
{
	return y;
}

void Punct::setX(int x)
{
	this->x = x;
}

void Punct::setY(int y)
{
	this->y = y;
}

Punct::Punct(int x, int y)
{
	this->x = x;
	this->y = y;
}

Punct::~Punct()
{

}