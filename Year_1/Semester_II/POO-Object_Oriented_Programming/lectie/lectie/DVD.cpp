#include "DVD.h"

DVD::DVD() :Publicatie()
{
	this->durata = 0;
	std::cout << "Constructor DVD";
}

int DVD::getDurata()
{
	return durata;
}

void DVD::setDurata(int durata)
{
	this->durata = durata;
}

void DVD::afisareInformatii()
{
	std::cout << "DVD-ul ,," << getTitlu() << "`` de " << getAutori() << " dureaza " << getDurata();
	std::cout << " minute si costa " << std::setprecision(2) << getPret() << " lei.";
}

std::istream& operator >>(std::istream& in, DVD& D)
{
	std::string titlu;
	std::string autori;
	float pret;
	int durata;

	std::cout << "Titlul DVD-ului: ";
	std::getline(in, titlu);

	std::cout << "\nAutorii DVD-ului:";
	std::getline(in, autori);

	std::cout << "\nDurata DVD-ului:";
	in >> durata;

	std::cout << "\nPretul DVD-ului:";
	in >> pret;

	D.setTitlu(titlu);
	D.setAutori(autori);
	D.setDurata(durata);
	D.setPret(pret);

	return in;
}