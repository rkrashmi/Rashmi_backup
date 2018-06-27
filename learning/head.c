#include <stdio.h>

int main(int argc , char * argv[])
{
	FILE *fp;
	int c;
	int count = 0;
	int size;
	int cnt = 0;

	fp = fopen(* ++argv, "r");

//for printing first 10 lines

	while( (c = getc(fp)) != EOF ){
		if( c == '\n'){
			count++;
			}
	
		putc( c , stdout);

		if( count == 10)
			break;
	}
	return 0;
}

//for printing last 10 lines

	while( (c = getc(fp)) != EOF ){
		if( c == '\n'){
			count++;
			}
	}
	
	count = count - 10;

	rewind(fp);
	
	 while((c = getc(fp)) != EOF) {
		if( c == '\n')
		{
			cnt++;
			
			if(cnt == count)
			{
				break;			
			}
		}
	}
	
	while((c = getc(fp)) != EOF)
	{
		putc(c, stdout);
	}

	return 0;

}
