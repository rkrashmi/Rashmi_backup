#include <stdio.h>
void my_cat2(FILE *ifp);
void my_cat3(FILE *ifp , FILE *ofp , char *argv[]);

int main (int argc , char *argv[])
{
	FILE *ifp;
	FILE *ofp;
	char ch;
	int i;

	if(argc == 1)
		printf("No input files\n");

	ifp = fopen(*++argv , "r");

	if(argc == 2)
	{
		my_cat2(ifp);
	}
	
	else{
		 if(argc > 2)
	 { 
		for(i = 0; i < argc; i++){
			my_cat2(ifp);
			ifp = fopen(*++argv , "r");
			}
	 }
	}
		argv++;
 
	if(*argv == '>'){
		my_cat3(ifp , ofp , argv);
	}
	fclose(ifp);
	return 0;
}		 



void my_cat2(FILE *ifp)
{
	char ch;
	while((ch = getc(ifp)) != EOF)
	{
		putc(ch ,stdout);
	}
}


void my_cat3(FILE *ifp , FILE *ofp , char *argv[])
{
    char ch;
	int i = 2;

	ifp = fopen(*argv-- , "r");
	ofp = fopen(*(argv + i) , "w");

    while((ch = getc(ifp)) != EOF)
    {
        putc(ch ,ofp);
    }
	fclose(ifp);
	fclose(ofp);
}


















