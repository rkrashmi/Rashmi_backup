#include"header.h"

int count_bit(num1, num2, n)
{
 	int i;
	int count = 0;
	int n1;
	int n2;
	for(i = 0; i < n; i++)
	{
		n1 = ((num1 >> i) & 0x01);
		n2 = ((num2 >> i) & 0x01);
		if( n1 != n2)
		{
			count++;
		}
	}
	return count;
	
}
