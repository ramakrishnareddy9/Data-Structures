#include <stdio.h>

#define MAX 10

int AM[MAX][MAX]; // Adjacency Matrix
int sol[MAX];     // Colors for each vertex
int MaxColor;     // Maximum number of colors
int count = 0;

int ValidColor(int v)
{
    for (int i = 1; i < v; i++)
    {
        if (sol[i] == sol[v] && AM[i][v])
            return 0;
    }
    return 1;
}

void PrintSolution(int n)
{
    count++;
    printf("Solution %d: ", count);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", sol[i]);
    }
    printf("\n");
}

void GraphColor(int v, int n)
{
    for (int color = 1; color <= MaxColor; color++)
    {
        sol[v] = color;
        if (ValidColor(v))
        {
            if (v == n)
                PrintSolution(n);
            else
                GraphColor(v + 1, n);
        }
    }
}

int main()
{
    int n = 4;
    MaxColor = 3;

    for (int i = 1; i <= n; i++)
    {
        sol[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            AM[i][j] = 0;
        }
    }

    AM[1][2] = AM[2][1] = 1;
    AM[1][3] = AM[3][1] = 1;
    AM[2][4] = AM[4][2] = 1;
    AM[3][4] = AM[4][3] = 1;

    GraphColor(1, n);

    printf("Total solutions: %d\n", count);

    return 0;
}