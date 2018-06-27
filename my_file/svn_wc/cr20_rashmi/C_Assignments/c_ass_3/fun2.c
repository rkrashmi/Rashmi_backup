#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int i = 1;
	int len;
	char *ptr;
	int count = 0;

	while(--argc > 0){

	ptr = argv[i];

	while(*ptr != '.' && *ptr != '\0')
		ptr++;

	if(*(++ptr) == 'c')
		count++;
	i++;
	}

	printf("Number of c files in a documentory = %d\n",count);
	return 0;
}
#if 0

	printf("*argv[0] -> %s\n", argv[0]);
	
	return 0;
}
#endif
