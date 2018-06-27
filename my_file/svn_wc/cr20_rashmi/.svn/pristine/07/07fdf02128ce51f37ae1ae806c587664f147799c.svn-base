// to check a palindrome
#include<stdio.h>
unsigned int is_palindrome( char* str)
{
	printf("hello");
	char *ptr=str;
	unsigned int flag = 0;
	
	while( *ptr != '\0'){
		ptr++;
	}
	ptr--;
	
	while( *str != '\0'){
		if( *str == *ptr){
			str++;
			ptr--;
			flag = 1;
		}
		else
			flag = 0;
	}
	return flag;
}
