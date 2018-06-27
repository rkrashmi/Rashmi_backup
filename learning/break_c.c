#include <stdio.h>

int main(void)
{
	int c = 0;

	while(c <= 20){
	if( c <= 5)
	{
		printf("hello");
		printf("\nworld");
	}
	else if( c > 5 && c <= 10){
		printf("Good\n");
		printf("morning\n");
		break;
		printf("!!!");
		}
	else{
		printf("OMG");
		}
	c++;

	if( c == 11)
	{
		printf("!!!!!!!!printed\n");
	}
	}

	return 0;
}
