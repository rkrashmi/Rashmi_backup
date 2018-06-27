//count the nor of bits//
#include"header.h"

int main()
{
	char *buf = NULL;
	int num1;
	int num2;
	int n;
	int count;

	printf("Enter the size of the nors:\n");

	if(NULL == (buf =(char*) malloc(sizeof(char)* MAX))){
		perror("malloc failed\n");
		exit(EXIT_FAILURE); 
	}

	if(NULL == (fgets(buf,MAX,stdin)))
	{
		perror("fgets failed");
		exit(EXIT_FAILURE);
	}

	n = atoi(buf);

	printf("Enter the first  nor:\n");

	if(NULL == (buf =(char*) malloc(sizeof(char)* MAX))){
    	perror("malloc failed\n");
    	exit(EXIT_FAILURE); 
	}

    if(NULL == (fgets(buf,MAX,stdin)))
    {
        perror("fgets failed");
        exit(EXIT_FAILURE);
    }
    num1 = atoi(buf);

	printf("Enter the second the nor:\n");

	if(NULL == (buf =(char*) malloc(sizeof(char)* MAX))){
    perror("malloc failed\n");
    exit(EXIT_FAILURE); 
	}

    if(NULL == (fgets(buf,MAX,stdin)))
    {
        perror("fgets failed");
        exit(EXIT_FAILURE);
    }
    num2 = atoi(buf);

	count = count_bit(num1,num2,n);
	printf("OUTPUT = %d",count);
	return 0;
}
