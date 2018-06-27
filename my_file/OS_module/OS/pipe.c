#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main( void )
{
	char *buf = NULL;
	pid_t pid;
	int pipefd[2];
	int fd;

	buf = (char*)malloc(20);

	 if(-1 == pipe(pipefd)){
        perror("pipe failed\n");
        exit(EXIT_FAILURE);
        }

	
	pid = fork();
	if( pid == -1 ){
		perror("fork failed\n");
		exit(EXIT_FAILURE);
		}

	if( pid == 0 ){
		printf("In child process\n");
		close(pipefd[1]);
	//	fgets(buf,50,stdin);

		read(pipefd[0], buf, 50);
		printf("%s\n",buf);		
		close(pipefd[0]);
 
		}
		

	if( pid > 0 ){
		printf("In parent process\n");
		close(pipefd[0]);
	
	//	fgets(buf,50,stdin);
		write(pipefd[1], buf, 50);
		close(pipefd[1]);	

	}
	return 0;
}
	
		
