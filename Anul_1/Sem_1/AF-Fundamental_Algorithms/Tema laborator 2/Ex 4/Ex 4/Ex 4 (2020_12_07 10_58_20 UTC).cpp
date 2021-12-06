#include <iostream>
using namespace std;
void Citire_Vector(int vector[], int numar_de_elemente)
{
	for (int index = 0; index < numar_de_elemente; index++)
	{
		cin >> vector[index];
	}
}
void Inserare_in_Vector_de_k_ori(int vector[], int& numar_de_elemente, int numar_de_pozitii)
{
	while (numar_de_pozitii > 0)
	{
		for (int index = numar_de_elemente - 1; index >= 0; index--)
			vector[index + 1] = vector[index];
		numar_de_elemente = numar_de_elemente + 1;
		numar_de_pozitii--;
	}
}
void Afisare_Vector(int vector[], int numar_de_elemente, int numar_de_pozitii)
{
	Citire_Vector(vector, numar_de_elemente);
	if (numar_de_elemente >= 100) cout << "Eroare";
	else
	{
		Inserare_in_Vector_de_k_ori(vector, numar_de_elemente, numar_de_pozitii);
		for (int index = 0; index < numar_de_pozitii; index++)
		{
			vector[index] = 0;
		}
		for (int index2 = 0; index2 < numar_de_elemente; index2++)
		{
			cout << vector[index2] << " ";
		}
	}
}

int main()
{
	int n, k, vector[100];
	cin >> n >> k;
	Afisare_Vector(vector, n, k);
	return 0;
}
