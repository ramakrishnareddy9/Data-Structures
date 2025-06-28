#include <stdio.h>
#include <limits.h>

int sort(int a[], int n, int target)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[smallest] > a[j])
            {
                smallest = j;
            }
            if (a[smallest] != target)
            {
                int temp = a[smallest];
                a[smallest] = a[i];
                a[i] = temp;
            }
        }
        if (a[i - 1] < target && a[smallest] == target)
        {
            for (int j = n; j >= i; j--)
            {
                a[j + 1] = a[j];
            }
            a[i] = target;
            break;
            return i;
        }
    }
}

void position(int a[], int n, int target)
{
    printf("(");
    for (int i = 0; i < n + 1; i++)
    {
        if (a[i] == target)
        {
            printf("%d,", i);
            break;
        }
    }
    for (int i = n; i >= 0; i++)
    {
        if (a[i] == target)
        {
            printf("%d", i);
            break;
        }
    }
    printf(")");
}

void pairs(int a[], int n, int target)
{
    int found = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (a[i] + a[j] == target)
            {
                printf("(%d,%d)", i, j);
                found = 1;
            }
        }
    }
    if (!found)
    {
        printf("no pairs");
    }
}
int duplicate(int a[], int n, int target)
{
    int size = n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] == a[j])
            {
                for (int k = i; k <= n; k++)
                {
                    a[k] = a[k + 1];
                }
                i--;
                for (int k = j; k <= n; k++)
                {
                    a[k] = a[k + 1];
                }
                j--;
                size--;
            }
        }
    }
    return size;
}

void difference(int b[][100], int k, int p, int r)
{
    int min = INT_MAX, max = INT_MIN, result = 0;
    for (int i = 0; i < k; i++)
    {
        int size = p + (i < r ? 1 : 0);
        for (int j = 0; j < size; j++)
        {
            if (b[i][j] < min)
            {
                min = b[i][j];
            }
            if (b[i][j] > max)
            {
                max = b[i][j];
            }
        }
        result += (max - min);
    }
    printf("sum of differences of the maximum and the minimum of each subarray is %d", result);
}

void subarray(int a[], int n, int k)
{
    int p = n / k;
    int r = n % k;
    int b[k][p > r ? p : r];
    int x = 0;
    for (int i = 0; i < k; i++)
    {
        int size = p + (i < r ? 1 : 0);
        for (int j = 0; j < size; j++)
        {
            b[i][j] = a[x++];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int size = p + (i < r ? 1 : 0);
        for (int j = 0; j < size; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    difference(b, k, p, r);
}

int main()
{
    int n;
    printf("enter n value :");
    scanf("%d", &n);
    int a[n + 1];
    printf("enter thr array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int target;
    printf("enter the target value :");
    scanf("%d", &target);
    int result = sort(a, n, target);
    printf("%d\n", result);
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    position(a, n, target);
    printf("\n");
    pairs(a, n, target);
    printf("\n");
    n = duplicate(a, n, target);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nenter the k value :");
    int k;
    scanf("%d", &k);
    subarray(a, n, k);
    return 0;
}