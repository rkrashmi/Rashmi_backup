#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>

void func(void);
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * th_1(void * p)
{
	//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_lock(&lock);
	printf("thread ID: %d\n", syscall(SYS_gettid));
	sleep(2);
	func();
	pthread_mutex_unlock(&lock);
	return;
}

//void * th_2	
int main(void)
{
	pthread_t tid[2];

	pthread_create(&tid[0], NULL, th_1, NULL);
	pthread_create(&tid[1], NULL, th_1, NULL);

	pthread_exit(0);
}

void func(void)
{
	int i = 0;
	for (i = 0; i < 20; i++) {
		printf("%d (%d)\n", i, syscall(SYS_gettid));
	}
}
