#include <stdio.h>

int (*fptr)(const char* ,...);

int main( void )
{
	int buf;

	fptr = printf;

	fptr("Rashmi");
	//printf("%d\n",buf);

	return 0;
}		
