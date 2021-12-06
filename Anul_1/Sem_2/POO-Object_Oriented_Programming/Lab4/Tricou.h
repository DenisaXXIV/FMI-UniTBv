#include <iostream>
#pragma once

using namespace std;

class Tricou
{
private:
	string firmaProducator;
	string marime;
	double pret;
public:
	///Fara parametri
	//Tricou();


	//Cu parametri
	/*Tricou(string, string, double);*/


	///Fara parametri si cu valori implicite
	Tricou(string = "-", string="-", double = 0);

	friend ostream& operator<< (ostream&, Tricou);

	friend istream& operator>>(istream&, Tricou&);

	void setPret(double pretNou);

	void setPretProcent (double procent);

	double getPret();

	double getPretFaraTVA();

	bool operator< (Tricou t);
};
