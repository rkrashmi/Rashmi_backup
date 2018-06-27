//prgrm to remove comments

#include <stdio.h>
#include <stdlib.h>

void f_copy(FILE *ifp)
{
	char c;
	int n = 0;

	while(( c = getc(ifp)) != EOF) {

		if( c == '"'){
			n = ftell(ifp);
			fseek( ifp , n , SEEK_SET);
			putc( c, stdout);
			}
			while( (c = getc(ifp) != '"'){
				putc(c, stdout);
	
							}
				}
			
		 else if( c != '/')
			putc(c, stdout);
		
		else if(c == '/') {
			if((c = getc(ifp)) == '/') {
				while(( c = getc(ifp)) != '\n') {
					;
				}
				putc('\n',stdout);
			}
		else if( c == '*') {
			while(( c = getc(ifp)) != '*') {
				;
			}
		
			
			if(( c = getc(ifp)) == '/') {
				;
			}
		  }
		}
	}
}


int main(int argc , char *argv[])
{
	FILE *fp;

	fp = fopen(* ++argv , "r");
	if(argc == 1)
		perror("No input files");	
	
	else if( argc > 2)
		perror("Enter only 1 input file");	
	
	else if(argc == 2) {
		f_copy(fp);	
		fclose(fp);
	}
	
	return 0;
}



