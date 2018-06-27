
#include <stdio.h>

void mergesort(int [],int,int);//dividing array into halves

void merge(int [],int,int,int);//to merge the two sorted halves

int c[10] , low , high;

int main()
{
	int a[10];
	int n;
	int i;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	
	printf("Enter elements \n");
	for(i = 0; i < n; i++)
	   scanf("%d",&a[i]); 
	
	low = 0;
	high = n-1;

	mergesort(a , low , high);

	printf("The sorted array elements are\n");
	for(i = low; i <= high; i++)
	  printf("%d\n",a[i]);
    return 0;
}//End of main


void mergesort(int a[10] , int low , int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high)/2;
		mergesort(a , low , mid);//recursively calls untill if condition fails
		mergesort(a , mid + 1 , high);
		merge(a , low , mid , high);//merging
	}
}//End of mergesort



void merge(int a[10] , int low , int mid , int high)
{
	int i = low;
	int	j = mid+1;
	int	k = low;
	while((i <= mid) && (j <= high))
	{
		if(a[i] < a[j])//comparing two halves
		{
			c[k] = a[i];//if a[i] is greater
			k++;
			i++;
		}
		else
		{
			c[k] = a[j];//a[j] is greater
			k++;
			j++;
		}
		
	}
	while(i <= mid)
	{
		c[k] = a[i];//remaining elements 
		k++;
		i++;
	}
	while(j <= high)
	{
		c[k] = a[j];//remaining elements
		k++;
		j++;
	}
	for(i = low;i <= high;i++)
	{
		a[i] = c[i];//copying temp array to original array
	}  
}//End of merge


