#include <iostream>

class Fractie
{
public:
	int numarator;
	int numitor;
	Fractie(int, int);

	Fractie operator+(Fractie);

	Fractie operator*(Fractie);

	friend std::ostream& operator <<(std::ostream& out, Fractie F);

	friend std::istream& operator>>(std::istream& in, Fractie& F);
};
