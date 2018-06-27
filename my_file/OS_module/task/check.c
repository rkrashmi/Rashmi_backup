#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int i;
void * th_1 ( void *p)
{
//	int i = 0;
	++i;
	printf("value in th_1 = %d\n",i);
	return;
}
	
int main( void )
{
	pthread_t pt;

	

	pt = pthread_create(&pt, NULL, th_1, NULL); 
	
	if(pt > 0)
	{
		printf("thread created\n");
	}
	else
	{ 
		printf("error\n");
	}
	
	//pthread_exit(NULL);
	return 0;
}
		
