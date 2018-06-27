//stack implementation

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10

int main(void)
{
	int a[MAX];
	int top = -1;
	int num;
	int index;
	char *buf = NULL;
	int  choice;
	
	printf("Enter the choice\n");
	printf("1. Push\n");
	printf("2.Pop\n");
	
	 buf = ((char*)malloc(sizeof(char)*MAX));
	 fgets( buf, MAX,stdin);
	 choice =atoi(buf);
	while(1){
	switch(choice)
	{
		case 1:		 printf("Enter the array size\n");
				     fgets(buf , MAX ,stdin);
 				     num = atoi(buf);

				
					if(top == num){
	
                        perror("stack overflow");
                        exit(EXIT_FAILURE);
						}
					else
						{
						top++;

						printf("Enter the element to be pushed:\n");

                        fgets( buf, MAX,stdin);
                        a[top] = atoi(buf);
						}
						//top++;
						break;
				

		case 2:	 if(top == -1)
                      {
                        perror("stack underflow");
                        exit(EXIT_FAILURE);
                        }
				else{
				index = a[top];
				printf("popped element is\n: %d", index);
				top--;
				}
				break;
	}
}
	return 0;
}

