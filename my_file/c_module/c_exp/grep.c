:#include <stdio.h>
#include <stdlib.h>
int  coun_t (FILE * , char , char *);
int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	char *str;
	int count;
	
	fp = fopen(*++argv , "r");
	printf("Enter the string\n");

	str =  malloc(sizeof(char) * 255);
	fgets(str , 255, stdin);
	
	count = coun_t(fp , ch , str); 
	if(count != 0)
	{
		printf("String is present\n");
		printf("string is present in line %d \n", count);
	}
	else 
		printf("String is not present\n");
	return 0;
}


int coun_t(FILE * fp , char ch , char *str)
{
	int count = 0;
	//char *c = NULL;
	while((ch = getc(fp) != EOF)) {
		if((*str != (ch = getc(fp)))){
			if(ch = getc(fp) == '\n')
				{
					count++;
					printf("%d\n",count);
				}
			}
		else
			{
				if(*str == '\n')
					str++;
			}
		}
		return count;
}

