#include <stdio.h>
#include <stdlib.h>

// Function to find maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Dynamic Programming solution for 0-1 Knapsack
int knapsack_01(int n, int W, int *values, int *weights)
{
    // Allocate 2D DP table
    int **dp = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    // Initialize base cases
    for (int w = 0; w <= W; w++)
    {
        dp[0][w] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int result = dp[n][W];

    // Free allocated memory
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main()
{
    // Test case
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = 3;

    int opt_value = knapsack_01(n, W, values, weights);
    printf("Optimal value (DP): %d\n", opt_value); // Should output 220

    return 0;
}