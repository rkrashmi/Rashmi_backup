//program to search the given pattern in a file 

#include <stdio.h>
#include <stdlib.h>

#define MAX 255

void my_grep(FILE * , char *);
int main(int argc , char * argv[])
{
	FILE *fp;
	char *patrn = NULL;
	int count = 0;

	printf("Enter the pattern to be searched :\n");
	
	if(NULL == ( patrn = (char *) malloc (sizeof(char) * MAX))){
		perror("Malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if(NULL == (fgets(patrn , MAX , stdin))){
		perror("fgets failed\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(*++argv , "r");

	my_grep(fp , patrn);

	fclose(fp);
	free(patrn);

	return 0;
}


void my_grep( FILE * fp, char * patrn)
{
	int count = 0;
	int c;
	char *temp = patrn;
	while((c = getc(fp)) != EOF) {

		if((char)c == '\n'){
			count++;
			}

		if((char)c == *patrn )
		{
			
			patrn++;

	
			if((char) *patrn == '\n'){


				printf("pattern found at line %d\n",count+1);
					break;               
			}
		  }
	
		else
			patrn = temp;
		
	}
		if(patrn == temp)
			printf("pattern not found\n");
	
	return;
}

