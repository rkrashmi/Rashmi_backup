#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/syscall.h>

int main ( void )
{
	pid_t pid;
	pid_t tgid;
	pid = fork();

	printf("after fork pid %d\n", getpid());

	if( pid > 0)
	{
		wait();
		printf("parent process\n");
		printf("pid = %d\n",pid);
		printf("pid in parent = %d\n",getpid());
		printf("tid in parent = %d\n",tgid);
		printf("ppid in parent = %d\n",getppid());
		getchar();
	}
	else if(pid == 0)
	{
		printf("child process\n");
		printf("pid = %d\n"
				"ppid in child = %d\n",getpid(), getppid());
		getchar();
//		printf("pid of child = %d\n",pid);
	//	printf("tid in child = %d\n",syscall(SYS_gettid));
	}
	else
	{
		printf("fork failed\n");
	}
	return 0;
} 
