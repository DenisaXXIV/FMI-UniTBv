#include "Fractie.h"
#include <iostream>

Fractie::Fractie(int numarator, int numitor)
{
	this->numarator = numarator;
	this->numitor = numitor;
}

Fractie Fractie::operator+(Fractie F)
{
	Fractie SUM(0,0);
	SUM.numarator = numarator + F.numarator;
	SUM.numitor = numitor;
	return SUM;
}

Fractie Fractie::operator*(Fractie F)
{
	Fractie Produs(1, 1);

	Produs.numarator = numarator * F.numarator;
	Produs.numitor = numitor * F.numitor;

	return Produs;
}

std::ostream& operator<<(std::ostream& out, Fractie F)
{
	out << F.numarator << "\n";
	out << "_\n";
	out<< F.numitor;

	return out;
}

std::istream& operator>>(std::istream& in, Fractie& F)
{
	in >> F.numarator >> F.numitor;

	return in;
}