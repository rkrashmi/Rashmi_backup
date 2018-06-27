#include <stdio.h>
#include <stdlib.h>

int main( void )
{

	int a[10] = {10,20,30,40,50,60,70,80,90};
	int *ptr = NULL;

	ptr = malloc(20);
	ptr = &a;

	printf("%p\n",ptr);
	printf("%p\n",&ptr);
	printf("%d\n",*ptr);
	printf("%p\n",ptr++);
	printf("%d\n",*ptr);
	printf("%p\n",++ptr);
	printf("%d\n",*ptr);
	printf("%d\n",*ptr++);
	printf("%d\n",*++ptr);
	printf("%d\n",++*ptr);
	printf("%d\n",*--ptr);
	//printf("%d\n",**ptr);
	printf("%p\n",&ptr);
	printf("%p\n",&ptr+1);
	printf("%p\n",*(&ptr+1));
	printf("%d\n",*ptr);
	
	return 0;
}


