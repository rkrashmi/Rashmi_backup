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

    buf = (char*)malloc(100);

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

	if( -1 == (dup2(pipefd[0],STDIN_FILENO))){
		perror("dup failed\n");
		exit( 0 );
		}
    if( -1 == (execlp("wc", "wc", "-l",NULL))){
		perror("exec failed\n");
		exit( 0 );
		}
	        
//        printf("%s\n",buf);
        close(pipefd[0]);

        }


    if( pid > 0 ){
        printf("In parent process\n");
        close(pipefd[0]);

    if( -1 == (dup2(pipefd[1],STDOUT_FILENO))){
        perror("dup failed\n");         
        exit( 0 );
        }

	if( -1 == (execlp("ls", "ls", NULL))){
        perror("exec failed\n");
        exit( 0 );
        }
	
		wait( NULL );

            
        close(pipefd[1]);

    }
    return 0;
}


