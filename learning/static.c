#include <stdio.h>

//int *ptr;
/*
void fun(int b)
{
	int *ptr = NULL;
	
	ptr = &b;
	printf("*ptr = %d\n", *ptr);

}
*/


	
int main(void)
{
	int *ptr = NULL;
	{
	 auto int a = 2;
		
		ptr = &a;
		printf("a = %d\n", a);
	}
//	printf(" *ptr = %d\n", *ptr);
	fun(ptr);	
	return 0;
}
