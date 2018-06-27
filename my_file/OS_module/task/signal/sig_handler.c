#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void usr_1(int signor)
{
	printf("parent %d got SIGUSR!\n",getpid());
}

int main(void)
{
	pid_t pid;
	int status;
	int role = -1;

	pid = fork();
	if(pid > 0){
	printf("This is a parent process\n");

	signal(SIGUSR1,usr_1);

	role = 0;
	printf("Waiting for signal from child\n");
	pause();

	printf("Waiting child to exit\n");
	pid = wait(&status);
	}
	else if(pid == 0){
	printf("This is child process\n");
	role = 1;

	sleep(1);

	printf("child sending SIGUSR1 to parent\n");

	kill(getppid(),SIGUSR1);
	sleep(2);
	}

	printf("%s\tExiting\n",((role == 0)?"parent":"child"));
	return 0;
}


