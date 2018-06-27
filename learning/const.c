#include <stdio.h>
// int a = 10;
//extern volatile int a;
const volatile int a = 56;
int main (void)

{
	const int z = 10;
	//static int * ptr = NULL;
//	a = 20;
	int *ptr;
	volatile int g = 46;
	printf( "a = %d\n", a);
	static int x = 28;
	ptr = &a;
	*ptr = 20;
//	a =99;
	//printf( "a = %d\n", *ptr);
	printf( "a = %d\n", a);
	return 0;
}
