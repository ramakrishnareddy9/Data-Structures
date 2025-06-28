#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapsack(int v[], int w[], int n, int W)
{
    int c[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                c[i][j] = 0;
            else if (w[i - 1] <= j)
                c[i][j] = max(v[i - 1] + c[i - 1][j - w[i - 1]], c[i - 1][j]);
            else
                c[i][j] = c[i - 1][j];
        }
    }

    printf("Maximum value: %d\n", c[n][W]);
}

int main()
{
    int v[] = {60, 100, 120};
    int w[] = {10, 20, 30};
    int W = 50;
    int n = 3;

    knapsack(v, w, n, W);
    return 0;
}
