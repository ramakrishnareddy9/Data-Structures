#include <stdio.h>
#include <limits.h> // For INT_MAX

int m = 0;
void sort(int a[]);
void remove_(int a[]);
void queries(int a[], int n);
void display(int a[]);

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &m);
    int a[100];
    printf("Enter %d elements: ", m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter number of queries: ");
    scanf("%d", &n);
    queries(a, n);
    display(a);
    return 0;
}

void sort(int a[])
{
    for (int i = 0; i < m - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < m - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}

void queries(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        char b;
        int c;
        printf("Enter query (I for insert, R for remove): ");
        scanf(" %c", &b);
        if (b == 'I')
        {
            printf("Enter value to insert: ");
            scanf("%d", &c);
            a[m] = c;
            m++;
            sort(a);
        }
        else if (b == 'R')
        {
            remove_(a);
        }
    }
}

void remove_(int a[])
{
    if (m == 0)
    {
        printf("Array is empty, nothing to remove.\n");
        return;
    }

    int min = INT_MAX, j = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            j = i;
        }
    }

    for (int i = j; i < m - 1; i++)
    {
        a[i] = a[i + 1];
    }
    m--;
}

void display(int a[])
{
    printf("Array contents: ");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
