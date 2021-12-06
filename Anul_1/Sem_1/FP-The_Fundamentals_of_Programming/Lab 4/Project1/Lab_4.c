#include<stdio.h>
#include<malloc.h>

int getPrimaAparitie(char* s1, char* s2);

void main()
{
	//declarare variabile
	char* s1, * s2;
	int n = 30, m = 20;
	int x;

	//alocare memorie
	s1 = (char*)malloc(n * sizeof(char));

	if (s1 == NULL)
	{
		perror("Memorie insuficienta");
		exit(1);
	}

	s2 = (char*)malloc(m * sizeof(char));

	if (s2 == NULL)
	{
		perror("Memorie insuficienta");
		exit(1);
	}

	//citire date de intrare
	printf("Introduceti primul sir de caractere: ");
	gets(s1);

	printf("Introduceti al doilea sir de caractere: ");
	gets(s2);

	//calcul
	x = getPrimaAparitie(s1, s2);

	//afisare rezultate
	printf("%d", x);

	//eliberare memorie
	free(s1); free(s2);
}

int getPrimaAparitie(char* s1, char* s2)
{
	char* adr; int x;

	adr = strstr(strlwr(s1), strlwr(s2));

	if (adr == NULL)
	{
		
		return -1; 
	}

	x = adr - s1 + 1;

	return x;
}
