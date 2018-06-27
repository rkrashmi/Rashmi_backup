#include <stdio.h>

int g_var = 100;

void fun(void);

int main(void)
{
	int *ptr = NULL;

	ptr = &g_var;

	printf("%p\n",ptr);

	fun();

	return 0;
}
