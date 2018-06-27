//to insert a character in the given string
#include"header.h"

char insertchar(char *sbuf, char ch,  int pos)
{
	char temp;
	char temp1;
	sbuf = sbuf + (pos - 1);
	temp = *sbuf;
	*sbuf = ch;
	sbuf++;
	while( *sbuf != '\0')
	{
		temp1 = *sbuf;
		*sbuf = temp;
		temp = temp1;
		sbuf++;
	}
}
