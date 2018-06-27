//
#include<stdio.h>
void file_copy(FILE * , FILE *);
int main(int argc , char *argv[])
{
	int index ;
//	int index1;
	FILE *ptr;

//	ptr = fopen(*++argv , "r");
	for(index = 1; index < argc ; index++)
	{
		ptr = fopen(*(argv + index) , "r");
		file_copy(ptr , stdout);
		}
		fclose(ptr);
		

	return 0;
}

void file_copy(FILE *ip, FILE *op)
{
	int c;
	while( (c = getc(ip)) != EOF)
	putc( c , op);
}
