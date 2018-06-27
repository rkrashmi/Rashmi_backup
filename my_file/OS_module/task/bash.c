#include <stdio.h>

int main( void )
{
	printf("pid = %d\n",getpid());
	printf("ppid = %d\n",getppid());
	getchar();

	return 0;
}
