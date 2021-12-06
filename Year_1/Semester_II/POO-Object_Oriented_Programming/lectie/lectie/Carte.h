#pragma once
#include "Publicatie.h"

class Carte: public Publicatie
{
private:
	int nrPag;
public:
	Carte();

	int getNrPag();

	void setNrPag(int);

	virtual void afisareInformatii();

	friend std::istream& operator>>(std::istream&, Carte&);
};

