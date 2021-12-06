#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Publicatie
{
protected:
	std::string titlu;
	std::string autori;
	float pret;

public:
	Publicatie(std::string,std::string,float);
	Publicatie();

	std::string getTitlu();
	std::string getAutori();
	float getPret();

	void setTitlu(std::string);
	void setAutori(std::string);
	void setPret(float);

	void afisareInformatii();
	friend std::istream& operator >>(std::istream&, Publicatie&);

};

