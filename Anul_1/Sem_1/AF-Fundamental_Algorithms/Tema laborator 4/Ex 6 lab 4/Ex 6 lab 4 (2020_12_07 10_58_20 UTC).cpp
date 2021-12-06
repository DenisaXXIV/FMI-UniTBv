#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void Generare_Sir(int* vector, int& dimensiune)
{
	cin >> dimensiune;
	for (int index = 0; index < dimensiune; index++)
	{
		vector[index] = rand();
	}

	for (int index = 0; index < dimensiune; index++)
	{
		cout << vector[index] << " ";
	}
	cout << endl;
}

void Interschimbare(int& numar1, int& numar2)
{
	int auxiliar = numar1;
	numar1 = numar2;
	numar2 = auxiliar;
}

void Sortare(int* vector,int dimensiune)
{
	for (int index1 = 0; index1 < dimensiune-1; index1 += 2)
	{
		for (int index2 = index1 + 2; index2 < dimensiune; index2 += 2)
		{
			if (vector[index1] > vector[index2])
			{
				Interschimbare(vector[index1], vector[index2]);
			}
		}
	}
}

void Afisare_Vector_Sortat(int* vector, int dimensiune)
{
	Sortare(vector, dimensiune);
	for (int index = 0; index < dimensiune; index++)
	{
		cout << vector[index] << " ";
	}
}

int main()
{
	int vector[100],dimensiune;
	Generare_Sir(vector, dimensiune);
	Afisare_Vector_Sortat(vector, dimensiune);
}

