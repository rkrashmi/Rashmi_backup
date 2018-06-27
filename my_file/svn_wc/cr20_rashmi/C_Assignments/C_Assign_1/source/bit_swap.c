//swapping the bits in two different numbers//
#include"header.h"

void bit_swap(snum,dnum,s_pos,d_pos)
{
	int bit1;
	int bit2;
	int swap;
	int swap_m1;
	int swap_m2;
	
	bit1 = ((snum >> s_pos) & 0x01);
	bit2 = ((dnum >> d_pos) & 0x01);

	swap = bit1 ^ bit2;
	
	swap_m1 = ((swap << s_pos) ^ snum);
	swap_m2 = ((swap << d_pos) ^ dnum);
	
	printf("output after swapping =%d", swap_m1);
	printf("output after swaping = %d",swap_m2);
} 
