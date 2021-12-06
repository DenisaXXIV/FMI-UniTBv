#include <iostream>
#include <fstream>

using namespace std;

void Copie_Vector(int* vector, int* copie_vector, int dimensiune)
{
	for (int index = 1; index <= dimensiune; index++)
	{
		copie_vector[index] = vector[index];
	}
}

void Citire_Vector(int* vector, int& dimensiune,int* vector_ordonat)
{
	ifstream fin("cautari.txt");
	int element_vector;
	while (fin >> element_vector)
	{
		vector[dimensiune++] = element_vector;
	}
	dimensiune--;
	fin.close();
	Copie_Vector(vector, vector_ordonat, dimensiune);
}

void Interschimbare(int& numar1, int& numar2)
{
	int auxiliar = numar1;
	numar1 = numar2;
	numar2 = auxiliar;
}

void Ordonare_Vector(int* vector, int dimensiune)
{
	for (int index = 1; index < dimensiune; index++)
	{
		for (int index2 = index + 1; index2 <= dimensiune; index2++)
		{
			if (vector[index] > vector[index2])
			{
				Interschimbare(vector[index], vector[index2]);
			}
		}
	}
}

void Afisare_Pozitii(int* vector, int* vector_ordonat, int dimensiune)
{
	Ordonare_Vector(vector_ordonat, dimensiune);
	for (int index = 1; index <= dimensiune; index++)
	{
		bool cautare_element = false;
		for (int index2 = 1; index2 <= dimensiune && cautare_element==false; index2++)
		{
			if (vector_ordonat[index] == vector[index2])
			{
				cautare_element = true;
				cout << index2 << " ";
			}
		}
	}
}

int main()
{
	int vector[100],vector_ordonat[100],  dim = 1;
	Citire_Vector(vector, dim, vector_ordonat);
	Afisare_Pozitii(vector, vector_ordonat, dim);
}

