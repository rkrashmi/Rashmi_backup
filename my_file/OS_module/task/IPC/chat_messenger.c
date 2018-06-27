#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 8192

int main ( void )
{
	mqd_t mqd;
	char *ptr;
	struct mq_attr attr;

	ptr = (char *)malloc(sizeof(char) * MAX);

	if( -1 == (mqd = mq_open( "/my_queue", O_CREAT | O_RDWR, 0777, NULL)))
		printf("open failed\n");
	while (1){
	if(mq_getattr( mqd, &attr )) {
		perror("mq_getattr error\n");
		exit(0);
	}
	fgets(ptr, 255, stdin);	
	printf("%s",ptr);
	if(-1 == (mq_send( mqd, ptr, attr.mq_msgsize, 0)))
		printf("send failed\n");
	mq_close( mqd );
	}
	return 0;
}

	
