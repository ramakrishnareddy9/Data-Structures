#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Recursive Quick Sort (QR)
void quickSortRecursive(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

// Iterative Quick Sort (QI) without using stack
void quickSortIterative(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int pi = partition(arr, low, high);

        // Decide whether to process the left or right subarray iteratively
        if (pi - low < high - pi)
        {
            // Process the smaller left subarray iteratively
            if (low < pi - 1)
            {
                high = pi - 1;
            }
            else
            {
                low = pi + 1;
            }
        }
        else
        {
            // Process the smaller right subarray iteratively
            if (pi + 1 < high)
            {
                low = pi + 1;
            }
            else
            {
                high = pi - 1;
            }
        }
    }
}

// Iterative Selection Sort (SS)
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Apply Recursive Quick Sort (QR)
    quickSortRecursive(arr, 0, n - 1);
    printf("Sorted array with Recursive Quick Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reset the array for the next sort
    int arr2[] = {10, 7, 8, 9, 1, 5};

    // Apply Iterative Quick Sort (QI) without stack
    quickSortIterative(arr2, n);
    printf("Sorted array with Iterative Quick Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Reset the array for the next sort
    int arr3[] = {10, 7, 8, 9, 1, 5};

    // Apply Selection Sort (SS)
    selectionSort(arr3, n);
    printf("Sorted array with Selection Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}