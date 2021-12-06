#include <string>
#pragma once
class Persoana
{
public:
	std::string nume;
	int varsta;

	Persoana(std::string, int);

	virtual void Afisare();
	virtual ~Persoana();
};

