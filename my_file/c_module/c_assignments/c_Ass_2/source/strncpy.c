//prgrm for copying a string

#include"header.h"

void my_strncpy(char *sbuf,char *dbuf,int  n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		*(dbuf++) = *(sbuf++) ;
	}
	*(dbuf) = '\0';
}
