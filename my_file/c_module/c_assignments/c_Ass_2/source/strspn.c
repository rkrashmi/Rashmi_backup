//to count initial set of characters
#include"header.h"

int strspn(const char *sbuf, const char *dbuf)
{
	int count;
	while(*dbuf != '\n'){
	if(*sbuf == *dbuf){
	count++;
	}
	dbuf++;
	}
	if(count == 0){
	exit(0);
	}
	else 
	sbuf++;
	return count;
}

