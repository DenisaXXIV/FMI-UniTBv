#include <iostream>

using namespace std;
void Citire_Medii(int interval[], int numar_de_elemente)
{
	float medie;
	for (int index1 = 0; index1 < numar_de_elemente; index1++)
	{
		cin >> medie;
		if ((int)medie == medie)
			interval[(int)medie]++;
		else
			interval[(int)medie + 1]++;
	}
}

void Statistica_Medii(int numar_de_elemente)
{
	int interval_medii[15] = { 0 };
	Citire_Medii(interval_medii, numar_de_elemente);
	cout << "Numarul de medii cuprinse in intervalul [ " << 1 << " , " << 2 << " ] este " << interval_medii[1] + interval_medii[2] << endl;
	for (int index2 = 2; index2 < 10; index2++)
	{
		cout << "Numarul de medii cuprinse in intervalul ( " << index2 << " , " << index2 + 1 << " ] este " << interval_medii[index2 + 1] << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	Statistica_Medii(n);
	return 0;
}
