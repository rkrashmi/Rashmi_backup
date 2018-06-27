#include <stdio.h>
void fun(void);
int main(void)
{
	int a = 100;
	fun();
	printf("%d\n",a);
	return 0;
}





void fun(void)
{
	int *ptr;
	int i;
	ptr = &i;
	while(*ptr != 100){
		ptr++;
		}
	*ptr = 200;

}
