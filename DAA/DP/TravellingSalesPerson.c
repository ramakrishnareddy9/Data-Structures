#include <stdio.h>
#include <limits.h>

#define MAX 16
#define INF 1000000000

int n = 4;
int dist[MAX][MAX] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};

int dp[MAX][1 << MAX];

int tsp(int pos, int mask)
{
    if (mask == (1 << n) - 1)
    {
        return dist[pos][0];
    }

    if (dp[pos][mask] != -1)
    {
        return dp[pos][mask];
    }

    int ans = INF;
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = dist[pos][city] + tsp(city, mask | (1 << city));
            if (newAns < ans)
            {
                ans = newAns;
            }
        }
    }

    dp[pos][mask] = ans;
    return ans;
}

int main()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            dp[i][j] = -1;
        }
    }

    int result = tsp(0, 1);
    printf("Minimum cost of visiting all cities: %d\n", result);

    return 0;
}