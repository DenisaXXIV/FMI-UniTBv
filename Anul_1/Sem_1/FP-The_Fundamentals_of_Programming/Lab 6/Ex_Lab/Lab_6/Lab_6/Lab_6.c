#include <stdio.h>
#include <malloc.h>
void main()
{
//declarare variabile
char numef[256];
FILE* fis;
char* s1;
int n;
//citesc datele de intrare - numele fisierului
printf("Introduceti numele (calea) fisierului: ");
gets(numef);
//citesc datele de intrare - nr de caractere ce se doresc a fi citite
printf("Introduceti nr de caractere pe care doriti sa le cititi din fisier:");
scanf("%d", &n);
getchar(); // ca sa nu imi ia enter-ul ca numef in gets-ul urmator
//deschidere fisier
fis = fopen(numef, "rb");
//verificarea deschiderii fisierului
if (fis == NULL)
{
printf("Fisierul %s nu a putut fi deschis!", numef);
exit(1);
}
//alocare memorie
s1 = (char*)malloc(n * sizeof(char));
if (s1 == NULL)
{
perror("Memorie insuficienta!");
exit(1);
}
//calcul
fgets(s1, n, fis);
//afisare rezultat
printf("Am citit din fisier: %s", s1);
//inchidere fisier
fclose(fis);
//eliberare memorie
free(s1);
}