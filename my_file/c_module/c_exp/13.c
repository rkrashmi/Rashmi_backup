#include <stdio.h>
extern const int a;
void fun (void);
int main(void)
{
//	a = 10;
	printf("%d\n",a);
	fun1();
	fun();
	return 0;
}

void fun()
{
//	a = 10;
	printf("a = %d\n",a);
	return;
}

