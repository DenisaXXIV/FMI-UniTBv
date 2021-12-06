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

void Interschimbare_Elemente_Simetrice_de_acceasi_Paritate(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	for (int index1 = 0; index1 < numar_de_linii_si_de_coloane ; index1++)
	{
		for (int index2 = 0; index2 < numar_de_linii_si_de_coloane; index2++)
		{
			if (matrice[index1][index2] % 2 == matrice[index2][index1] % 2 && index1 != index2 && index1<index2)
				Interschimbare(matrice[index1][index2], matrice[index2][index1]);
		}
	}
}

void Afisare_Matrice(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	Interschimbare_Elemente_Simetrice_de_acceasi_Paritate(numar_de_linii_si_de_coloane, matrice);
	cout << endl;
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
