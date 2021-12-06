#include <iostream>

int Cmmdc(int numar1, int numar2)
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

int Cmmmc(int numar1, int numar2)
{
	int aux1, aux2;
	aux1 = numar1;
	aux2 = numar2;
	while (aux1 != aux2)
	{
		if (aux1 > aux2)
		{
			aux1 -= aux2;
		}
		else
		{
			aux2 -= aux1;
		}
	}
	return (numar1*numar2)/aux1;
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
		std::cout << " ";
	}
	void Simplificare()
	{
		int indice;
		indice = Cmmdc(numarator, numitor);
		numarator /= indice;
		numitor /= indice;
	}
	void Adunare(NrRationale Fractie2, NrRationale &Rezultat)
	{
		if (numitor == Fractie2.numitor)
		{
			Rezultat.numarator = numarator + Fractie2.numarator;
			Rezultat.numitor = numitor;
		}
		else
		{
			int cmmmc = Cmmmc(numitor, Fractie2.numitor);
			int aux = cmmmc / numitor;
			numarator *= aux;
			aux = cmmmc / Fractie2.numitor;
			Fractie2.numarator *= aux;
			Rezultat.numarator = numarator + Fractie2.numarator;
			Rezultat.numitor = cmmmc;
		}
	}
	void Scadere(NrRationale Fractie2, NrRationale &Rezultat)
	{
		if (numitor == Fractie2.numitor)
		{
			Rezultat.numarator = numarator - Fractie2.numarator;
			Rezultat.numitor = numitor;
		}
		else
		{
			int cmmmc = Cmmmc(numitor, Fractie2.numitor);
			int aux = cmmmc / numitor;
			numarator *= aux;
			aux = cmmmc / Fractie2.numitor;
			Fractie2.numarator *= aux;
			Rezultat.numarator = numarator - Fractie2.numarator;
			Rezultat.numitor = cmmmc;
		}
	}

	void Impartire(NrRationale Fractie2, NrRationale &Rezultat)
	{
		Rezultat.numarator = numarator * Fractie2.numitor;
		Rezultat.numitor = numitor * Fractie2.numarator;
	}

	void Inmultire(NrRationale Fractie2, NrRationale &Rezultat)
	{
		Rezultat.numarator = numarator * Fractie2.numarator;
		Rezultat.numitor = numitor * Fractie2.numitor;
	}
};

int main()
{
	NrRationale s,p,q,r;
	s.Citire();
	p.Citire();
	q.Citire();
	s.Simplificare();
	s.Afisare();
	p.Adunare(q, r);
	r.Afisare();
	p.Scadere(q, r);
	r.Afisare();
	p.Inmultire(q, r);
	r.Afisare();
	p.Impartire(q,r);
	r.Afisare();
}