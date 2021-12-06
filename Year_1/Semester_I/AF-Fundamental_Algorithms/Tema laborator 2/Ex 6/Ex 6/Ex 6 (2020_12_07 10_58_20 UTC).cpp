#include <iostream>

using namespace std;

void Citire_Vector(int vector[], int numar_de_elemente)
{
	for (int index = 0; index < numar_de_elemente; index++)
	{
		cin >> vector[index];
	}
}

void Interclasare_v1_si_v2(int vector_final[], int vector1[], int vector2[],int numar_de_elemente1,int numar_de_elemente2, int& numar_de_elemente_final)
{
	int index1 = 0, index2 = 0, index_final = 0;
	while (index1 < numar_de_elemente1 && index2 < numar_de_elemente2)
	{
		if (vector1[index1] < vector2[index2])
		{
			vector_final[index_final++] = vector1[index1++];
		}
		else
		{
			vector_final[index_final++] = vector2[index2++];
		}
	}
	while (index1 < numar_de_elemente1)
	{
		vector_final[index_final++] = vector1[index1++];
	}
	while (index2 < numar_de_elemente2)
	{
		vector_final[index_final++] = vector2[index2++];
	}
	numar_de_elemente_final = index_final;
}

void Afisare_Vector(int vector1[], int numar_de_elemente1, int vector2[], int numar_de_elemente2)
{

	int vector_final[201],numar_de_elemente_total;
	if (numar_de_elemente1 >= 100 || numar_de_elemente2>=100) cout << "Eroare";
	else
	{
		Interclasare_v1_si_v2(vector_final, vector1, vector2, numar_de_elemente1, numar_de_elemente2, numar_de_elemente_total);
		for (int index = 0; index < numar_de_elemente_total; index++)
		{
			cout << vector_final[index] << " ";
		}
	}
}

int main()
{
	int v1[100],v2[100], n, m;
	cin >> n >> m;
	Citire_Vector(v1, n);
	Citire_Vector(v2, m);
	Afisare_Vector(v1, n,v2,m);
}
