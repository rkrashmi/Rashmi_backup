#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void catch_ctlc(int signor)
{
	printf("Segfalult is generated!!!\n");
//	printf("caught control + c\n");
	fflush(stdout);
	exit(0);	
	return;
}

int main(void)
{
//	signal(2,catch_ctlc);
	signal(SIGSEGV, catch_ctlc);

	printf("Go ahead,Make ur day\n");

	int *p = NULL;
	printf("%d\n",*p);

	pause();

	return 0;
}
