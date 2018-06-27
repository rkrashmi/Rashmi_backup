#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void Addjob(int *,int *,int[]);
int main(void)
{
	int i;
	int n;
	int rear = -1;
	int front = -1;
	int queue[MAX];
	char * buf;

	printf("Enter the nor of requests to be accepted:\n");
	fgets(buf, MAX, stdin);
	n = atoi(buf);

	front = 0;
	
	for( i= 0; i <= n ; i++) {
 		Addjob(&front, &rear, queue);
		}

	return 0;
}

void Addjob(int *front, int *rear, int queue[])
{
	char *buf = NULL;
	buf = (char *)malloc (sizeof(char) * MAX);
	if(*rear == (MAX - 1)) 
	{
		printf("Buffer is full\n");
		exit(0);
	}
	
	else
	{
		*rear = *rear + 1;
		printf(" Enter the requested element\n");
		fgets(buf , MAX, stdin);
		queue[*rear] = atoi(buf);
	}
}
 
