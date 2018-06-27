#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

void * thread_func_2(void *p);
void * thread_func_3(void *p);
void * thread_func_4(void *p);

void * thread_func_1(void *p)
{
	
	pthread_t thread_id;
	printf("am\n");

	pthread_create(&thread_id, NULL , thread_func_2, NULL);
	printf("Why???\n");
//	pthread_join(&thread_func_2, NULL);
	
	return;
}
void * thread_func_2(void *p)
{
	printf("at\n");
	pthread_t thread_id;
	pthread_create(&thread_id, NULL , thread_func_3, NULL);
	printf("hello\n");
	return;
}

void * thread_func_3(void *p)
{
	pthread_t thread_id;
	printf("the\n");
	pthread_create(&thread_id, NULL , thread_func_4, NULL);
	
	printf("qwe\n");
	printf("qwesdfdf\n");
	printf("qwesdfds\n");
	printf("qwasfdfe\n");
	printf("qwesdafd\n");
	printf("qwe\n");
	printf("qwasdfdsfe\n");
	printf("qwe\n");
	printf("qwsdafdsfsdfsdfe\n");
	printf("qwasdfdsfdfe\n");
	return;
}
void * thread_func_4(void *p)
{
	//pthread_t thread_id;
	printf("edge\n");
	printf("omg!!!");
	return;
}
int main( void )
{
	pthread_t thread_id;

	printf("I\n");

	pthread_create(&thread_id, NULL , thread_func_1, NULL);
/*	pthread_create(&thread_id, NULL , thread_func_2, NULL);
	pthread_create(&thread_id, NULL , thread_func_3, NULL);
	pthread_create(&thread_id, NULL , thread_func_4, NULL);
//	getchar();
//	getchar();*/
	//pthread_exit(NULL);
	printf("qwe111111111\n");
	printf("qwe1111111113\n");
	printf("qwe11111111433\n");
	printf("qwe111111115666666664\n");
	printf("qwe111111123\n");
	printf("qwe111111134\n");
	pthread_exit(NULL);

	return 0;
} 
	
