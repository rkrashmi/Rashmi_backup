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
	while( 1 ){
    mq_getattr( mqd, &attr );
//    fgets(ptr, 255, stdin);
    if(-1 == mq_receive( mqd, ptr, attr.mq_msgsize, NULL))
		printf("receive failed\n");

	printf("%s\n",ptr);
	}

	mq_close( mqd );
    return 0;
}

    

