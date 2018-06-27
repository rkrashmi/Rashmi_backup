//typecasting//
#include<stdio.h>
void main()
{
	char *p;
	int n = 0x5042;
	p = (char *)&n;

	printf("%c\n%c\n",*p,(unsigned int)p);
}
