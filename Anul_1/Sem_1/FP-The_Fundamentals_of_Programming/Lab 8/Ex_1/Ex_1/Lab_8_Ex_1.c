#include <stdio.h>
#include <malloc.h>

struct tpers
{
	char nume[50];
	int v;
};

typedef struct tstiva tstiva;

struct tstiva
{
	char info;
	tstiva* leg;
}; *cap;

typedef int intreg;

typedef struct tpers tpers;

void afisare()
{
	tstiva* p = cap;
	printf("Stiva contine urmatoarele elemente: ");
	while (p != NULL)
	{
		printf("%c", p->info);
		p = p->leg;
	}
	printf("\n");
}

int introducere(char c)
{
	tstiva* p;
	p = (tstiva*)malloc(sizeof(tstiva));

	if (p == NULL)
	{
		exit(0);
	}

	p->info = c;
	p->leg = cap;
	cap = p;
	return 1;
}

int scoatere()
{
	tstiva* p;
	if (cap == NULL)
		return 0;
	p = cap;
	cap = p->leg;
	free(p);
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
		printf("1 pentru introducere in stiva \n");
		printf("2 pentru scoatere din stiva \n");
		printf("3 pentru afisarea stivei\n");
		printf("0 pentru iesire din program\n");

		scanf("%d", &op);
		getchar();
		switch (op)
		{
		case 1:
		{
			scanf("%c", &c);
			if (introducere(c))
			{
				printf("Am introdus caracterul %c in stiva\n", c);
			}
			break;
		}
		case 2:
		{
			if (scoatere())
				printf("Am scos un element din stiva\n");
			break;
		}
		case 3:
		{
			afisare();
			break;
		}
		case 0:
			break;
		default:
		{
			printf("Va rugam sa introduceti 1,2,3 sau 0");
			break;
		}
		}
	} while (op != 0);
	printf("Introduceti un caracter ");
	scanf("%c", &c);


	//struct tpers pers;
	//tpers *p;

	//p = (tpers*)malloc(sizeof(tpers));
	//if (p == NULL)
	//{
	//	perror("Memorie insuficienta");
	//	exit(1);
	//}

	//citire date de intrare
	//intreg v;
	//scanf("%d", &v);

	//printf("Nume: ");
	//gets(p->nume);

	//printf("Varsta ");
	//scanf("%d", &p->v);
	//afisare
	//printf("Am citit: %s \n",p->nume);
	//printf("Am citit: %d ", p->v);

	//pers.nume

	//pers.v;
}