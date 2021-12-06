#include <iostream>
#include <cmath>
using namespace std;

void Citire_Vector(int vector[], int marime_vector)
{
	for (int index = 0; index < marime_vector; index++)
	{
		cin >> vector[index];
	}
}

bool Verificare_Palindrom(int numar, int dimensiune)
{
	int numar1 = numar / pow(10, dimensiune / 2);
	int numar2 = numar % ((int)pow(10, dimensiune / 2));
	int oglindit_numar1 = 0;
	if (dimensiune % 2 == 1)
		numar1 /= 10;
	while (numar1 != 0)
	{
		oglindit_numar1 = oglindit_numar1 * 10 + numar1 % 10;
		numar1 /= 10;
	}
	if (oglindit_numar1 == numar2)
		return true;
	else
		return false;
}

void Afisare(int vector[], int marime_vector)
{

	for (int index = 0; index < marime_vector; index++)
	{
		cout << vector[index] << " ";
	}
}

void Sortare_vector(int vector[], int marime_vector, int dimensiune)
{
	for (int index1 = 0; index1 < marime_vector - 1; index1++)
	{
		for (int index2 = index1 + 1; index2 < marime_vector; index2++)
		{
			if (vector[index1] > vector[index2] && Verificare_Palindrom(vector[index1], dimensiune) && Verificare_Palindrom(vector[index2], dimensiune))
			{
				int auxiliar = vector[index1];
				vector[index1] = vector[index2];
				vector[index2] = auxiliar;
			}
		}
	}
	Afisare(vector, marime_vector);
}

int main()
{
	int vector[100], marime_vector, dim;
	cin >> marime_vector >> dim;
	Citire_Vector(vector, marime_vector);
	Sortare_vector(vector, marime_vector, dim);
}
