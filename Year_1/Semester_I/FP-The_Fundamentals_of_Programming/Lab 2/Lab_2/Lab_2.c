#include <stdio.h>
#include <malloc.h>


// In curs se gaseste la pagina


//malloc (10 * 4) = 40 octeti sizeif(int) = 4;
//calloc (10, 4) = 40 octeti (n, sizeof(int))
//realloc (a, )

int n;
int* a;

void main()
{
	n = 10;

	a = (int*)malloc(n * sizeof(int));

	if (a == NULL)
	{
		perror("Memorie inficienta");
		exit(1);
	}


	for (int i = 0; i < n; i++)
	{
		printf("a[%d]= ", i);
		scanf_s("%d", &a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}

}
