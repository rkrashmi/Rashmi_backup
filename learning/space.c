#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int main( void )
{
	int count = 0;
	static int num;
	int n;

	char * buf = NULL;
	buf = (char *)malloc(sizeof(char) * MAX);

	printf("Enter numbers\n");
	while( count < MAX )
	{
		fgets(buf , MAX, stdin);
		n = atoi(buf);
		
		num = printf("%d",n);
//			printf("%d",num);	
		while(num >= 0)
		{
			printf("_");
			num--;
		}
		count++;
	}
	return 0;
}
