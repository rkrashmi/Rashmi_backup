#include<stdio.h>

int main()
{
	unsigned  int i;
	int num =5;
	for(i=31;i>0;i--)
	printf("%d",(num>>i)&1);
}
