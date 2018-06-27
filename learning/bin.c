#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[16];
	int num;
	int index = 0;

	printf("Enter the number:\n");
	scanf("%d\n",&num);

	while(num != 0)
	{
		arr[index++] = num % 2;
		num = num / 2;
	}
	printf("output = %d\n",arr[index]);

	return 0;
}
		
