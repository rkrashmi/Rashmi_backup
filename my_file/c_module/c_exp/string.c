#include <stdio.h>
int main(void)
{
	char *str1 = "hello";
	char str2[6] = "world";

	printf("%p\n",str1);
	
	printf("%p\n",str2);

	printf("%p\n","hello");

	*str1 = "hi";
	printf("str1 = %p\n",str1);
	printf("%p\n","hello");
	printf("%p\n","hi");
	
	str2[2] = 'a';
	printf("str2 = %s",str2);
	return 0;
}
