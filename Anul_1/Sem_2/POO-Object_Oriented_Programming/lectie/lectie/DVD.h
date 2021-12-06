#pragma once
#include "Publicatie.h"

class DVD:public Publicatie
{
private:
	int durata; // in minute
public:
	DVD();

	int getDurata();

	void setDurata(int);

	virtual void afisareInformatii();

	friend std::istream& operator>>(std::istream&, DVD&);
};

