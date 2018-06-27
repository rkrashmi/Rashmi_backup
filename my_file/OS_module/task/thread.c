#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

void * thread_func_2(void *p);
void * thread_func_3(void *p);
void * thread_func_4(void *p);

void * thread_func_1(void *p)
{
	
	pthread_t thread_id;
	printf("am\n");
	pthread_create(&thread_id, NULL , thread_func_2, NULL);
	
	return;
}
void * thread_func_2(void *p)
{
	printf("at\n");
	pthread_t thread_id;
	pthread_create(&thread_id, NULL , thread_func_3, NULL);
	return;
}

void * thread_func_3(void *p)
{
	pthread_t thread_id;
	printf("the\n");
	pthread_create(&thread_id, NULL , thread_func_4, NULL);
	return;
}
void * thread_func_4(void *p)
{
	//pthread_t thread_id;
	printf("edge\n");
	return;
}
int main( void )
{
	pthread_t thread_id;

	printf("I\n");

	pthread_create(&thread_id, NULL , thread_func_1, NULL);
/*	pthread_create(&thread_id, NULL , thread_func_2, NULL);
	pthread_create(&thread_id, NULL , thread_func_3, NULL);
	pthread_create(&thread_id, NULL , thread_func_4, NULL);
//	getchar();
//	getchar();*/
	//pthread_exit(NULL);
//	printf("I\n");
	pthread_exit(NULL);

	return 0;
} 
	
