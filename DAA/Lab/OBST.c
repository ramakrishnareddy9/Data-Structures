#include <stdio.h>
#include <float.h>

void OBST(double p[], double q[], int n)
{
    double w[n + 1][n + 1], c[n + 1][n + 1];
    int r[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        w[i][j] = q[i] + q[j] + p[i];
        c[i][j] = w[i][j];
        r[i][j] = j;
    }

    for (int m = 2; m <= n; m++)
    {
        for (int i = 0; i <= n - m; i++)
        {
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
            c[i][j] = DBL_MAX;

            for (int k = i + 1; k <= j; k++)
            {
                double current_cost = c[i][k - 1] + c[k][j] + w[i][j];
                if (current_cost < c[i][j])
                {
                    c[i][j] = current_cost;
                    r[i][j] = k;
                }
            }
        }
    }

    printf("Minimum cost: %f\n", c[0][n]);
}

int main()
{
    double p[] = {3, 3, 1, 1};
    double q[] = {2, 3, 1, 1, 1};
    int n = 4;
    OBST(p, q, n);
    return 0;
}