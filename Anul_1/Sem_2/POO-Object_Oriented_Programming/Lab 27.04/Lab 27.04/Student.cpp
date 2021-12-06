#include <iostream>
#include "Student.h"

Student::Student(std::string numeNou, int varstaNoua, std::string profilNou, int valBursaNoua) :Persoana(numeNou, varstaNoua)
{
	this->profil = profilNou;
	this->valBursa = valBursaNoua;
}

void Student::Afisare()
{
	std::cout << nume << " in varsta de " << varsta << " ani , student la profilul ";
	std::cout << profil << " , ia bursa in valoare de " << valBursa << " .\n";
}

int Student::getVenit()
{
	return valBursa;
}

Student::~Student()
{
}
