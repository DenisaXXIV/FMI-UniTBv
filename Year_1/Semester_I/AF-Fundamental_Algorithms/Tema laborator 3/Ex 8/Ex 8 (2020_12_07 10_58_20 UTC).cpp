#include <iostream>

using namespace std;

void Citire_Matrice_Patratica(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	for (int index_linie = 0; index_linie < numar_de_linii_si_de_coloane; index_linie++)
		for (int index_coloana = 0; index_coloana < numar_de_linii_si_de_coloane; index_coloana++)
			cin >> matrice[index_linie][index_coloana];
}

void Afisare_Numere(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	for(int index=0;index<2*numar_de_linii_si_de_coloane;index++)
		for (int index2 = 0; index2 < index; index2++)
		{
			if (index - 1 - index2 < numar_de_linii_si_de_coloane && index2 < numar_de_linii_si_de_coloane)
			{
				if (index % 2 == 0)
					cout << matrice[index - 1 - index2][index2] << " ";
				else cout << matrice[index2][index - 1 - index2] << " ";
			}
		}
}

int main()
{
	int n, matrice[100][100];
	cin >> n;
	Citire_Matrice_Patratica(n, matrice);
	Afisare_Numere(n, matrice);
	return 0;
}
