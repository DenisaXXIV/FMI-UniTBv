#include <string>
#include "Persoana.h"
#pragma once
class Angajat:public Persoana
{
public:
	int salariu;
	std::string firma;

	Angajat(std::string,int,int, std::string);
	virtual void Afisare();
	int getVenit();
	virtual ~Angajat();
};

