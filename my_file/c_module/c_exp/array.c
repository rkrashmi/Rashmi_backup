#include<stdio.h>
unsigned int a[2][3] = {
				{1,2},
				{3,4}
				};
int main()
{
	printf("&a =%u\n",&a);
	printf("a = %u\n",a);
	printf("*a = %u\n",*a);

	printf("&a+1 = %u\n",&a+1);
	printf("a+1 = %u\n",a+1);
	printf("*a+1 = %u\n",*a+1);
	return 0;
}
