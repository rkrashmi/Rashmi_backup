#include "header.h"

void quickSort(int arr[], int low, int high)

{

    int pivot;

    if (low < high)

    {
        pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);

        quickSort(arr, pivot + 1, high);

    }

}


