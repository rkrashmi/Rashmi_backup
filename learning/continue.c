#include <stdio.h>
int main( void )
{
	int i = 0;
	int n;
	printf("Enter nors\n");
	while( i <= 10){
		i++;
		printf("nor %d:",i);
		scanf("%d",&n);
			if( n < 0){
				printf("only positive nor is valid\n");
				continue;
			}
		//i++;
	}
	return 0;
}
