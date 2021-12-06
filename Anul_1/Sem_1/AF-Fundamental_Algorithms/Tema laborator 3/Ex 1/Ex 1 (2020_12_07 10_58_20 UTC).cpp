#include <iostream>

using namespace std;

void Citire_Matrice_Patratica(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	for (int index1 = 0; index1 < numar_de_linii_si_de_coloane; index1++)
		for (int index2 = 0; index2 < numar_de_linii_si_de_coloane; index2++)
			cin >> matrice[index1][index2];
}

void Gasire_Element_Maxim_de_pe_Diagonala_Principala(int numar_de_linii_si_de_coloane, int matrice[][100], int& element_maxim, int& index_element)
{
	for (int index = 1; index < numar_de_linii_si_de_coloane; index++)
		if (element_maxim < matrice[index][index])
		{
			element_maxim = matrice[index][index];
			index_element = index;
		}
}

void Gasire_Element_Minim_de_pe_Diagonala_Secundara(int numar_de_linii_si_de_coloane, int matrice[][100], int& element_minim, int& index_element)
{
	for (int index = 1; index < numar_de_linii_si_de_coloane; index++)
		if (element_minim > matrice[index][numar_de_linii_si_de_coloane - 1 - index])
		{
			element_minim = matrice[index][numar_de_linii_si_de_coloane - 1 - index];
			index_element = index;
		}
}

void Modificare_Matrice(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	int element_maxim = matrice[0][0], element_minim = matrice[0][numar_de_linii_si_de_coloane - 1], index_element_maxim = 0, index_element_minim = 0;
	Gasire_Element_Maxim_de_pe_Diagonala_Principala(numar_de_linii_si_de_coloane, matrice, element_maxim, index_element_maxim);
	Gasire_Element_Minim_de_pe_Diagonala_Secundara(numar_de_linii_si_de_coloane, matrice, element_minim, index_element_minim);
	matrice[index_element_maxim][index_element_maxim] = element_minim;
	matrice[index_element_minim][numar_de_linii_si_de_coloane - 1 - index_element_minim] = element_maxim;
}

void Afisare_Matrice_Patratica(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	Modificare_Matrice(numar_de_linii_si_de_coloane, matrice);
	for (int index1 = 0; index1 < numar_de_linii_si_de_coloane; index1++)
	{
		for (int index2 = 0; index2 < numar_de_linii_si_de_coloane; index2++)
			cout << matrice[index1][index2]<<" ";
		cout << endl;
	}
}

int main()
{
	int n, matrice[100][100];
	cin >> n;
	Citire_Matrice_Patratica(n, matrice);
	Afisare_Matrice_Patratica(n, matrice);
	return 0;
}
