#include"header.h"
int cnt_leading_set_bits(num,n)
{
    int set;
	int i;
	int count;
	for(i = 1; i <= n; i++){
    set  = (num & (0x01 << (n-i)));
    if(set == 1)
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

                                                                                                                                           
                                                                                                                                                      