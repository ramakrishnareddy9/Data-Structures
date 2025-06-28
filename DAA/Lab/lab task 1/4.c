#include <stdio.h>

int search_2d_matrix(int a[][100], int n, int m, int target)
{
    int i = 0, j = m;
    while (i < n && j >= 0)
    {
        if (a[i][j] == target)
        {
            return 1;
        }
        else if (a[i][j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int target;
    scanf("%d", &target);
    int result = search_2d_matrix(a, n, m, target);
    if (result)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}