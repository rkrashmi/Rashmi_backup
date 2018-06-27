#include<stdio.h>
void main()
{
	char buf[100];
	unsigned int num;
	printf("Enter the nor:\n");
	fgets(buf,100,stdin);
	num =n_atoi(buf);
	printf("%d",num);
}
	unsigned int n_atoi(char *buff)
	{	
	    int i;
    	int n;
    	n=0;
   		 for(i=0;buff[i] >= '0' && buff[i] <='9'; ++i)
    	 n = 10 * n + (buff[i]-'0');
    	return n;
	}



     
