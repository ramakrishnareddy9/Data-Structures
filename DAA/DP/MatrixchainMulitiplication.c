#include <stdio.h>
#include <limits.h>

#define MAX 100
int s[MAX][MAX];
int dp[MAX][MAX];

int matrixChainRecursive(int dims[], int i, int j)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int min = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost = matrixChainRecursive(dims, i, k) + matrixChainRecursive(dims, k + 1, j) + dims[i - 1] * dims[k] * dims[j];
        if (cost < min)
        {
            min = cost;
            s[i][j] = k;
        }
    }
    dp[i][j] = min;
    return min;
}

void printOptimalParens(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        printOptimalParens(i, s[i][j]);
        printOptimalParens(s[i][j] + 1, j);
        printf(")");
    }
}

int main()
{
    int dims[] = {40, 20, 30, 10, 30};
    int n = sizeof(dims) / sizeof(dims[0]) - 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = -1;

    int minMultiplications = matrixChainRecursive(dims, 1, n);

    printf("Minimum number of multiplications: %d\n", minMultiplications);
    printf("Optimal parenthesization: ");
    printOptimalParens(1, n);
    printf("\n");

    return 0;
}