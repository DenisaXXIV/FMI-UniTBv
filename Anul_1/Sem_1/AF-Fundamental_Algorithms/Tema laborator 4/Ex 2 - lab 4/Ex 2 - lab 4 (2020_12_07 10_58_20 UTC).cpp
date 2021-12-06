#include <iostream>

using namespace std;

void Citire_Vector(int vector[], int marime_vector)
{
	for (int index = 0; index < marime_vector; index++)
	{
		cin >> vector[index];
	}
}

void Afisare(int vector[], int marime_vector)
{

	for (int index = 0; index < marime_vector; index++)
	{
		cout << vector[index] << " ";
	}
}

void Sortare_vector(int vector[], int marime_vector)
{
	for (int index1 = 0; index1 < marime_vector/2 -1; index1++)
	{
		for (int index2 = index1 + 1; index2 < marime_vector/2; index2++)
		{
			if (vector[index1] > vector[index2])
			{
				int auxiliar = vector[index1];
				vector[index1] = vector[index2];
				vector[index2] = auxiliar;
			}
		}
	}
	for (int index1 = marime_vector / 2; index1 < marime_vector- 1; index1++)
	{
		for (int index2 = index1 + 1; index2 < marime_vector; index2++)
		{
			if (vector[index1] < vector[index2])
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
	int dim,vector[100];
	cin >> dim;
	Citire_Vector(vector, dim);
	Sortare_vector(vector, dim);
}
