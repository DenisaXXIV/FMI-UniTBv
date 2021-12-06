#include "Publicatie.h"

Publicatie::Publicatie(std::string titlu, std::string autori, float pret)
{
	this->titlu = titlu;
	this->autori = autori;
	this->pret = pret;
}

Publicatie::Publicatie()
{
	this->titlu = "";
	this->autori = "";
	this->pret = 0;

	std::cout << "Constructor Publicatie\n";
}

std::string Publicatie::getTitlu()
{
	return titlu;
}

std::string Publicatie::getAutori()
{
	return autori;
}

float Publicatie::getPret()
{
	return pret;
}

void Publicatie::setTitlu(std::string titlu)
{
	this->titlu = titlu;
}

void Publicatie::setAutori(std::string autori)
{
	this->autori = autori;
}

void Publicatie::setPret(float pret)
{
	this->pret = pret;
}

void Publicatie::afisareInformatii()
{
	std::cout << "Publicatia ,," << getTitlu() << "`` de " << getAutori() << " costa ";
	std::cout << std::setprecision(2) << getPret()<<" lei.";
}

std::istream& operator >>(std::istream& in, Publicatie P)
{
	std::string titlu;
	std::string autori;
	float pret;

	std::cout << "Titlul publicatiei: ";
	std::getline(in, titlu);

	std::cout << "\nAutorii publicatiei:";
	std::getline(in, autori);

	std::cout << "\nPretul publicatiei:"; 
	in>> pret;

	P.setTitlu(titlu);
	P.setAutori(autori);
	P.setPret(pret);
	return in;
}