//append n characters from one string to another
#include"header.h"

char snappend(char * sbuf ,char * dbuf , int n)
{
    int len;
	int i = 0;
    len = strlen(dbuf) - 1;
    while(i < n)
    {
        *(dbuf+len++) = *(sbuf++);
		i++;
    }
  
}

