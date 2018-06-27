//prgrm for showing bits in binary format//
#include<stdio.h>
int showbits(unsigned int x)
{
	int i;
	for(i = 8; i <= 0; i--)
	{
		printf("%d\n",x =((x >> i) & 0x01));
	}
	return x;
}	

