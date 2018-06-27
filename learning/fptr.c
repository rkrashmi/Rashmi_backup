#include <stdio.h>
#include <stdlib.h>

int (*fptr[2])(int , int);
//int (*fptr1)(int, int, int);

//int sub(int, int, int);

int add(int a, int b)
{
	int sum;
//	int subb;

	sum = a + b;
//	subb = sub(a, b);
	
//	printf("sub in add func = %d\n",subb);

	return sum;
}

int sub(int a, int b, int (*fptr)(c, d))
{
	int sub;
	int addd;

	sub = a - b;
	addd = (*fptr[0])(a , b);
	
	printf("add in sub fun =%d\n", addd);

	return sub;
}


int main( void )
{
	 fptr[0] = add;
	 fptr[1] = sub;

	int a = 10;
	int b = 20;

	int c;
	int d;
	c = (*fptr[0])(a, b);
	printf("sum = %d\n", c);

	d = (*fptr[1])(a, b);
	printf("sub = %d\n", d);

	return 0;
}

