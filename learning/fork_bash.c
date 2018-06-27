#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	
//	printf("In main\n");
	pid = vfork();
	
	if(pid == 0)
	{
		int i;
//		char *args[] = {argv[1], argv[2], argv[3]};
		char *args[argc];
		for(i = 0; i < argc; i++)	
		{
			args[i] = argv[i+1];
		}
		printf("\n");
		execvp(*args, args);
//		execvp(argv[2], args);
//		printf("\n\n");
		
	}
	
	return 0;
}
