#include <stdio.h>
#include <stdarg.h>
union tpers
{
	char serieid[9];
	char cnp[14];
};
typedef union tpers tpers;
void main()
{
	int op;
	tpers pers;
	op = -1;
	printf("Ce doriti sa introduceti? 1- Serie sau 2-Cnp: ");
	scanf_s("%d", &op);
	getchar();
	switch (op)
	{
	case 1:puts("Serie buletin:");
		gets(pers.serieid);
		puts("Am citit:");
		printf("Serie Id: %s\n", pers.serieid);
		break;
	case 2:
		printf("Cnp: ");
		gets(pers.cnp);
		printf("Am citit Cnp: %s\n", pers.cnp);
		break;
		
	default:
		break;
	}
	

	
	
}