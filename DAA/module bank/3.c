#include <stdio.h>

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = a[i];
        int j = i - 1;
        while (j >= 0 && current < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }
}

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

void sort(int arr[], int low, int high, int threshold)
{
    if (low < high)
    {
        if (high - low < threshold)
        {
            insertion_sort(arr + low, high - low + 1);
        }
        else
        {
            int pivot = partition(arr, low, high);
            sort(arr, low, pivot - 1, threshold);
            sort(arr, pivot + 1, high, threshold);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, 0, n - 1, n / 10);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
