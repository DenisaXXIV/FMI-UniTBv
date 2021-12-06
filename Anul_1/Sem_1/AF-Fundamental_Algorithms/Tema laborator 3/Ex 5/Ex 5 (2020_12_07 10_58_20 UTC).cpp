#include <iostream>

using namespace std;

void Citire_Matrice_Patratica(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	for (int index_linie = 0; index_linie < numar_de_linii_si_de_coloane; index_linie++)
		for (int index_coloana = 0; index_coloana < numar_de_linii_si_de_coloane; index_coloana++)
			cin >> matrice[index_linie][index_coloana];
}

void Rotire_Matrice(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	int matrice_auxiliara[100][100];
	for (int index_linie = 0; index_linie < numar_de_linii_si_de_coloane; index_linie++)
		for (int index_coloana = 0; index_coloana < numar_de_linii_si_de_coloane; index_coloana++)
			matrice_auxiliara[index_linie][index_coloana] = matrice[index_linie][index_coloana];
	for (int index_linie = 0; index_linie < numar_de_linii_si_de_coloane; index_linie++)
		for (int index_coloana = 0; index_coloana < numar_de_linii_si_de_coloane; index_coloana++)
			matrice[index_linie][index_coloana] = matrice_auxiliara[numar_de_linii_si_de_coloane - 1 - index_coloana][index_linie];
}

void Afisare_Matrice(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	Rotire_Matrice(numar_de_linii_si_de_coloane, matrice);
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
