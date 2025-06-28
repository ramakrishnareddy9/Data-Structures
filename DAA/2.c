#include <stdio.h>
#include <stdlib.h>

// Structure to hold item details
typedef struct
{
    double value_per_weight;
    int value;
    int weight;
    int index;
} Item;

// Function to find maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Dynamic Programming solution (for OPT)
int knapsack_01(int n, int W, int *values, int *weights)
{
    int **dp = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    for (int w = 0; w <= W; w++)
        dp[0][w] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

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
    for (int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);
    return result;
}

// Comparison function for qsort (descending order of value/weight)
int compare(const void *a, const void *b)
{
    double diff = ((Item *)b)->value_per_weight - ((Item *)a)->value_per_weight;
    return (diff > 0) ? 1 : (diff < 0) ? -1
                                       : 0;
}

// GreedySteal algorithm
int greedy_steal(int n, int W, int *values, int *weights)
{
    // Create array of items
    Item *items = (Item *)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++)
    {
        items[i].value_per_weight = (double)values[i] / weights[i];
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].index = i;
    }

    // Sort by value per weight in decreasing order
    qsort(items, n, sizeof(Item), compare);

    // Find maximum single item value (T)
    int max_value_T = 0;
    for (int i = 0; i < n; i++)
    {
        if (weights[i] <= W && values[i] > max_value_T)
        {
            max_value_T = values[i];
        }
    }

    // Greedy selection
    int total_weight = 0;
    int greedy_value = 0;
    for (int i = 0; i < n; i++)
    {
        if (total_weight + items[i].weight <= W)
        {
            total_weight += items[i].weight;
            greedy_value += items[i].value;
        }
        else
        {
            break;
        }
    }

    // G = max(greedy_value, max_value_T)
    int G = max(greedy_value, max_value_T);

    free(items);
    return G;
}

int main()
{
    // Test case
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = 3;

    // Compute optimal value
    int OPT = knapsack_01(n, W, values, weights);
    printf("Optimal value (OPT): %d\n", OPT); // 220

    // Compute greedy value
    int G = greedy_steal(n, W, values, weights);
    printf("Greedy value (G): %d\n", G); // Should be 180 (60 + 120) or 120, G = 180

    // Verify G >= (1/2) OPT
    double half_OPT = OPT / 2.0;
    printf("1/2 OPT: %.1f\n", half_OPT); // 110.0
    if (G >= half_OPT)
    {
        printf("Bound holds: G >= (1/2) OPT\n");
    }
    else
    {
        printf("Bound does not hold\n");
    }

    return 0;
}