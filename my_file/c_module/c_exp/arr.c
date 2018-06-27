
#include<stdio.h>
int main(void)
{
	float x = 50.0;
	char *ptr = NULL;
	char y;
	y = (char)x;
	printf("%c\n",y);
	ptr = &y;
//	ptr = &x;
	printf("%c\n",*ptr);
//	printf("%f\n %p\n", x , ptr);
	return 0;
}

