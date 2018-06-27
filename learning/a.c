#include <stdio.h>

const volatile int a = 4;
int main (void)
{
//	a = 45;
//	int *ptr = &a;
	
//	*ptr = 20;
	 printf("%d\n",(*ptr)++);

	printf("a = %d\n",a);
	fun();
	printf("%d\n",a);
	return 0;
}
