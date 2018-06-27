#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signum,siginfo_t *p,void *q)
{
	printf("Hai \n");

	pid_t pid = p -> si_pid;
	printf("process issued signal : %d\n",pid);
	
	printf("signal number: %d\n",signum);	
	printf("signal number : %d\n",p -> si_signo);

}

int main(void)
{
	struct sigaction *sig;

	sig -> sa_sigaction = &sig_handler;

	sigaction(SIGINT,sig,NULL);

	printf("Helllllllllllo\n");
	printf("process pid: %d\n",getpid());

	pause();
	
	return 0;
}
