//count the length of the string

#include <stdio.h>
#include<stdlib.h>
#define MAX 100

int my_strcspn(const char* ,const char*);

int main(void)
{
	char *str = NULL;
	char *reject = NULL;
	unsigned int count;
	
	printf("Enter the string:\n");
	
	if(NULL == (str = (char *) malloc (sizeof(char) * MAX))){
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if(NULL ==  (fgets(str,MAX,stdin))){
		perror("fgets failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the string to check:\n");
	if(NULL == (reject = (char *) malloc(sizeof(char) * MAX))){
        perror("malloc failed\n");
        exit(EXIT_FAILURE);
    }

    if(NULL ==  (fgets(reject,MAX,stdin))){
        perror("fgets failed\n");
        exit(EXIT_FAILURE);
    }

	count = my_strcspn(str,reject);
	
	printf("Output = %d\n",count);
	return 0;
}
		
