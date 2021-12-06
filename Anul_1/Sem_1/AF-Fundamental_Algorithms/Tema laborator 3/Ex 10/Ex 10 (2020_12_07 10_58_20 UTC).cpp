#include <iostream>

using namespace std;

void Citire_Matrice_Patratica(int marime_matrice, int matrice[][100])
{
	for (int index_linie = 0; index_linie < marime_matrice; index_linie++)
		for (int index_coloana = 0; index_coloana < marime_matrice; index_coloana++)
			cin >> matrice[index_linie][index_coloana];
}

bool Verificare_Matrice(int marime_matrice, int matrice[][100])
{
	Citire_Matrice_Patratica(marime_matrice, matrice);
	int vector_frecventa[10000];
	for (int index = 0; index <= marime_matrice * marime_matrice - 1; index++)
		vector_frecventa[index] = 0;
	for (int index_linie = 0; index_linie < marime_matrice; index_linie++)
		for (int index_coloana = 0; index_coloana < marime_matrice; index_coloana++)
			vector_frecventa[matrice[index_linie][index_coloana]]++;
	for (int index = 0; index <marime_matrice * marime_matrice; index++)
		if (vector_frecventa[index] == 0)
			return false;
	return true;
}

int main()
{
	int n, matrice[100][100];
	cin >> n;
	if (Verificare_Matrice(n, matrice)) cout << "Matricea data contine toate numerele intre 0 si n^2-1. ";
	else cout << "Matricea data nu contine toate numerele intre 0 si n^2-1. ";
	return 0;
}
