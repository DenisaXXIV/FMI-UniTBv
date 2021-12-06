#include <iostream>

class Vect
{
private:
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

	double operator*(Vect vector)
	{
		return cx * vector.cx + cy * vector.cy + cz * vector.cz;
	}

	

};

Vect operator*(Vect vector, double scalar)
{
	Vect produs;
	produs.setx(scalar*vector.getx());
	produs.sety(scalar * vector.gety());
	produs.setz(scalar * vector.getz());
	return produs;
}

int main()
{
	Vect v, u, S, D, Pscal;
	double P;
	std::cout << "Vector 1:";
	v.Initializare(0, 1, 2);
	v.Afisare();
	std::cout << std::endl;
	std::cout << "Vetor 2:";
	u.Initializare(4, 5, 6);
	u.Afisare();
	std::cout << std::endl;

	S = v + u;
	std::cout << "v+u=";
	S.Afisare();
	std::cout << std::endl;

	D = u - v;
	std::cout << "u-v=";
	D.Afisare();
	std::cout << std::endl;

	std::cout << "v*u=";
	P = v * u;
	std::cout << P;
	std::cout<< std::endl;

	std::cout << "v*5=";
	Pscal = v * 5;
	Pscal.Afisare();
	std::cout << std::endl;

	return 0;
}
