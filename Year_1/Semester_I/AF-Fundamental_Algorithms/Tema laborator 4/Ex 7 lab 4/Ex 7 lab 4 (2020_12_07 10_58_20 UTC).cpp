#include <iostream>
#include <stdlib.h>

using namespace std;

void Citire_Matrice(int matrice[][100], int& dimensiune_linii, int& dimensiune_coloane)
{
	cin >> dimensiune_linii >> dimensiune_coloane;
	for (int index = 0; index < dimensiune_linii; index++)
	{
		for (int index2 = 0; index2 < dimensiune_coloane; index2++)
		{
			cin >> matrice[index][index2];
		}
	}
}

void Interschimbare_Linii(int matrice[][100], int dimensiune_coloane, int numar_linie1, int numar_linie2)
{
	for (int index = 0; index < dimensiune_coloane; index++)
	{
		int auxiliar = matrice[numar_linie1][index];
		matrice[numar_linie1][index] = matrice[numar_linie2][index];
		matrice[numar_linie2][index] = auxiliar;
	}
}

void Sortare_dupa_Linii(int matrice[][100], int dimensiune_linii, int dimensiune_coloane)
{
	for (int index1 = 0; index1 < dimensiune_linii - 1; index1++)
	{
		for (int index2 = index1 + 2; index2 < dimensiune_linii; index2++)
		{
			if (matrice[index1][0] > matrice[index2][0])
			{
				Interschimbare_Linii(matrice, dimensiune_coloane, index1, index2);
			}
		}
	}
}

bool Cautare_Binara(int matrice[][100], int dimensiune, int element_cautat)
{
	int stanga = 1, dreapta = dimensiune, pozitie = -1;
	while (stanga < dreapta && pozitie == -1)
	{
		int mijloc = (stanga + dreapta) / 2;
		if (matrice[0][mijloc] == element_cautat)
		{
			pozitie = mijloc;
		}
		else
		{
			if (matrice[0][mijloc] < element_cautat)
			{
				stanga = ++mijloc;
			}
			else
			{
				dreapta = --mijloc;
			}
		}
	}
	if (matrice[0][stanga] == element_cautat)
	{
		pozitie = stanga;
	}
	if (pozitie == -1) return false;
	return true;
}

void Generare_Sir_de_Numere(int matrice[][100], int dimensiune_linii, int dimensiune_coloane)
{
	int Numar_de_Elemente = 0;
	Sortare_dupa_Linii(matrice, dimensiune_linii, dimensiune_coloane);
	for (int index = 0; index < 100; index++)
	{
		int element_random = rand(), verificare = 0;
		verificare = Cautare_Binara(matrice, dimensiune_linii, element_random);
		if (verificare == true)
		{
			cout << element_random << " ";
		}
	}

}

int main()
{
	int matrice[100][100], dimensiune_linii, dimensiune_coloane;
	Citire_Matrice(matrice, dimensiune_linii, dimensiune_coloane);
	Generare_Sir_de_Numere(matrice, dimensiune_linii, dimensiune_coloane);
}

