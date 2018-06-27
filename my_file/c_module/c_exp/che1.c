#include <stdio.h>
int main()
{
	int i;
	int j = 0;

	for(i = 0 ; i < 100; i++)
	{
		j = j++;
	}
	printf("%d\n",j);
	return 0;
}
