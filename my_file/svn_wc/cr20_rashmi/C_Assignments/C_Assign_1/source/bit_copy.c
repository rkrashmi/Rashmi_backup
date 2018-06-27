// function to copy the n bits from one number to another number//
#include"header.h"

int bit_copy(snum,dnum,s_pos,d_pos,n)
{
	int dig2;
	int dig1;
	int i;
	for(i = 0; i < n; i++) {
		dig1 = (snum >> (s_pos - (n-1))) & ((1 << n) -1);
		dig2 = (dnum >> (d_pos - (n-1))) & ((1 << n) -1);
		if(dig1 != dig2)
		{
			if(s_pos < d_pos) {
			dnum = (1 << d_pos) ^ dnum;
			}
			else 
			{
				printf("data will be lost");
			}
		}
			s_pos--;
			d_pos--;
	}
	return dnum;
}

	
