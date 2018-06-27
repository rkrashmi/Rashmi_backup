#include <stdio.h>


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
//function to perform partion 
int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	int j;
	for (j = low; j <= high- 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

//performing quicksort
void quickSort(int arr[], int low, int high)
{
	int pivot;
	if (low < high)
	{
		
		pivot = partition(arr, low, high);

		//recursively performing quicksort
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, n-1);
	printf("Sorted array: ");
	printArray(arr, n);
	printf("\n");
	return 0;
}


