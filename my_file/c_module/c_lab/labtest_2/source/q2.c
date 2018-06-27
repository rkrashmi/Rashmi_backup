//checking the palindrome

#include <stdio.h>
#include <stdlib.h>
#define MAX 128

unsigned int is_palindrome( char*);

int main(void)
{
	char *str = NULL;
	unsigned int flag = 0;

	printf("Enter the string:\n");

	if(NULL == (str = (char *) malloc(sizeof(char) * MAX))){
        perror("malloc failed\n");
        exit(EXIT_FAILURE);
    }

    if(NULL == (fgets(str,MAX,stdin))){
        perror("fgets failed\n");
        exit(EXIT_FAILURE);
    }

	printf("habd");

	flag = is_palindrome(str);
	
	if(flag == 1)
		printf("Entered string is Palindrome\n");
	else
		printf("Entered string is not a Palindrome\n");

	return 0;
} 

