#include <stdio.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <unistd.h>

void *func(void *p)
{
	pid_t tid;
	printf("pid = %d\n",getpid());	
	tid = syscall(SYS_gettid);
	
	printf("pthread_self = %u\n", pthread_self);
	printf("tid = %d\n", tid);
	
	getchar();
	return ;
}

int main(void)
{
	pthread_t no;
	
	printf("no = %u\n", no);
	pthread_create(&no, NULL, func, NULL);
	
	pthread_exit(NULL);
}
