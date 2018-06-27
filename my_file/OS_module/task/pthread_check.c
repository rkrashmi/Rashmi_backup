#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// pthread_mutex_t var = PTHREAD_MUTEX_INITIALIZER;


void * thread_1(void *p)
{
//	pthread_mutex_t var = PTHREAD_MUTEX_INITIALIZER;
//	pthread_mutex_lock(&var);

	printf("1i\t");
	printf("2i\t");
	printf("3i\t");
	printf("4i\t");
	printf("5i\t");
	printf("6i\t");
	printf("7i\t");
	printf("8i\t");
	printf("9i\t");
	fflush(stdout);
	sleep(3);
	printf("!!!!!\t");
	printf("10i\t");
	printf("11i\t");
    printf("12i\t");
    printf("13i\t");
    printf("14i\t");
    printf("15i\t");
    printf("16i\t");
    printf("17i\t");
    printf("18i\t");
    printf("19i\t");
    printf("20i\t");
//	pthread_mutex_unlock(&var);
}

void * thread_2 (void *p)
{
//	pthread_mutex_t var = PTHREAD_MUTEX_INITIALIZER;
  //  pthread_mutex_lock(&var);
//	sleep(2);
	printf("11\t");
	printf("12\t");
	printf("13\t");
	printf("14\t");
	printf("15\t");
	printf("16\t");
	printf("17\t");
	printf("18\t");
	printf("19\t");
	printf("20\t");
	printf("111\t");
    printf("112\t");
    printf("113\t");
    printf("114\t");
    printf("115\t");
    printf("116\t");
    printf("117\t");
    printf("118\t");
    printf("119\t");
    printf("120\t");

//	pthread_mutex_unlock(&var);
}

int main( void )
{
	pthread_t tid[2];

	pthread_create(&tid[0], NULL, thread_1, NULL);
//	sleep(1);
	pthread_create(&tid[1], NULL, thread_2, NULL);
//	sleep(2);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_exit(NULL);

	return 0;
}


