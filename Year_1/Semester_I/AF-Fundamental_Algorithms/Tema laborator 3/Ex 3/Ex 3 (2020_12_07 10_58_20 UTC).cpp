#include <iostream>

using namespace std;

void Citire_Matrice(int numar_de_linii, int numar_de_coloane, int matrice[][100])
{
	for (int index_linie = 0; index_linie < numar_de_linii; index_linie++)
		for (int index_coloana = 0; index_coloana < numar_de_coloane; index_coloana++)
			cin >> matrice[index_linie][index_coloana];
	cout << endl;
}

int Verificare_Numar_de_Elemente_Distince(int numar_coloane, int matrice[][100], int linie)
{
	int nr_elemente_distincte = 0, vector[100];
	for (int index = 0; index < numar_coloane; index++)
		vector[index] = matrice[linie][index];
	for (int index = 0; index < numar_coloane; index++)
	{
		int conditie = 1;
		for (int index2 = 0; index2 < numar_coloane && conditie == 1; index2++)
			if (index2 != index && vector[index] == vector[index2])
				conditie = 0;
		if (conditie) nr_elemente_distincte++;
	}
	return nr_elemente_distincte;
}

int Numarul_Maxim_de_Elemente_Distincte(int numar_coloane, int matrice[][100])
{
	int maxim = -1;
	for (int index = 0; index < numar_coloane; index++)
	{
		if (Verificare_Numar_de_Elemente_Distince(numar_coloane, matrice, index) > maxim)
		{
			maxim = Verificare_Numar_de_Elemente_Distince(numar_coloane, matrice, index);
		}
	}
	return maxim;
}

void Eliminare_Linii(int& numar_linii,int numar_coloane, int matrice[][100], int pozitie)
{
	for (int index1 = pozitie; index1 < numar_linii; index1++)
		for (int index2 = 0; index2 < numar_coloane; index2++)
			matrice[index1][index2] = matrice[index1 + 1][index2];
	numar_linii--;
}

void Afisare_Linii_cu_Nr_Maxim_de_Elemente_Distincte(int numar_linii, int numar_coloane, int matrice[][100])
{
	int maxim_aparitii_distincte = Numarul_Maxim_de_Elemente_Distincte(numar_coloane, matrice);
	for (int index = 0; index < numar_linii; index++)
	{
		if (Verificare_Numar_de_Elemente_Distince(numar_coloane, matrice, index) == maxim_aparitii_distincte)
		{
			for (int index2 = 0; index2 < numar_coloane; index2++)
				cout << matrice[index][index2] << " ";
			cout << endl;
			Eliminare_Linii(numar_linii,numar_coloane, matrice, index);
			index--;
		}
	}
}

int main()
{
	int n, m, matrice[100][100];
	cin >> n >> m;
	Citire_Matrice(n, m, matrice);
	Afisare_Linii_cu_Nr_Maxim_de_Elemente_Distincte(n, m, matrice);
	return 0;
}
