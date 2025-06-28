#include <stdio.h>

#define MAX 100

int G[MAX][MAX]; // Adjacency matrix
int x[MAX];      // Path array
int n;           // Number of vertices

void nextValue(int k)
{
    int j;
    while (1)
    {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0)
            return;

        if (G[x[k - 1]][x[k]] != 0)
        {
            for (j = 1; j < k; j++)
            {
                if (x[j] == x[k])
                    break;
            }

            if (j == k)
            {
                if ((k < n) || (k == n && G[x[n]][x[1]] != 0))
                    return;
            }
        }
    }
}

void hamiltonian(int k)
{
    while (1)
    {
        nextValue(k);
        if (x[k] == 0)
            return;

        if (k == n)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", x[i]);
            }
            printf("%d\n", x[1]); // Complete cycle
        }
        else
        {
            hamiltonian(k + 1);
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
    {
        x[i] = 0;
    }

    x[1] = 1; // Start from vertex 1
    printf("Hamiltonian cycles:\n");
    hamiltonian(2);

    return 0;
}
