#include <stdio.h>
#include <pthread.h>

pthread_mutex_t var1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t var2 = PTHREAD_MUTEX_INITIALIZER;

int g_var;

void *th_1(void *p)
{
	pthread_mutex_lock(&var1);
	
	if( g_var <= 100)
	++g_var;

	pthread_mutex_unlock(&var1);
	return;
}

void *th_2(void *p)
{
	pthread_mutex_lock(&var2);
	
	printf("g_var = %d\n",g_var);

	pthread_mutex_unlock(&var2);

	return;
}



int main ( void )
{

	pthread_t tid_1;
	pthread_t tid_2;

	pthread_create(&tid_1, NULL, th_1, NULL);

	pthread_create(&tid_2, NULL, th_2, NULL);

	pthread_exit(NULL);

	return 0;
}		
