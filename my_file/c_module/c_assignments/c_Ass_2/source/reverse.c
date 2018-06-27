//for reversing the string
#include"header.h"

void reverse( char *sbuf)
{
	int len;
	int i;
	char *dbuf;
	len = strlen(sbuf) - 1;
	sbuf = sbuf + len;
	for(i = 0;i < len; i++)
	{
		*(dbuf++) = *(sbuf--);
		len--;
	}
 	 *(dbuf) = '\0';
}
