void Interschimbare(int& numar1, int& numar2)
{
	int numar_auxiliar;
	numar_auxiliar = numar1;
	numar1 = numar2;
	numar2 = numar_auxiliar;
}

int Separare(int matrice[][100], int index_coloana, int prima_pozitie, int ultima_pozitie)
{
	int pivot = matrice[ultima_pozitie][index_coloana];
	int index_element_mai_mic = prima_pozitie - 1;
	for (int index = prima_pozitie; index < ultima_pozitie; index++)
	{
		if (matrice[index][index_coloana] <= pivot)
		{
			index_element_mai_mic++;
			Interschimbare(matrice[index_element_mai_mic][index_coloana], matrice[index][index_coloana]);
		}
	}
	Interschimbare(matrice[index_element_mai_mic + 1][index_coloana], matrice[ultima_pozitie][index_coloana]);
	return index_element_mai_mic + 1;
}

void QuickSort(int matrice[][100], int index_coloana, int prima_pozitie, int ultima_pozitie)
{
	if (prima_pozitie < ultima_pozitie)
	{
		int index_separat = Separare(matrice, index_coloana, prima_pozitie, ultima_pozitie);
		QuickSort(matrice, index_coloana, prima_pozitie, index_separat - 1);
		QuickSort(matrice, index_coloana, index_separat + 1, ultima_pozitie);
	}
}