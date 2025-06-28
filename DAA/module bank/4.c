#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int bridgeCrossing(int *times, int n)
{
    quick_sort(times, 0, n - 1);
    int totalTime = 0;

    while (n > 3)
    {
        int option1 = times[1] + times[0] + times[n - 1] + times[1];
        int option2 = times[n - 1] + times[0] + times[n - 2] + times[0];
        totalTime += (option1 < option2) ? option1 : option2;
        n -= 2;
    }

    if (n == 3)
    {
        totalTime += times[2] + times[0] + times[1];
    }
    else if (n == 2)
    {
        totalTime += times[1];
    }
    else if (n == 1)
    {
        totalTime += times[0];
    }

    return totalTime;
}

int main()
{
    int times[] = {1, 2, 5, 10};
    int n = 4;

    int result = bridgeCrossing(times, n);
    printf("Total time to cross: %d minutes\n", result);
    return 0;
}
