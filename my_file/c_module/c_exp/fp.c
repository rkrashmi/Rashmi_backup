#include<stdio.h>
int main()
{
	int count;
	FILE *fp1;

	count = fprintf(fp1,"%d",5);

	if(count < 0) {
		printf("fprintf() failed\n");
}
	return 0;
}
