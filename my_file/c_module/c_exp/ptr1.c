//checking normal assignment operator on pointer//
#include<stdio.h>
void main()
{
	int n = 10;
	int *p1 = &n;
	int *p2;
 	p2 = p1;

	printf("%d%d\n",*p2,*p1);
    printf("%x\n%x\n",(unsigned int)&n,(unsigned int)p1);
}
