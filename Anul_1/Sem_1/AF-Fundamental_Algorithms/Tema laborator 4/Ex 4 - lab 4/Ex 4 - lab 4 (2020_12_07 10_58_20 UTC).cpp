#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cautari.txt");

void Afisare(int vector[], int marime_vector)
{

	for (int index = 1; index <= marime_vector; index++)
	{
		cout << vector[index] << " ";
	}
}

void Interschimbare(int& numar1, int& numar2)
{
	int auxiliar = numar1;
	numar1 = numar2;
	numar2 = auxiliar;
}

void Ordonare_Vector(int vector[], int dim)
{
	int vector_pozitie[100];
	for (int index = 1; index <= dim; index++)
		vector_pozitie[index] = index;
	for (int index1 = 1; index1 < dim; index1++)
	{
		for (int index2 = index1 + 1; index2 <= dim; index2++)
		{
			if (vector[index1] > vector[index2])
			{
				Interschimbare(vector[index1], vector[index2]);
				Interschimbare(vector_pozitie[index1], vector_pozitie[index2]);
			}
		}
	}
	Afisare(vector_pozitie, dim);
}

int main()
{
	int vector[100], element_vector, index = 1;
	while (fin >> element_vector)
	{
		vector[index++] = element_vector;
	}
	int dim = --index;
	Ordonare_Vector(vector, dim);
}
