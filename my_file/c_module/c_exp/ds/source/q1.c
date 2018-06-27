#include "header.h"

typedef struct node{
	int data;
	struct node *plink;
	struct node *nlink;
	}NODE;

int main(void)
{
	NODE *head = NULL;
	char *buf = NULL;
	int num;
	
	printf("===================================================================================\n");
	printf("====================	stack	========================\n");
	printf("1. PUSH\n"
			"2.	POP \n"
			"3. DISPLAY\n");
	printf("Enter your choice: \n");
	
	if( NULL == (buf = (char *) malloc (sizeof(char) * MAX))) {
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	if( NULL == (fgets( buf, MAX, stdin))) {
		perror("fgets failed\n");
		exit(EXIT_FAILURE);
	}
	
	num = my_atoi(buf);
		
	switch(num)	{
		case 1:
			
			break;
		
		case 2:	
			break;
			
		default:
			printf("Invalid option\n");
	}
	
	return 0;
}
