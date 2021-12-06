#include <iostream>

using namespace std;

void Citire_Matrice_Patratica(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	for (int index_linie = 0; index_linie < numar_de_linii_si_de_coloane; index_linie++)
		for (int index_coloana = 0; index_coloana < numar_de_linii_si_de_coloane; index_coloana++)
			cin >> matrice[index_linie][index_coloana];
}

void Interschimbare(int& numar1, int& numar2)
{
	int numar_auxiliar = numar1;
	numar1 = numar2;
	numar2 = numar_auxiliar;
}

void Ordonare_Elemente_de_pe_Diagonala_Principala(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	for (int index1 = 0; index1 < numar_de_linii_si_de_coloane-1; index1++)
	{
		for (int index2 = index1; index2 < numar_de_linii_si_de_coloane; index2++)
		{
			if (matrice[index1][index1] > matrice[index2][index2])
				Interschimbare(matrice[index1][index1], matrice[index2][index2]);
		}
	}
}

void Afisare_Matrice(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	Ordonare_Elemente_de_pe_Diagonala_Principala(numar_de_linii_si_de_coloane, matrice);
	for (int index_linie = 0; index_linie < numar_de_linii_si_de_coloane; index_linie++)
	{
		for (int index_coloana = 0; index_coloana < numar_de_linii_si_de_coloane; index_coloana++)
			cout << matrice[index_linie][index_coloana] << " ";
		cout << endl;
	}

}

int main()
{
	int n, matrice[100][100];
	cin >> n;
	Citire_Matrice_Patratica(n, matrice);
	Afisare_Matrice(n, matrice);
	return 0;
}
