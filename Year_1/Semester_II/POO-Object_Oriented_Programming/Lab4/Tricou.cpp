#include "Tricou.h"
#include <iostream>

using namespace std;

//Tricou::Tricou()
//{
//	firmaProducator = "-";
//	marime = "-";
//	pret = 0;
//}

Tricou::Tricou(string firmaProducator, string marime, double pret)
{
	this->firmaProducator = firmaProducator;
	this->marime = marime;
	this->pret = pret;
}

ostream& operator<<(ostream& out, Tricou t)
{
	out << "Firma producatoare: " << t.firmaProducator << endl;
	out << "Marimea: " << t.marime << endl;
	out << "Pret: " << t.pret<<endl;
	out << endl;
	return out;
}

istream& operator>>(istream& in, Tricou& t)
{
	in >> t.firmaProducator >> t.marime >> t.pret;
	return in;
}

void Tricou::setPret(double pretNou)
{
	pret = pretNou;
}

double Tricou::getPret()
{
	return pret;
}

double Tricou::getPretFaraTVA()
{
	return pret*(1+19/100);
}

bool Tricou::operator<(Tricou t)
{
	return (pret < t.pret);
}