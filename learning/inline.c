#include<stdio.h>
//#define add(a,b)(a+b)

int add( int a, int b)
{
	return a + b;
}

int main()
{
	int a=1;
	int b=2;
	int c;
	c = add(a,b);
	printf("c is %d\n",c);
	return 0;

	
	
}


