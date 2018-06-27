#include <stdio.h>

int fun(int, int);

int main ( void )
{
	int a = 10;
	int b = 20;
	int sum;
	
	sum = fun(a, b);
	printf("%d\n", sum);

	return 0;
}

int fun(int a, int b)
{
	int sum;
	a++;
	b--;
	sum = a + b;
	printf("sum in fun %d\n", sum);
	return sum;
}

