#include <stdio.h>

int main (void )
{

	char *p = "hello";

	*(p+2) = 's';
	printf("%s\n",p);
	return 0;
}
