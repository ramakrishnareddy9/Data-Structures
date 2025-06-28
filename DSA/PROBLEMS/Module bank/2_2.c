#include <stdio.h>

int binary_search(int a[], int l, int r, int key)
{
    int result;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            r = mid - 1;
        }
        else
        {
            result = mid;
            l = mid + 1;
        }
    }
    return result;
}

int main()
{
    int q;
    printf("enter no of queries :");
    scanf("%d", &q);
    for (int j = 0; j < q; j++)
    {
        int n, key;
        printf("no of elements :");
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("enter the key : ");
        scanf("%d", &key);
        int result = binary_search(a, 0, n - 1, key);
        printf("%d", a[result]);
    }
    return 0;
}