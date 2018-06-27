//program to find a key using linear search

#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int main(void)
{
	int pos = 0;
	int key;
	int n;
	int index = 0;
	char *buf = NULL;

	buf = (char *)malloc(sizeof(char) * MAX);	

	printf("Enter the size of the array:\n");
	fgets(buf , MAX , stdin);
	n = atoi(buf);

	int a[n];
 
	printf("Enter array elements:\n");
	for(index = 0; index < n; index++){
		 fgets(buf , MAX , stdin);
		a[index] = atoi(buf);
		}
	
	printf("Enter the key to be searched:\n");
	fgets(buf , MAX , stdin);
	key = atoi(buf);

	while(index < n){
		if(key == a[index]){
			pos = index;
		}
		else
			index++;
	}

	if(pos)
		printf("%d is found in %d position\n",key,pos);
	else
		printf("%d is not found\n",key);

	return 0;
}



















