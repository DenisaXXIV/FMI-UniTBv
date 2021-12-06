#include <stdio.h>
#include<malloc.h>

typedef struct tcoada tcoada;

struct tcoada
{
	char info;
	tcoada* leg;
}*cap, * coada;

void afisare()
{
	printf("Coada contine urmatoarele elemente: ");
	tcoada* p = cap;
	while (p != NULL)
	{
		printf("%c", p->info);
		p = p->leg;
	}
	printf("\n");
}

int introducere(char c)
{
	tcoada* p;

	p = (tcoada*)malloc(sizeof(tcoada));
	if (p == NULL)
	{
		return 0;
	}
	p->info = c;
	p->leg = cap;
	cap = p;
	if (coada == NULL)
	{
		coada = cap;
	}

	return 1;
}

int scoatere()
{
	tcoada* p = cap;
	if (p == NULL) {
		return 0;
	}
	if (cap == coada)
	{
		free(coada);
		cap = NULL;
		coada = NULL;
		return 1;
	}
	while (p->leg != coada)
	{
		p = p->leg;
	}
	coada = p;

	free(coada->leg);
	coada->leg = NULL;
	return 1;
}

void main()
{
	int op;
	char c;
	op = -1;
	do
	{
		printf("Introduceti: \n");
		printf("1 pentru introducere in coada \n");
		printf("2 pentru scoatere din coada \n");
		printf("3 pentru afisarea cozii \n");
		printf("0 pentru iesire din program \n");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 1:
		{
			printf("Introduceti un caracter: ");
			scanf_s("%c", &c);
			if (introducere(c))
			{
				printf("Am introdus caracterul %c in coada\n", c);
			}
			break;
		}
		case 2:
		{
			if (scoatere())
			{
				printf("Am scos un element din coada\n");
			}
			break;
		}
		case 3:
		{
			afisare();
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			printf("Va rugam sa introduceti 1, 2, 3 sau 0");
			break;
		}
		}
	} while (op != 0);
}