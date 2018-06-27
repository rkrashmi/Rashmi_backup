#include<stdio.h>
int var = 10;
int main()
{
//	const int var = 10;
	//int *ptr = &var;
	int i = 0 ;
	printf("%d\n",var);
	//*ptr = 5;
	while ( i < 10){
	//printf("%d\n",(*ptr)++);
	printf("%d\n",i);
	i++;
	}
	return 0;
} 
