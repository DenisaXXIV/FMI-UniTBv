#include <iostream>
#include "Persoana.h"

Persoana::Persoana(std::string numeNou, int varstaNou)
{
	this->nume = numeNou;
	this->varsta = varstaNou;
}

void Persoana::Afisare()
{
	std::cout << nume << " are varsta " << varsta << ".\n";
}

Persoana::~Persoana()
{
}
