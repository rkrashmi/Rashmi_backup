//counting the length of the string
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int my_strcspn(const char *str ,const char *reject)
{

	int count = 0;
	const char *temp = NULL;
	temp = reject;
	int len = (strlen(reject) - 1);
	while( *str != '\n' && *reject != '\n'){

		if( *str != *reject)
		{
			str++;
			reject = temp;
		}
		else   
		{
			str++;
			reject++;
			}
	count++;
	}

	return (count - len);
}
