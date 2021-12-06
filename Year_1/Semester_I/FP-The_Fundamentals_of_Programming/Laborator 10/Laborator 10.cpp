#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fnc(void) {
	int x = 1;
	x++;
	printf("%d", x);
}

int main()
{
	for (int i = 0; i < 3; i++) {
		fnc();
	}

	/*
	int a, b;
	a = 1;
	b = a++;
	printf("%d%d",a,b)
	*/
	/*
	FILE* fis;
	char c;
	char numef[256];

	printf("Introduceti calea: ");
	scanf("%s", numef);

	fis = fopen(numef, "ab+");

	if (fis == NULL)
	{
		fprintf(stderr, "Eroare deschidere fisier.\n");
		return 1; // fluxul standard de erori
	}
	fprintf(fis, "%d", 'A');
	/*
	while (fread(&c, 1, 1, fis) != NULL) // citire caracter din fisier
		fprintf(stdout, "%c", c); // trimitere la monitor, pentru imprimanta stdprn

	fclose(fis);
	*/
	return 0;
}