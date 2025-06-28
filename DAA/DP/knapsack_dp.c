#include <stdio.h>

#define N 100

int max(int x, int y)
{
    return (x > y) ? x : y;
}

void solve(int a[], int b[], int n, int k)
{
    int dp[N][N];
    int i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= k; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (b[i] <= j)
            {
                dp[i][j] = max(a[i] + dp[i - 1][j - b[i]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d\n", dp[n][k]);

    i = n;
    j = k;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            printf("%d ", i);
            j -= b[i];
        }
        i--;
    }
    printf("\n");
}

int main()
{
    int values[] = {0, 60, 100, 120};
    int weights[] = {0, 10, 20, 30};
    int num_items = 3;
    int capacity = 50;

    solve(values, weights, num_items, capacity);

    return 0;
}
