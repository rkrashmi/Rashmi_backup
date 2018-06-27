#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int* bubble(int a[],int i);
int main(void)
{
	int temp = 0;
	int i;
	int j;
	char *buf = NULL;
	int a[MAX];
	int *ptr = NULL;
	buf = (char *) malloc (sizeof(char) * MAX);
	ptr = (int *) malloc (sizeof(int) * MAX);
	printf("Enter the elements of array :\n");

	for(i= 0; i < MAX; i++){
		fgets(buf , MAX , stdin);
		a[i] = atoi(buf);
		}
#if 0
	for( i = 0; i < MAX-1 ; i++){
		for ( j = 0 ; j < MAX -1- i ; j++){
			if(a[j] > a[j+1]){
			temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
			}
		}	
	}
#endif
	
	ptr = bubble(a,i);

	printf("sorted list is \n");
	for ( i = 0; i < MAX; i++){
		printf("%d\t",a[i]);

	
}	
	return 0;
}

int* bubble (int *ptr ,int i)
{
	int j ;
	int temp;
	while ( i < MAX){
	if (*ptr < *(ptr+1))
	return 0;

	else 
	{
	 temp = *ptr;
     *ptr = *(ptr+1);
     *(ptr+1) = temp;
	}
		ptr++;
	}

	 bubble( ptr, i++);
	return ptr;
}














 
