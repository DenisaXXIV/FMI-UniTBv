#include "Matrice.h"
#include <iostream>

using namespace std;

int** Matrice::alocare(int nrLinii, int nrColoane)
{
	int** mat = new int* [nrLinii];
	for (int i = 0; i < nrLinii; i++)
	{
		mat[i] = new int[nrColoane] {0};
	}
	return mat;
}

Matrice::Matrice(int dim) :Matrice(dim, dim)
{
	cout << "Apel al constructorului cu un parametru";
}

Matrice::Matrice(int nrLinii,int nrColoane)
{
	this->nrLinii = nrLinii;
	this->nrColoane = nrColoane;
	elem = alocare(nrLinii, nrColoane);
	cout << "Apel al constructorului cu 2 parametri";
}

Matrice::Matrice()
{
	this->nrLinii = 0;
	this->nrColoane = 0;
	elem = nullptr;
	cout << "Apel al constructorului fara parametri";
}

ostream& operator<<(ostream& out, Matrice m)
{
	out << "\n";
	out << "Matricea este: "<<"\n";
	for (int i = 0; i < m.nrLinii; i++)
	{
		for (int j = 0; j < m.nrColoane; j++)
			out << m.elem[i][j] << " ";
		out << "\n";
	}
	return out;
}

istream& operator>>(istream& in, Matrice& m)
{
	for (int i = 0; i < m.nrLinii; i++)
	{
		for (int j = 0; j < m.nrColoane; j++)
			in >> m.elem[i][j];
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

int Matrice::getElemente(int linie, int coloana)
{
	return elem[linie][coloana];
}

int** Matrice :: getElemente()
{
	int** copie = alocare(nrLinii, nrColoane);
	for (int i = 0; i < nrLinii; i++)
	{
		for (int j = 0; j < nrColoane; j++)
		{
			copie[i][j] = elem[i][j];
		}
	}
	return copie;
}

//void Matrice::RESIZE(int nrLinii, int nrColoane) 
//{
//	this->nrLinii = nrLinii;
//	this->nrColoane = nrColoane;
//}
//
//Matrice Matrice::operator+(Matrice vector)
//{
//	Matrice suma;
//	suma.cx = cx + vector.cx;
//	suma.cy = cy + vector.cy;
//	suma.cz = cz + vector.cz;
//	return suma;
//}



Matrice::~Matrice()
{
	for (int i = 0; i < nrLinii; i++)
	{
		delete[] elem[i];
	}
	delete[] elem;
	std::cout << "S-a apelat deconstructorul.";
}