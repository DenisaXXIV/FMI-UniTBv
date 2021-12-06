#include <iostream>

using namespace std;

void Citire_Numar(int numar[], int numar_de_cifre)
{
	for (int index = 0; index < numar_de_cifre; index++)
	{
		cin >> numar[index];
	}
}

void Inserare_o_Noua_Unitate_in_Numar(int numar[], int& numar_de_cifre, int unitate_noua)
{
	for (int index = numar_de_cifre - 1; index >= 0; index--)
	{
		numar[index + 1] = numar[index];
	}
	numar[0] = unitate_noua;
	numar_de_cifre++;
}

void Inmultire_Numar_cu_Numarul_Generat(int numar[], int& numar_cifre, int numar_generat)
{
	int transport = 0;
	for (int index = numar_cifre - 1; index >= 0; index--)
	{
		numar[index] = numar[index] * numar_generat;
		if (transport != 0)
		{
			numar[index] += transport;
			transport = 0;
		}
		if (numar[index] > 9)
			transport = numar[index] / 10;
		else transport = 0;
		numar[index] = numar[index] % 10;
	}
	if (transport != 0)
		Inserare_o_Noua_Unitate_in_Numar(numar, numar_cifre, transport);
}

void Afisare_Produs(int numar[], int numar_de_cifre, int numar_generat)
{
	Citire_Numar(numar, numar_de_cifre);
	Inmultire_Numar_cu_Numarul_Generat(numar, numar_de_cifre, numar_generat);
	for (int index = 0; index < numar_de_cifre; index++)
	{
		cout << numar[index];
	}

}

int main()
{
	int numar_cifre, numar[100], numar_generat;
	cin >> numar_cifre;
	//numar_generat = rand() % 9 + 1;
	numar_generat = 9;
	Afisare_Produs(numar, numar_cifre, numar_generat);
	return 0;
}