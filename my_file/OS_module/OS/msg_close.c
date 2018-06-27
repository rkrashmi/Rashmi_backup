#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>

int main( int argc, char* argv[])
{
	if( argc == 1){
		printf("Input an option to send or receive\n");
		}
	else
	{
	
    mqd_t mqd;
    char *buf = NULL;
//    struct mq_attr attr;
    int st;
	int st1;
	char *buf2 = "send";
	char *buf1 = "receive";

    buf = (char *)malloc(8192);

    mqd = mq_open( "/mqueue1", O_CREAT | O_RDWR, 0777, NULL);
    if( mqd == -1){
        printf("Bad file descriptor\n");
        exit(EXIT_FAILURE);
         }
	while (1){
    if(!strcmp(argv[1], buf1)){
		printf("receiver:  ");
    	st = mq_receive( mqd, buf, 8192, 0);
    
		if(st == -1){
    	    perror("mq_receive failed\n");
      	    exit(EXIT_FAILURE);
       }
	
	printf("%s\n",buf);

	 printf("sender:  ");
       // printf("insert the msg\n");
        fgets(buf, 255, stdin);

        st1 = mq_send( mqd, buf, 8192 , 0);
        if(st1 == -1){
            perror("mq_send failed\n");
            exit(EXIT_FAILURE);
       }

	}

	else if(!strcmp(argv[1],buf2)){
		printf("sender:  ");
		//printf("insert the msg\n");
	    fgets(buf, 255, stdin);

	    st1 = mq_send( mqd, buf, 8192 , 0);
	    if(st1 == -1){
    	    perror("mq_send failed\n");
     	    exit(EXIT_FAILURE);
       		}
		sleep( 2 );
		printf("receiver:  ");
        st = mq_receive( mqd, buf, 8192, 0);

        if(st == -1){
            perror("mq_receive failed\n");
            exit(EXIT_FAILURE);
       }
		
		printf("%s\n",buf);
	 }
	}
	   mq_close( mqd );
    }
	return 0;
}

