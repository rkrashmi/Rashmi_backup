//check whether the one string is rotated string of another or not

#include"header.h"

int strrot( char * sbuf, char * dbuf)
{
	int len;
	
	len = strlen(dbuf) - 1;
	dbuf = dbuf + len;

	if( *sbuf == *dbuf)
			*sbuf++;
		dbuf = dbuf - len + 1;
	while(  *sbuf != '\0')
		if( *(sbuf++) == *(dbuf++))
		return 0;
	return 1;
}
