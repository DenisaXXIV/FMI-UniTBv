#include <iostream>

int cmmdc(int numar1, int numar2)
{
	int rest;
	while (numar2 != 0)
	{
		rest = numar1 % numar2;
		numar1 = numar2;
		numar2 = rest;
	}
	return numar1;
}

struct NrRationale
{
	int numitor, numarator;
	void Citire()
	{
		std::cin >> numarator >> numitor;
	}
	void Afisare()
	{
		if (numitor != 1)
		{
			std::cout << numarator << "/" << numitor;
		}
		else
		{
			std::cout << numarator;
		}
	}
	void Simplificare()
	{
		int indice;
		indice = cmmdc(numarator, numitor);
		numarator /= indice;
		numitor /= indice;
	}
	void Adunare()
	{

	}
};

int main()
{
	NrRationale p;
	std::cin >> p.numarator>>p.numitor;
	p.Simplificare();
	p.Afisare();
}