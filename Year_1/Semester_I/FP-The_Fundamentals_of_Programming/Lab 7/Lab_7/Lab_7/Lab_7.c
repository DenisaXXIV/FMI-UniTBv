
#include <stdio.h>
#include <malloc.h>

float med(float** a, int m, int n);
float** alocare(float** a, int m, int n);


void main()
{
	//declarare variabile
	char numef[256];
	FILE* fis;
	float** a;
	int m, n;
	float s;

	//citesc datele de intrare - numele fisierului
	printf("Introduceti numele (calea) fisierului: ");
	gets(numef);
	//deschidere fisier
	fis = fopen(numef, "rb");

	//verificarea deschiderii fisierului
	if (fis == NULL)
	{
		printf("Fisierul %s nu a putut fi deschis!", numef);
		exit(1);
	}

	//citesc datele de intrare - nr de caractere ce se doresc a fi citite
	scanf("%d""%d", &m, &n);


	//alocare memorie
	a = alocare;

	for (int i = 0; i < m; i++)
	{
		a[i] = (float**)calloc(n, sizeof(float*));
		if (a[i] == NULL)
		{
			perror("Memorie insuficienta!");
			exit(1);
		}
	}
	//citire matrice din fisier
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf("%.2f", &a[i][j]);
		}
	}

	//calcul
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s += a[i][j];
		}
	}


	//afisare rezultat
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%f", a[i][j]);
		}
		puts(" ");
	}

	printf("Media elementelor dim matrice este: "%.2f", med);


	//inchidere fisier
	fclose(fis);

	//eliberare memorie
	for (int i = 0; i < m; i++)
	{
		free(a[i]);
	}
	free(a);
}

float med(float** a, int m, int n)
{
	float s = 0;
	return s / (m * n);
}

float** alocare(float** a, int m, int n)
{
	a = (float**)calloc(m, sizeof(float*));
	if (a == NULL)
	{
		perror("Memorie insuficienta!");
		exit(1);
	}
}