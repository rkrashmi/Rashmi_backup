#include<stdio.h>
void main()
{
	char *str1;
	char *str2;
	int result;
	printf("enter str1:\n");
	scanf("%s", str1);
	printf("enter 2nd string:\n");
	scanf("%s",str2);

   for(; *str1 == *str2; *str++,*str2++)
		if(*str1 =='\0')
{
	printf("0");

	}
	else 
printf("%d", (*str1 - *str2));
//	printf("%d", result);
} 
	
