#include <iostream>
#include "Angajat.h"

Angajat::Angajat(std::string numeNou, int varstaNoua, int salariuNou, std::string firmaNoua):Persoana(numeNou, varstaNoua)
{
	this->salariu = salariuNou;
	this->firma = firmaNoua;
}

void Angajat::Afisare()
{
	std::cout << nume << " in varsta de " << varsta << " ani lucreaza la firma " << firma;
	std::cout << " si castiga un salariu de " << salariu << ".\n";
}

int Angajat::getVenit()
{
	return salariu;
}

Angajat::~Angajat()
{
}
