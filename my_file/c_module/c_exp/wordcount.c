#include <stdio.h>
int my_wordcount(FILE *);

int main(int argc , char *argv[])
{
	if(argc == 1)
		printf("no input\n");
	
	FILE *ifp;
	char ch;
	int n;
	
	ifp = fopen(*++argv , "r");
	
	n = my_wordcount(ifp);

	printf("Nor of words in file is = %d\n",n);

	fclose(ifp);
	return 0;
}



int my_wordcount(FILE *ifp)   
{
	int count = 0;
	char ch;

	ch = getc(ifp);
	while( ch != EOF){
		if((ch = getc(ifp)) == ' ')
		{
			count++;
		}
	}
	return (count+1);
}


