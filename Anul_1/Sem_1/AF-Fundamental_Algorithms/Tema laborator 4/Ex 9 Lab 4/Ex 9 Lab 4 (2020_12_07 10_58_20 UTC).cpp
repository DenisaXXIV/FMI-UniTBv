#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void Citire_Vector(int* vector, int& dimensiune, int* vector_ordonat)
{
	ifstream fin("cautari.txt");
	int element_vector;
	while (fin >> element_vector)
	{
		vector[dimensiune++] = element_vector;
	}
	dimensiune--;
	fin.close();
}

struct myclass {
	bool operator() (int i, int j) { return (i < j); }
} myobject;


void Afisare_Pozitii(int* vector, int* vector_ordonat, int dimensiune)
{
	sort(vector.begin(), vector.end(), myobject);
	for (int index = 1; index <= dimensiune; index++)
	{
		bool cautare_element = false;
		for (int index2 = 1; index2 <= dimensiune && cautare_element == false; index2++)
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
	int vector[100], vector_ordonat[100], dim = 1;
	Citire_Vector(vector, dim, vector_ordonat);
	Afisare_Pozitii(vector, vector_ordonat, dim);
}

