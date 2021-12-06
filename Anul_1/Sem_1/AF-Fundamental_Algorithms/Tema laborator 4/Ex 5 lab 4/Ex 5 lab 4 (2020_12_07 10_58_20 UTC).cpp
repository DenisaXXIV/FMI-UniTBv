#include <iostream>
#include <fstream>

using namespace std;

void Citire_Vector_din_FISIER(int* vector, int& dimensiune)
{
	ifstream fin("cautari.in");
	int element_vector;
	while (fin >> element_vector)
	{
		vector[dimensiune++] = element_vector;
	}
	dimensiune--;
	fin.close();
}

void Citire_Vector(int vector[], int& dimensiune)
{
	cin >> dimensiune;
	for (int index = 0; index < dimensiune; index++)
	{
		cin >> vector[index];
	}
}


void Interschimbare(int& numar1, int& numar2)
{
	int auxiliar = numar1;
	numar1 = numar2;
	numar2 = auxiliar;
}

int Cautare_Binara(int* vector, int dimensiune, int element_cautat)
{
	int stanga = 0, dreapta = dimensiune - 1, pozitie = -1;
	while (stanga < dreapta && pozitie == -1)
	{
		int mijloc = (stanga + dreapta) / 2;
		if (vector[mijloc] == element_cautat)
		{
			pozitie = mijloc;
		}
		else
		{
			if (vector[mijloc] > element_cautat)
			{
				stanga = ++mijloc;
			}
			else
			{
				dreapta = --mijloc;
			}
		}
	}
	if (vector[stanga] == element_cautat)
	{
		pozitie = stanga;
	}
	return pozitie;
}

void Afisare_in_Fisier(int* vector1_din_fisier, int* vector2_din_consola, int dimensiune1, int dimensiune2)
{
	ofstream fout("cautari.out");

	for (int index = 0; index < dimensiune2; index++)
	{
		int pozitie = Cautare_Binara(vector1_din_fisier, dimensiune2, vector2_din_consola[index]);
		if (pozitie != -1)
		{
			fout << "Elementul " << vector2_din_consola[index] << " din al doilea vector apare si in primul pe pozitia " << pozitie << endl;;
		}
		else
		{
			fout << "Elementul " << vector2_din_consola[index] << " din al doilea vector NU apare si in primul vector" << endl;;
		}
	}
	fout.close();
}

int main()
{
	int vector1[100], vector2[100];
	int dim1 = 0, dim2;
	Citire_Vector_din_FISIER(vector1, dim1);
	Citire_Vector(vector2, dim2);
	Afisare_in_Fisier(vector1, vector2, dim1, dim2);
}

