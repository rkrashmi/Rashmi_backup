#include<stdio.h>

//char** func_Str();
//char ** fun_str1();
char ** func_Str()
{
    char  *p = "Linux";
		
    return &p;
}

char ** fun_str1()
{   
    char *p="windows";
    return &p;
}


int main(void)
{
    char **ptr = NULL;
	char **ptr1 =NULL;

	char *ptr2;
    ptr = func_Str();
	ptr2=*ptr;
    printf("\n [%s] \n",*ptr);
    ptr1 = fun_str1();
	printf("[%s]",*ptr1);

//    printf("\n [%s] \n",*ptr);
	
//	printf("%s\n",ptr2);

	printf("%s\n",*ptr);
    return 0;
}
/*
char** func_Str()
{
    char *p = "Linux";
    return &p;
}

char ** fun_str1()
{
	char *p="windows";
	return &p;
}*/
