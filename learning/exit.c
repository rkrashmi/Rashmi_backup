#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	
	printf("hello\n");
	printf("world");
	
	sleep(2);
	
	_exit(0);
}
