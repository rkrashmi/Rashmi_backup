#include<stdio.h>
#include<string.h> 
#if 0
{
  char *ptr1 = NULL;
  char *ptr2 = 0;

  strcpy(ptr1," c");
  strcpy(ptr2,"questions");

  printf("%s\n",ptr1);
  return 0;
}



int main(void)
{
  char *mess[] = {"Monday","Tuesday", "Wednesday", "Thursday"};
  printf ("%d\n%d\n", sizeof(mess), sizeof(mess[1]));
  return 0;  
}
#endif

int str_len(char *s)
{
  int length = 0;
  
  while(*s!='\n')
	 length++;
	
  return length;
}
int main(void)
{
	int length;
	char *s;
	length = str_len(s);
	printf("len = %d\n",length);
	return 0;
}
