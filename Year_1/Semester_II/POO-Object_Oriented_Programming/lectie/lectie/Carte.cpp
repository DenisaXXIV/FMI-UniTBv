#include "Carte.h"

Carte::Carte():Publicatie()
{
	this->nrPag = 0;
	std::cout << "Constructor Carte";
}

int Carte::getNrPag()
{
	return nrPag;
}

void Carte::setNrPag(int nrPag)
{
	this->nrPag = nrPag;
}

void Carte::afisareInformatii()
{
	std::cout << "Cartea ,," << getTitlu() << "`` de " << getAutori() << " are " << getNrPag();
	std::cout << "pagini si costa " << std::setprecision(2) << getPret() << " lei.";
}

std::istream& operator >>(std::istream& in, Carte& C)
{
	std::string titlu;
	std::string autori;
	float pret;
	int nrPag;

	std::cout << "Titlul cartii: ";
	std::getline(in, titlu);

	std::cout << "\nAutorii cartii:";
	std::getline(in, autori);

	std::cout << "\nNumarul de pagini ale cartii:";
	in >> nrPag;

	std::cout << "\nPretul cartii:";
	in >> pret;

	C.setTitlu(titlu);
	C.setAutori(autori);
	C.setNrPag(nrPag);
	C.setPret(pret);

	return in;
}