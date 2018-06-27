// program to remove comments from a file
#include <stdio.h>
int main(void) //main of a program 
{
/*hello every one today is tuseday
 mona not yet come today*/
	char *buf = NULL;

	int *str = "check//hyg"
	char *ch = NULL;//enter any character
	printf("Enter the character\n");
	ch = (char *) malloc(sizeof(char)* 10);
	fgets(buf , 10 , stdin);
	while( ch == 0//comparing)
	ch = buf;
	printf("Entered//hello character is : %c\n", *ch);//print the output
	return 0;
}

