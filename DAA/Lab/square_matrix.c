#include <stdio.h>

void printarray(int n, int c[n][n]);

void multiply(int n, int x[n][n], int y[n][n])
{
    int z[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            z[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                z[i][j] += x[i][k] * y[k][j];
            }
        }
    }
    printarray(n, z);
}

void printarray(int n, int c[n][n])
{
    printf("output\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n], b[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    multiply(n, a, b);
    return 0;
}
