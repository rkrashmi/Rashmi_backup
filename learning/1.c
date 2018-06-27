#include<stdio.h>

int* fun (int, int);
int main()
{

	int a = 1;
	int b = 2;
	int c;

	fun(a, b);	
//	c = a++ + ++b;

	printf("c = %d\n",c);

return ;
}

int* fun(int a, int b)
{
	int* p;
	int c;
	c = a++ + ++b;
	p = &c;
	*p = c;
//	return;
}
