//program to find a key using li


























#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int recursion(int* ,int ,int,int);

int main(void)
{
	int pos = 0;
	int key;
	int n;
	int index_1 = 0;
	char *buf = NULL;

	buf = (char *)malloc(sizeof(char) * MAX);	

	printf("Enter the size of the array:\n");
	fgets(buf , MAX , stdin);
	n = atoi(buf);

	int a[n];
 
	printf("Enter array elements:\n");
	for(index_1 = 0; index_1 < n; index_1++){
		 fgets(buf , MAX , stdin);
		a[index_1] = atoi(buf);
		}
	
	printf("Enter the key to be searched:\n");
	fgets(buf , MAX , stdin);
	key = atoi(buf);

	index_1 = 0;
	pos = recursion(a,key,n,index_1);
	if(pos)
		printf("%d is found at %d pos\n",key,pos);
	else
		printf("%d is not found\n",key);

	return 0;
}


int recursion(int *a, int key,int n,int index_1)
{
	while(index_1 < n){
	if(key == *(a + index_1)){
		return (index_1 +1);
	//	return index_1;
	}

	else{
			index_1++;
			 recursion(a , key, n,index_1);
		}
	}
return 0;
}

















