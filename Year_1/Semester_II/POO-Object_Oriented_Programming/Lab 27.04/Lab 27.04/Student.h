#include "Persoana.h"
#pragma once
class Student :public Persoana
{
public:
	std::string profil;
	int valBursa;

	Student(std::string, int, std::string, int);

	virtual void Afisare(); 
	int getVenit();
	virtual ~Student();
};

