#include<stdio.h>
#include<string.h>
int main()
{
	char str_arr[40] = "Global edge";
	char str_arr2[40] = "learning & development";
	char *str_ptr = "technical training";

	strcat(str_arr,str_ptr);
	printf("%s\n",str_arr);
	strcat(str_arr,str_arr2);
	printf("%s\n",str_arr);
	printf("%s\n",str_arr2);
	return 0;
}
