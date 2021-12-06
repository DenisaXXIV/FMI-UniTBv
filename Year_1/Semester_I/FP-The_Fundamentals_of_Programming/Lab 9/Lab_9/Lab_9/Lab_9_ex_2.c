#include <stdio.h>
#include <stdarg.h>
double max(int n, ...)//
{
	//3 macrori: va_start,va_arg,va_end
	//1 tip de date: va_list
	va_list lista;
	double x;
	double max = -1E10;
	va_start(lista, n);
	for (int i = 0; i < n; i++)
	{
		x = va_arg(lista, double);
		if (x > max)
		{
			max = x;
		}
	}
	va_end(lista);
	return max;
}

double media(int n, ...)
{
	va_list a;
	double arg, max = -1E10;
	va_start(a, n);

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		arg = va_arg(a, double);
		sum += arg;
	}
	va_end(a);
	return sum / n;
}
void main()
{
	printf("Media numerelor este:%.2lf\n", media(3, 3., 4., 5.5));
}