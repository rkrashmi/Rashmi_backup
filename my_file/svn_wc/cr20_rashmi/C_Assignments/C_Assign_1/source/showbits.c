// program to convert decimal to binary//
#include"header.h"

void showbits(unsigned int x)
{
	int i;
	for(i = 31; i > 0; i--)
	{
		printf("%d",(x >> i) & 0x01);
	}
		printf("\n");
}
