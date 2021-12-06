#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream in("numere.in");
ofstream out("numere.out");

void Construire_Matrice(int marime_matrice, int matrice[][100])
{
	int index = 0;
	while (index < marime_matrice / 2)
	{
		int linie = index - 1, coloana = index;
		while (linie < marime_matrice - 1 - index)
			in >> matrice[++linie][coloana];
		while (coloana < marime_matrice - 1 - index)
			in >> matrice[linie][++coloana];
		while (linie > index)
			in >> matrice[--linie][coloana];
		while (coloana > index + 1)
			in >> matrice[linie][--coloana];
		index++;
		if (marime_matrice % 2 == 1)
			in >> matrice[marime_matrice / 2][marime_matrice / 2];
	}
}

void Afisare_Matrice(int numar)
{
	int matrice[100][100], marime_matrice = sqrt(numar);
	Construire_Matrice(marime_matrice, matrice);
	for (int index_linie = 0; index_linie < marime_matrice; index_linie++)
	{
		for (int index_coloana = 0; index_coloana < marime_matrice; index_coloana++)
			out << matrice[index_linie][index_coloana] << " ";
		out << endl;
	}
}

int main()
{
	int n;
	in >> n;
	Afisare_Matrice(n);
	return 0;
}
