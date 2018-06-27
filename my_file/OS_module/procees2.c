#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <pthread.h>


FILE *fp=NULL;
int cnt=0;
pthread_mutex_t var = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int x = 0;

mqd_t mqdes;
struct mq_attr attr;
int st;
int pos = 6;
char buf[1024];


void* th_1(void *p)
{
	pthread_mutex_lock( &var );

	while( x != 0 ){
		pthread_cond_wait(&cond, &var);
		}

	fp = fopen( "file2.c", "w+" );
	unsigned int prio = 0;

	st = mq_receive(mqdes, buf, 8192, 0);
    if( st == -1){
        perror("Receive Failed");
        exit( EXIT_FAILURE);
        }
     else{

        if( 0 == (fwrite( buf, pos, 1, fp))){
			perror("fwrite failed\n");
			exit(EXIT_FAILURE);
        }
		}
		fclose(fp);
		x++;
		pthread_mutex_unlock( &var );
		pthread_cond_broadcast(&cond);
}
void* th_2(void *p)
{
	pthread_mutex_lock( &var );
	while( x != 1 ){
		pthread_cond_wait( &cond, &var);
		}
	
	fp = fopen( "file2.c", "a+" );
	st = mq_receive( mqdes, buf, 8192, 0);
        if( st == -1){
            perror("Receive Failed\n");
            exit( EXIT_FAILURE);
            }
        else{
        fwrite( buf, pos, 1, fp);
        }
		fclose(fp);
		x++;
		pthread_mutex_unlock( &var );
		pthread_cond_broadcast( &cond );
}

void* th_3(void *p)
{
	pthread_mutex_lock( &var );

	while( x != 2 ){
		pthread_cond_wait( &cond, &var);
		}

	fp = fopen( "file2.c", "a+" );

	st = mq_receive( mqdes, buf, 8192, 0 );
        if( st == -1){
            perror("Receive Failed\n");
            exit( EXIT_FAILURE);
            }
        else{
        fwrite( buf, pos, 1, fp);
        }
		fclose(fp);
		x++;
		pthread_mutex_unlock( &var );
		pthread_cond_broadcast( &cond );
}


void* th_4(void *p)
{
	pthread_mutex_lock( &var );
	while( x != 3 ){
		pthread_cond_wait( &cond, &var);
		}
	
	fp = fopen( "file2.c", "a+" );
	st = mq_receive( mqdes, buf, 8192, 0 );
        if( st == -1){
            perror("Receive Failed\n");
            exit( EXIT_FAILURE);
            }
        else{
        fwrite( buf, pos, 1, fp);
        }
		fclose(fp);
		printf("Writing into a file is completed\n");
		x++;
		pthread_mutex_unlock( &var );
		pthread_cond_broadcast( &cond );
}


int main( void )
{
	pthread_t pid;
	pthread_t pid1;
	pthread_t pid2;
	pthread_t pid3;
	
	if(-1 == (mqdes = mq_open( "/mqueue1", O_RDWR))){
		perror("mq_open failed\n");
		exit(EXIT_FAILURE);
		}

		pthread_mutex_lock( &var );

		if(pthread_create( &pid, NULL, th_1, NULL ) != 0){
			printf("creation failed\n");
			}

		if(0 !=(pthread_create( &pid1, NULL, th_2, NULL ))){
			perror("creation failed\n");
	        exit( 0 );
            }
		
		if(0 != (pthread_create( &pid2, NULL, th_3, NULL ))){
		   perror("creation failed\n");
           exit( 0 );
            }
		
		if(0 != (pthread_create( &pid3, NULL, th_4, NULL ))){
		   perror("creation failed\n");
           exit( 0 );
            }
			
		
		pthread_mutex_unlock( &var );
	pthread_exit(NULL);

	return 0;
}

		
