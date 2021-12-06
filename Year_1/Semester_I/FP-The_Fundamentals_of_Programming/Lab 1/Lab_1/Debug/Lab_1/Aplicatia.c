#include <stdio.h>

int isMajor(int n)
{
	if (n < 18) {
		return 0;
	}
	return 1;
}


float medie(float x, float y) {
	return (x + y) / 2;
}



void main() {

	/*Declarare variabile*/
	int v;
	char nume[20];
	float r;
	float a;
	float b;

	/*Citirea datelor de intrare*/
	printf("Introduceti numele dumneavoastra:");
	scanf_s("%s", nume, sizeof(nume));

	printf("Introduceti varsa dumneavoastra:");
	scanf_s("%d", &v);

	printf("Introduceti primul nr:");
	scan_f("%f", &a);

	printf("Introduceti al doilea nr:");
	scan_f("%f", &b);



	/*Calcule*/
	if (!isMajor(v)) {
		return 0;
	}


	r = medie(a, b);


	/*Afisare rezultat*/
	printf("Hello, %s! Ai %d ani!", nume);

	printf("Media dintre %.2f si %.2f este :%.2f", a, b, r);
}
