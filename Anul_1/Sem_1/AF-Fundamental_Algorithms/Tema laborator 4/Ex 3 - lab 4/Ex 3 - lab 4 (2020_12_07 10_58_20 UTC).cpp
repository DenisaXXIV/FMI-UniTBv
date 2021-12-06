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

int Aflare_Pozitie_ELEM(int vector[], int marime_vector, int elem)
{
	for (int index = 0; index < marime_vector-1; index++)
	{
		if (vector[index] <= elem && vector[index + 1] > elem)
			return index + 1;
	}
}

void Inserare_ELEM(int vector[], int marime_vector,int elem)
{
	int pozitie = Aflare_Pozitie_ELEM(vector, marime_vector, elem);
	for (int index = marime_vector; index > pozitie; index--)
	{
		vector[index] = vector[index - 1];
	}
	marime_vector++;
	vector[pozitie] = elem;
	Afisare(vector, marime_vector);
}

void Eliminare_element(int vector[], int& dim, int pozitie)
{
	for (int index = pozitie; index < dim; index++)
	{
		vector[index] = vector[index + 1];
	}
	dim--;
}

int Verificare_Sortare(int vector[], int& marime_vector,int elem)
{
	for (int index1 = 0; index1 < marime_vector-1; index1++)
	{
		for (int index2 = index1 + 1; index2 < marime_vector; index2++)
		{
			if (vector[index1] > vector[index2])
			{
				Eliminare_element(vector, marime_vector, index1);
				return Verificare_Sortare(vector, marime_vector, elem);
			}
		}
	}
}

int main()
{
	int dim, vector[100],elem;
	cin >> dim>>elem;
	Citire_Vector(vector, dim);
	Verificare_Sortare(vector, dim,elem);
	Inserare_ELEM(vector, dim, elem);
}
