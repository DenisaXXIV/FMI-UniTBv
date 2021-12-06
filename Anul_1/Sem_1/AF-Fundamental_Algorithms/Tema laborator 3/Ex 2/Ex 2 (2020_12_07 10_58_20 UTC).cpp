#include <iostream>

using namespace std;

void Citire_Matrice_Patratica(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	for (int index_linie = 0; index_linie < numar_de_linii_si_de_coloane; index_linie++)
		for (int index_coloana = 0; index_coloana < numar_de_linii_si_de_coloane; index_coloana++)
			cin >> matrice[index_linie][index_coloana];
}

void Aflare_Sume(int numar_de_linii_si_de_coloane, int matrice[][100], int& suma_sus, int& suma_jos, int& suma_stanga, int& suma_dreapta)
{
	for (int index_linie = 0; index_linie < numar_de_linii_si_de_coloane; index_linie++)
		for (int index_coloana = 0; index_coloana < numar_de_linii_si_de_coloane; index_coloana++)
		{
			if ((index_coloana + index_linie < numar_de_linii_si_de_coloane - 1) && (index_linie < index_coloana))
				suma_sus = suma_sus + matrice[index_linie][index_coloana];
			else
			{
				if ((index_coloana + index_linie > numar_de_linii_si_de_coloane - 1) && (index_linie < index_coloana))
					suma_dreapta = suma_dreapta + matrice[index_linie][index_coloana];
				else
				{
					if ((index_coloana + index_linie > numar_de_linii_si_de_coloane - 1) && (index_linie > index_coloana))
						suma_jos = suma_jos + matrice[index_linie][index_coloana];
					else
					{
						if ((index_coloana + index_linie < numar_de_linii_si_de_coloane - 1) && (index_linie > index_coloana))
							suma_stanga = suma_stanga + matrice[index_linie][index_coloana];
					}
				}
			}
		}
}

void Afisare_Sume(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	int suma_sus = 0, suma_jos = 0, suma_stanga = 0, suma_dreapta = 0;
	Aflare_Sume(numar_de_linii_si_de_coloane, matrice, suma_sus, suma_jos, suma_stanga, suma_dreapta);
	cout << suma_sus << " " << suma_dreapta << " " << suma_jos << " " << suma_stanga;
}

int main()
{
	int n, matrice[100][100];
	cin >> n;
	Citire_Matrice_Patratica(n, matrice);
	Afisare_Sume(n, matrice);
	return 0;
}
