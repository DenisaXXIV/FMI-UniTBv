#include <iostream>

class Vect
{
	double cx, cy, cz;  //atribute
public:
	void Initializare(double x, double y, double z)
	{
		cx = x;
		cy = y;
		cz = z;
	}

	void Afisare()
	{
		std::cout << "(" << cx << "," << cy << "," << cz << ")" << std::endl;
	}

	void setx(double x)
	{
		cx = x;
	}

	void sety(double y)
	{
		cy = y;
	}
	void setz(double z)
	{
		cz = z;
	}
	double getx()
	{
		return cx;
	}
	double gety()
	{
		return cy;
	}
	double getz()
	{
		return cz;
	}

	Vect operator+(Vect vector)
	{
		Vect suma;
		suma.cx = cx + vector.cx;
		suma.cy = cy + vector.cy;
		suma.cz = cz + vector.cz;
		return suma;
	}

	Vect operator-(Vect vector)
	{
		Vect diferenta;
		diferenta.cx = cx - vector.cx;
		diferenta.cy = cy - vector.cy;
		diferenta.cz = cz - vector.cz;
		return diferenta;
	}

	Vect operator*(Vect vector)
	{
		Vect;
	}
};

int main()
{
	Vect v, u;
	v.Initializare(0, 1, 2);
	u.Initializare(4, 5, 6);

	v.operator+(u);

	v.Afisare();
}
