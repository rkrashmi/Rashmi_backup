#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256
//char* strtok(const char* ,const char*);
//char* squeez(char*, char*);
int strrot(const char*,const char*);

int main()
{
	char *sbuf;
	char *delim;
//	char *temp;
	 int res;
	printf("Enter string\n");

	sbuf = (char*) malloc (sizeof(int)*MAX);
	fgets(sbuf,MAX,stdin);
	
	printf("enter delim\n");

	delim =(char*) malloc (sizeof(int)*MAX);
	fgets(delim,MAX,stdin);
	
	strcat(sbuf,delim);

//	printf("enter delim\n");
//	scanf("%c",delim);
//	temp =strtok(sbuf,delim);
//	temp = squeez( sbuf, delim);
	res = strrot(sbuf,delim);
	if(res == 1)
	{ printf("delim is rotated string of sbuf\n");}
	else
	{ printf("delim is not rotated string of sbuf\n");}

//	printf("%d",res);
	return 0;
}
#if 0
char* strtok(const char *sbuf,const char *delim)
{
	int i;
	char *temp =NULL;

	temp = (char*) malloc(sizeof(int)*MAX);	
	for(i = 0;*( sbuf+i) != '\0'; i++)
	{
		if(*(sbuf+i) != *delim)
		{
			*(temp+i) = *(sbuf+i);
		}
	}
	return temp;
}

	char* squeez(char* sbuf,char* delim)
{
	int i=0, j=0;
	while(*(sbuf+i) != '\0')
{
	*(delim+j) = *(sbuf+i);
	while(*(delim+j) == *(sbuf+i))
{
	i++;
}
	j++;
 }
return delim;
}

#endif
int strrot(const char* sbuf,const char* delim)
{
	int count =0;
int flag = 0;
	int len = 0;

	len = strlen(delim);
	printf("length = %d\n",len);
	while(*delim != '\0' && *sbuf != '\0')
	{
		if(*sbuf !=  *delim){
		sbuf++;
//		count = 0;
	}
	else
	{
		sbuf++;
		delim++;
		++count;}
	}
	printf("count = %d",count);
	if(count == (len ))
	flag = 1;
	return flag;
}



