#include <iostream>

using namespace std;

void Citire_Vector(int vector[], int numar_de_elemente )
{
	for (int index = 0; index < numar_de_elemente; index++)
	{
		cin >> vector[index];
	}
}

void Eliminare_Element_de_pe_Pozitia_p(int vector[], int numar_de_elemente, int indicele_de_pozitie)
{
	for (int index = indicele_de_pozitie; index < numar_de_elemente-1; index++)
	{
		vector[index] = vector[index + 1];
	}
	numar_de_elemente--;
}

void Inserare_p_pe_Prima_Pozitie_din_Vector(int vector[], int numar_de_elemente, int indicele_de_pozitie)
{
	for (int index = numar_de_elemente + 1; index >= 0; index--)
	{
		vector[index + 1] = vector[index];
	}
	numar_de_elemente++;
	vector[0] = indicele_de_pozitie;
}

void Afisare_Vector(int vector[], int numar_de_elemente, int indicele_de_pozitie)
{
	
	if (numar_de_elemente >= 100) cout << "Eroare";
	else
	{
		Eliminare_Element_de_pe_Pozitia_p(vector, numar_de_elemente, indicele_de_pozitie);
		Inserare_p_pe_Prima_Pozitie_din_Vector(vector, numar_de_elemente, indicele_de_pozitie);
		for (int index = 0; index < numar_de_elemente; index++)
		{
			cout << vector[index] << " ";
		}
	}
}

int main()
{
    int v[100], n, p;
	cin >> n >> p;
	Citire_Vector(v, n);
	Afisare_Vector(v, n, p);
}
