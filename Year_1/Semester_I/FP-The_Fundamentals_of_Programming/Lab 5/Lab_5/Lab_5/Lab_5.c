#include <stdio.h>
#include <malloc.h>
void main()
{

	char numef[256];
	FILE* fis;
	char* s1;
	int n;

	printf("Introduceti numele (calea) fisierului: ");
	gets(numef);



	printf("Introduceti nr de caractere pe care doriti sa le cititi din fisier:");
	scanf("%d", &n);
	getchar();
	fis = fopen(numef, "rb");

	if (fis == NULL)
	{
		printf("Fisierul %s nu a putut fi deschis!", numef);
		exit(1);
	}

	s1 = (char*)malloc(n * sizeof(char));
	if (s1 == NULL)
	{
		perror("Memorie insuficienta!");
		exit(1);
	}

	fgets(s1, n, fis);

	printf("Am citit din fisier: %s", s1);

	fclose(fis);

	free(s1);
}