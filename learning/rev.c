#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

char* strrev(char*);

int main( void )
{
	char *ptr = NULL;
	char *temp = NULL;
	char *str1 = NULL;
	char *str2 = NULL;
	char *rev = NULL;

	int len = 0;

	ptr = (char *)malloc((sizeof( char) * MAX));
	temp = (char *)malloc((sizeof( char) * MAX));
	str1 = (char *)malloc((sizeof(char) * 25));
	str2 = (char *)malloc((sizeof( char) * 25));
	rev = (char *)malloc((sizeof(char) * 25));

	printf("Entter the string\n");
	fgets( ptr, 25, stdin);
	
	temp = ptr;
	str1 = ptr;


	len = strlen(ptr) - 1;
	ptr = ptr + len;
	

	str2 = ptr;
//	printf("reversed %s",str2);

	ptr = temp;

	int j = 1;
	int k = 1;
	int i;
	int index = 0;

//		printf("%p\n",ptr);
	len = strlen(ptr) - 1;

//		printf("%p\n",ptr);
	
	while( len > 0){
	for( i = 0; i < j; i++){
			printf("%c", *str1);
			str1++;
			
		}
		len = len - j;

		printf("\n");
		j = j + 2;

		for( i = 0; i <= k; i++){
			*(rev + index) = *(str2 - index);
			index++;	
		}

		len = len - k;

		rev = strrev(rev);
		printf("%s",rev);
		
//		rev = rev - k;

		k = k + 2;	


	}
//	free(ptr);

	return 0;
}


char* strrev( char * rev)
{
	char *ptr = NULL;
	char *ptr1 = NULL;
	ptr = (char*)malloc(sizeof(char)*MAX);
	ptr1 = (char*)malloc(sizeof(char)*MAX);
	
	int index = 0;	
	ptr = rev;

//	printf("recieved string %s\n", rev);

	int len = strlen(rev)-1 ;
//		printf("length of string %d\n",len);
//		printf("before %p\n",ptr);
	ptr = ptr + len;
//		printf("After %p", ptr);
	while( *rev != '\0')
	{
		*(ptr1 + index) = *(ptr - index);
//	printf("%s",*ptr1);
//		ptr1++;
//		ptr--;
		rev++;
		index++;
	}
//	printf("string = %s", ptr1);

	return ptr1;
}


			



