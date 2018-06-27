//prgm to find endianess of machine

#include<stdio.h>
int main(void)
{
	int a = 0x01;
	int  *ptr;
	ptr = &a;
	*ptr = a & 0x01;
	
	if( *ptr == 1)
		printf("Machine is Little Endian\n");
	else
		printf("Machine is Big Endian\n");
}
