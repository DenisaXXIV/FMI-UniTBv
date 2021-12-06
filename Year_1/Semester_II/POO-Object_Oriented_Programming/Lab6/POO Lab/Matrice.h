#pragma once
class Matrice
{
private:
	int nrLinii, nrColoane;
	int** elem;
	int** alocare(int nrLinii, int nrColoane);
public:
	Matrice(int diemsniune);
	Matrice(int nr_linii, int nr_coloane);
	Matrice();
	Matrice(const Matrice& m);
	int getNrLinii();
	int getNrColoane();
	int** getElemente();
	void resize(int nrLinii, int nrColoane);
	Matrice operator +(Matrice m);
	Matrice operator -(Matrice m);
	Matrice operator *(Matrice m);
	friend Matrice operator *(int alfa, Matrice m);
	friend std::ostream& operator <<(std::ostream& out, Matrice m);
	friend std::istream& operator >>(std::istream& in, Matrice& m);
	~Matrice();
	int getValoare(int linie, int coloana);
	int* operator[](int linie);
};

