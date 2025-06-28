#include <stdio.h>

void conqure(int a[], int si, int ei, int mid)
{
    int merged[ei - si + 1];
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;
    while (idx1 <= mid && idx2 <= ei)
    {
        if (a[idx1] <= a[idx2])
        {
            merged[x++] = a[idx1++];
        }
        else
        {
            merged[x++] = a[idx2++];
        }
    }
    while (idx1 <= mid)
    {
        merged[x++] = a[idx1++];
    }
    while (idx2 <= ei)
    {
        merged[x++] = a[idx2++];
    }
    for (int i = 0, j = si; i < ei - si + 1; i++, j++)
    {
        a[j] = merged[i];
    }
}

void merg_sort(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = si + (ei - si) / 2;
    merg_sort(a, si, mid);
    merg_sort(a, mid + 1, ei);
    conqure(a, si, ei, mid);
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;
    merg_sort(arr, 0, n - 1);
    printf("Sorted array: ");
    print_array(arr, n);
    return 0;
}
