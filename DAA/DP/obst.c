#include <stdio.h>
#include <float.h>

#define MAX 100

int a;
double P[MAX], Q[MAX];
double dp[MAX][MAX];
int calculated[MAX][MAX];
int root[MAX][MAX];

double sum(double P[], double Q[], int i, int j)
{
    double total = 0;
    for (int k = i + 1; k <= j; k++)
    {
        total += P[k];
    }
    for (int k = i; k <= j; k++)
    {
        total += Q[k];
    }
    return total;
}

double obst_memo(double P[], double Q[], int i, int j)
{
    if (i == j)
    {
        root[i][j] = 0;
        return Q[i];
    }

    if (calculated[i][j])
    {
        return dp[i][j];
    }

    double min_cost = DBL_MAX;
    int best_root = -1;

    for (int r = i + 1; r <= j; r++)
    {
        double left = obst_memo(P, Q, i, r - 1);
        double right = obst_memo(P, Q, r, j);
        double cost = left + right;

        if (cost < min_cost)
        {
            min_cost = cost;
            best_root = r;
        }
    }

    dp[i][j] = min_cost + sum(P, Q, i, j);
    calculated[i][j] = 1;
    root[i][j] = best_root;
    return dp[i][j];
}

void print_cost_matrix(int N)
{
    printf("\nCost Matrix (C values):\n");
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i > j)
                printf("   -   ");
            else
                printf("%6.2lf ", dp[i][j]);
        }
        printf("\n");
    }
}

void print_root_matrix(int N)
{
    printf("\nRoot Matrix:\n");
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i > j)
                printf("  - ");
            else
                printf("%3d ", root[i][j]);
        }
        printf("\n");
    }
}

void print_structure(int i, int j, int parent, int isLeft)
{
    int r = root[i][j];
    if (r == 0 || i > j)
        return;

    if (parent == -1)
        printf("Key%d is root\n", r);
    else if (isLeft)
        printf("Key%d is left child of Key%d\n", r, parent);
    else
        printf("Key%d is right child of Key%d\n", r, parent);

    print_structure(i, r - 1, r, 1);
    print_structure(r, j, r, 0);
}

int main()
{
    int N = 4;
    double P_vals[] = {0, 0.15, 0.10, 0.05, 0.10};
    double Q_vals[] = {0.05, 0.10, 0.05, 0.05, 0.10};

    for (int i = 0; i <= N; i++)
    {
        P[i] = P_vals[i];
        Q[i] = Q_vals[i];
    }

    a = N;

    double result = obst_memo(P, Q, 0, a);
    printf("Minimum cost of OBST (memoized recursion): %.2lf\n", result);

    print_cost_matrix(a);
    print_root_matrix(a);
    printf("\nOBST Structure:\n");
    print_structure(0, a, -1, 0);

    return 0;
}