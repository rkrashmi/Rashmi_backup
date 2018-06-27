#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <mqueue.h>

#define MAX 8192

int main( int argc, char *argv[] )
{
//	if(mq_unlink("/mqueue") == -1){
//		perror("unlink failed\n");
//		exit(EXIT_FAILURE);
//		}

	FILE *fp;	
	long int pos =0;
	int st;
	int rem;
	unsigned int i;

	mqd_t mqd;
	char *buf = NULL;
	struct mq_attr attr;
	
	buf = (char *)malloc(MAX);

	if(argc == 1){
		printf("No input file\n");
	}
	else
	{
		fp = fopen( argv[1], "r+");
		fseek( fp, 0, SEEK_END);
		pos = ftell(fp);
				printf("%ld\n",pos);
		rem = pos % 4;
		pos = pos/4;
				printf("%ld\n",pos);
				printf("%d\n",rem);
		rewind(fp);

		mq_unlink("/mqueue");	
		mqd = mq_open( "/mqueue", O_CREAT | O_RDWR, 0777, NULL);
		if( mqd == -1){
			printf("Bad file descriptor\n");
			exit(EXIT_FAILURE);
			}
		if((mq_getattr( mqd, &attr)) == -1){
			perror("mq_getattr failed\n");
			exit(EXIT_FAILURE);
			}


		for( i = 0; i < 4; i++){		
		
		fread( buf, pos, 1, fp );
				printf("%s\n",buf);

			printf("Sending message\n");
		st = mq_send( mqd, buf, attr.mq_msgsize , i);
			printf("msg sent\n");
		if(st == -1){
			perror("mq_send failed\n");
			exit(EXIT_FAILURE);	
			}
		}
		if(rem != 0 ){
			  fread( buf, rem, 1, fp );
                printf("%s\n",buf);
                printf("%d\n",rem);

			       printf("Sending message\n");
        st = mq_send( mqd, buf, attr.mq_msgsize , 5);
            printf("msg sent\n");
        if(st == -1){
            perror("mq_send failed\n");
            exit(EXIT_FAILURE);
            }
		}
	
		printf("%s\n",buf);
//		sleep( 2 );
		
		}
	getchar();

		mq_close( mqd );
		
		fclose(fp);
	
	
	return 0;
}
	
