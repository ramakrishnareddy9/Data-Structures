#include <stdio.h>
#include <limits.h>

void printOptimalParenthesis(int s[][100], int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }
    printf("(");
    printOptimalParenthesis(s, i, s[i][j]);
    printOptimalParenthesis(s, s[i][j] + 1, j);
    printf(")");
}

void matrixChainMultiplication(int dims[], int n)
{
    int m[100][100], s[100][100];
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\n");
    printf("Minimum number of multiplications: %d\n", m[1][n]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n);
    printf("\n");
}

int main()
{
    int dims[] = {2, 3, 2, 4, 5};
    int n = 4;
    matrixChainMultiplication(dims, n);
    return 0;
}
