// Laborator Prog Dinam 2 204.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int valoriObiecte[] = { 6, 10 ,12 };
int dimensiuniObiecte[] = { 1, 2, 3 };
int numarDeIteratii = 0;
vector<vector<int>> structuraTabelaraDeMemorie = vector<vector<int>>();

int GasireValoareMaximaMemoizare(int numarulDeObiecte, int capacitateaRucsacului) {
	numarDeIteratii++;
	if (numarulDeObiecte == 0 || capacitateaRucsacului == 0)
	{
		structuraTabelaraDeMemorie[numarulDeObiecte][capacitateaRucsacului] = 0;
		return 	structuraTabelaraDeMemorie[numarulDeObiecte][capacitateaRucsacului];
	}
	else if (structuraTabelaraDeMemorie[numarulDeObiecte][capacitateaRucsacului] != INT_MIN)
	{
		return 	structuraTabelaraDeMemorie[numarulDeObiecte][capacitateaRucsacului];
	}
	else if (capacitateaRucsacului < dimensiuniObiecte[numarulDeObiecte - 1])
	{
		structuraTabelaraDeMemorie[numarulDeObiecte][capacitateaRucsacului] = GasireValoareMaximaMemoizare(numarulDeObiecte - 1, capacitateaRucsacului);
	}
	else
	{
		structuraTabelaraDeMemorie[numarulDeObiecte][capacitateaRucsacului] = max(GasireValoareMaximaMemoizare(numarulDeObiecte - 1, capacitateaRucsacului), GasireValoareMaximaMemoizare(numarulDeObiecte - 1, capacitateaRucsacului - dimensiuniObiecte[numarulDeObiecte - 1]) + valoriObiecte[numarulDeObiecte - 1]);
	}
	return structuraTabelaraDeMemorie[numarulDeObiecte][capacitateaRucsacului];
}

void InitializareStructura(int numarulDeObiecte, int capacitateaRucsacului) {
	for (int i = 0; i <= numarulDeObiecte; i++)
	{
		structuraTabelaraDeMemorie.push_back(vector<int>());
		for (int j = 0; j <= capacitateaRucsacului; j++)
		{
			structuraTabelaraDeMemorie[i].push_back(INT_MIN);
		}
	}
}

int GasireValoareMaxima(int numarulDeObiecte, int capacitateaRucsacului) {
	InitializareStructura(numarulDeObiecte, capacitateaRucsacului);
	numarDeIteratii = 0;
	for (int i = 0; i <= numarulDeObiecte; i++)
	{
		structuraTabelaraDeMemorie[i][0] = 0;
		numarDeIteratii++;
	}
	for (int i = 0; i <= capacitateaRucsacului; i++)
	{
		structuraTabelaraDeMemorie[0][i] = 0;
		numarDeIteratii++;
	}

	for (int obiectulCurent = 1; obiectulCurent <= numarulDeObiecte; obiectulCurent++)
	{
		for (int capacitateaCurenta = 1; capacitateaCurenta <= capacitateaRucsacului; capacitateaCurenta++)
		{
			numarDeIteratii++;
			if (capacitateaCurenta < dimensiuniObiecte[obiectulCurent - 1])
			{
				structuraTabelaraDeMemorie[obiectulCurent][capacitateaCurenta] = structuraTabelaraDeMemorie[obiectulCurent - 1][capacitateaCurenta];
			}
			else
			{
				structuraTabelaraDeMemorie[obiectulCurent][capacitateaCurenta] =
					max(structuraTabelaraDeMemorie[obiectulCurent - 1][capacitateaCurenta],
						structuraTabelaraDeMemorie[obiectulCurent - 1][capacitateaCurenta - dimensiuniObiecte[obiectulCurent - 1]] + valoriObiecte[obiectulCurent - 1]);
			}
		}
	}

	return structuraTabelaraDeMemorie[numarulDeObiecte][capacitateaRucsacului];
}


int main()
{
	InitializareStructura(3, 5);
	cout << numarDeIteratii << " " << GasireValoareMaximaMemoizare(3, 5) << endl;
	std::cout << numarDeIteratii << " " << GasireValoareMaxima(3, 5);
}