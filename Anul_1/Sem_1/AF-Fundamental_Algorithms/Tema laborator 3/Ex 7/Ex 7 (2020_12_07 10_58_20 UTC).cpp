#include <iostream>

using namespace std;

void Generare_Matrice(int numar_de_linii_si_de_coloane, int matrice[][100])
{
	for (int index_linie = 0; index_linie < numar_de_linii_si_de_coloane; index_linie++)
		for (int index_coloana = 0; index_coloana < numar_de_linii_si_de_coloane; index_coloana++)
			if (index_linie <= index_coloana)
				matrice[index_linie][index_coloana] = (index_coloana - index_linie) + 1;
			else
				matrice[index_linie][index_coloana] = (index_linie - index_coloana) + 1;
}

void Afisare_Matrice(int numar_de_linii_si_de_coloane, int matrice[][100])
{
		Generare_Matrice(numar_de_linii_si_de_coloane, matrice);
		for (int index_linie = 0; index_linie < numar_de_linii_si_de_coloane; index_linie++)
		{
			for (int index_coloana = 0; index_coloana < numar_de_linii_si_de_coloane; index_coloana++)
				cout << matrice[index_linie][index_coloana] << " ";
			cout << endl;
		}

}

int main()
{
	int n, matrice[100][100];
	cin >> n;
	Afisare_Matrice(n, matrice);
	return 0;
}
