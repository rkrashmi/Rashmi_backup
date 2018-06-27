//append one string to another
#include"header.h"

void sappend(char *sbuf ,char *dbuf)
{
	int len;
	len = strlen(dbuf) - 1;
	while( *sbuf != '\0'){
		*(dbuf+len++) = *(sbuf++);
	}
	//return dbuf;

}
