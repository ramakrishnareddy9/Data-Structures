#include <stdio.h>

int interpolation_search(int a[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high && key >= a[low] && key <= a[high])
    {
        if (low == high)
        {
            if (a[low] == key)
            {
                return low;
            }
            return -1;
        }
        else
        {
            int pos = low + ((key - a[low]) * (high - low) / (a[high] - a[low]));
            if (a[pos] == key)
            {
                return pos;
            }
            else if (a[pos] < key)
            {
                low = pos + 1;
            }
            else
            {
                high = pos - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;
    int key = 5;
    int r = interpolation_search(a, n, key);
    if (r == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", r);
    }
    return 0;
}
