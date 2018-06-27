#include"header.h"
int cnt_trailing_cleared_bits(num,n)
{
    int clear;
	int i;
	int count;
	for(i = 1; i <= n; i++){
    clear = (num & 0x01);
    if(clear == 0)
    {
       count++;
    }
	 else
    {
     exit(0);
    }
	}
    return count;
}

