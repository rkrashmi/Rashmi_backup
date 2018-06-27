// compare two strings
#include"header.h"
	
int my_strcmp(char *sbuf, char *dbuf)
{
	for(; *sbuf == *dbuf; sbuf++ , dbuf++)
	if(*sbuf == '\0')
	return 0;
	return (*sbuf - *dbuf);
}
