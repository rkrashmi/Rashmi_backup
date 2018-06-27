#include<stdio.h>
int main()
{
	int a= 0x01;
	char *ptr = NULL;
	ptr = (char*)&a;
	if(*ptr == 1){
		printf("Little endian");
		}
	else 
		printf(" Big endian");
	return 0;
}
