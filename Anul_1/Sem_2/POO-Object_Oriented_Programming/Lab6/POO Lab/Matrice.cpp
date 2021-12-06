#include "Matrice.h"
#include <iostream>

int** Matrice::alocare(int nrLinii, int nrColoane)
{
	int** mat = new int* [nrLinii];
	for (int contor = 0; contor < nrLinii; contor++)
	{
		mat[contor] = new int[nrColoane] {};
	}
	return mat;
}

Matrice::Matrice(int dimensiune) :Matrice(dimensiune, dimensiune)
{
	std::cout << "Apel al primului constructor" << std::endl;;
}

Matrice::Matrice(int nr_linii, int nr_coloane)
{
	this->nrColoane = nr_coloane;
	this->nrLinii = nr_linii;
	elem = alocare(nr_linii, nr_coloane);
	std::cout << "Apel al constructorului cu 2 parametrii" << std::endl;
}


Matrice::Matrice()
{
	nrLinii = 0;
	nrColoane = 0;
	elem = NULL;
}

std::ostream& operator << (std::ostream& out, Matrice m)
{
	for (int contor_linii = 0; contor_linii < m.getNrLinii(); contor_linii++)
	{
		for (int contor_coloane = 0; contor_coloane < m.getNrColoane(); contor_coloane++)
		{
			out << m.elem[contor_linii][contor_coloane] << " ";
		}
		out << std::endl;
	}
	return out;
}

std::istream& operator >> (std::istream& in, Matrice& m)
{
	for (int contor_linii = 0; contor_linii < m.getNrLinii(); contor_linii++)
	{
		for (int contor_coloane = 0; contor_coloane < m.getNrColoane(); contor_coloane++)
		{
			in >> m.elem[contor_linii][contor_coloane];
		}
	}
	return in;
}

int Matrice::getNrLinii()
{
	return nrLinii;
}

int Matrice::getNrColoane()
{
	return nrColoane;
}

int** Matrice::getElemente()
{
	int** copie = alocare(nrLinii, nrColoane);
	for (int contor_linie = 0; contor_linie < nrLinii; contor_linie++)
	{
		for (int contor_coloane = 0; contor_coloane < nrColoane; contor_coloane++)
		{
			copie[contor_linie][contor_coloane] = elem[contor_linie][contor_coloane];
		}
	}
	return copie;
}


Matrice::~Matrice()
{
	for (int counter = 0; counter < nrLinii; counter++)
	{
		delete[] elem[counter];
	}
	delete[] elem;
	std::cout << "S-a apelat destructorul";
}

Matrice::Matrice(const Matrice& m)
{
	nrLinii = m.nrLinii;
	nrColoane = m.nrColoane;
	elem = alocare(nrLinii, nrColoane);
	for (int i = 0; i < nrLinii; i++)
	{
		for (int j = 0; j < nrColoane; j++)
		{
			elem[i][j] = m.elem[i][j];
		}
	}
	std::cout << "Apel al constructorului de copiere" << std::endl;
}

Matrice& Matrice:: operator =(const Matrice& m)
{
	if (this == &m)
	{
		return *this; //nu se face suprascrierea
	}
	if (nrLinii != m.nrLinii || nrColoane != m.nrColoane)
	{
		for (int i = 0; i < nrLinii; i++)   /// sau this->Matrice()
		{
			delete[] elem[i];
			delete[] elem;
			elem = alocare(m.nrLinii, m.nrColoane);
			nrLinii = m.nrLinii;
			nrColoane = m.nrColoane;
		}
		for (int i = 0; i < nrLinii; i++)
		{
			for (int j = 0; j < nrColoane; j++)
			{
				elem[i][j] = m.elem[i][j];
			}
		}
		return *this;
	}
}

int Matrice :: getValoare(int linie, int coloana)
{
	if (linie < 0 or linie >= nrLinii or coloana < 0 or coloana >= nrColoane)
		throw std::out_of_range("indici in afara listelor");
	return elem[linie][coloana];
}

int* Matrice::operator[](int linie)
{
	if (linie < 0 or linie >= nrLinii)
	{
		throw std::out_of_range("Indice in afara limitelor");
		
	}
	return elem[linie];
}