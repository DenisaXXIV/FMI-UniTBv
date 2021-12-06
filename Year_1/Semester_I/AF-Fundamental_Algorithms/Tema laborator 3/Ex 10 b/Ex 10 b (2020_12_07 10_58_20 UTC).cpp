#include <iostream>

using namespace std;

void Citire_Matrice_Patratica(int marime_matrice, int matrice[][100])
{
	for (int index_linie = 0; index_linie < marime_matrice; index_linie++)
		for (int index_coloana = 0; index_coloana < marime_matrice; index_coloana++)
			cin >> matrice[index_linie][index_coloana];
	cout << endl;
}

void Interschimbare(int& numar1, int& numar2)
{
	int numar_auxiliar = numar1;
	numar1 = numar2;
	numar2 = numar_auxiliar;
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
	for (int index = 0; index < marime_matrice * marime_matrice; index++)
		if (vector_frecventa[index] == 0)
			return false;
	return true;
}

void Generare_Matrici(int marime_matrice, int matrice[][100], int linie, int coloana)
{
	if (linie - 1 >= 0)
	{
		Interschimbare(matrice[linie][coloana], matrice[linie - 1][coloana]);
		for (int index_linie = 0; index_linie < marime_matrice; index_linie++)
		{
			for (int index_coloana = 0; index_coloana < marime_matrice; index_coloana++)
				cout << matrice[index_linie][index_coloana] << " ";
			cout << endl;
		}
		cout << endl;
		Interschimbare(matrice[linie][coloana], matrice[linie - 1][coloana]);
	}
	if (linie + 1 < marime_matrice)
	{
		Interschimbare(matrice[linie][coloana], matrice[linie + 1][coloana]);
		for (int index_linie = 0; index_linie < marime_matrice; index_linie++)
		{
			for (int index_coloana = 0; index_coloana < marime_matrice; index_coloana++)
				cout << matrice[index_linie][index_coloana] << " ";
			cout << endl;
		}
		cout << endl;
		Interschimbare(matrice[linie][coloana], matrice[linie + 1][coloana]);
	}
	if (coloana - 1 < marime_matrice)
	{
		Interschimbare(matrice[linie][coloana], matrice[linie][coloana - 1]);
		for (int index_linie = 0; index_linie < marime_matrice; index_linie++)
		{
			for (int index_coloana = 0; index_coloana < marime_matrice; index_coloana++)
				cout << matrice[index_linie][index_coloana] << " ";
			cout << endl;
		}
		cout << endl;
		Interschimbare(matrice[linie][coloana], matrice[linie][coloana - 1]);
	}
	if (coloana + 1 >= 0)
	{
		Interschimbare(matrice[linie][coloana], matrice[linie][coloana + 1]);
		for (int index_linie = 0; index_linie < marime_matrice; index_linie++)
		{
			for (int index_coloana = 0; index_coloana < marime_matrice; index_coloana++)
				cout << matrice[index_linie][index_coloana] << " ";
			cout << endl;
		}
		cout << endl;
		Interschimbare(matrice[linie][coloana], matrice[linie][coloana + 1]);
	}
}

void Cautare_Zero(int marime_matrice, int matrice[][100])
{
	int linie_zero, coloana_zero;
	for (int index_linie = 0; index_linie < marime_matrice; index_linie++)
		for (int index_coloana = 0; index_coloana < marime_matrice; index_coloana++)
			if (matrice[index_linie][index_coloana] == 0)
			{
				linie_zero = index_linie;
				coloana_zero = index_coloana;
			}
	Generare_Matrici(marime_matrice, matrice, linie_zero, coloana_zero);
}

int main()
{
	int n, matrice[100][100];
	cin >> n;
	if (Verificare_Matrice(n, matrice)) Cautare_Zero(n, matrice);
	else cout << "Matricea data nu contine toate numerele intre 0 si n^2-1. ";
	return 0;
}
