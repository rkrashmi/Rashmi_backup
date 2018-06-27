// prgrm to design 8-bit twisted ring counter//
#include"header.h"
int main()
{
    int i;
	int set;
	int j;
	unsigned int x = 0x00;
    printf("Twisted ring counter is:\n");
	for(i = 0; i < 2; i++)
	{
		set = 0x01 << 8;
		for(j = 0; j < 8; j++)
		{
		   showbits(x);
		  // printf("%u\n",x);
			x = (x ^ (set >> j));
		}
	}
	return 0;
}

