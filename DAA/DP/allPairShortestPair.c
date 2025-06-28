#include <stdio.h>
#define MAX 100
#define INF 1000000

void allPaths(int cost[MAX][MAX], int dp[MAX][MAX], int n)
{
    int i, j, k;

    // Initialize dp with cost matrix
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            dp[i][j] = cost[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
}

int main()
{
    int n = 4;
    int cost[MAX][MAX] = {
        {0},
        {0, 0, 3, INF, 7},
        {0, 8, 0, 2, INF},
        {0, 5, INF, 0, 1},
        {0, 2, INF, INF, 0}};
    int dp[MAX][MAX];

    allPaths(cost, dp, n);

    printf("All-pairs shortest paths:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}
