#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 999999

int selectMinVertex(int key[], int mstSet[], int V)
{
    int min = INF, index = -1;
    for (int i = 0; i < V; i++)
    {
        if (!mstSet[i] && key[i] < min)
        {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void primMST(int graph[MAX][MAX], int V)
{
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = selectMinVertex(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total weight = %d\n", total);
}

int main()
{
    int V, i, j;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    primMST(graph, V);

    return 0;
}

// Enter number of vertices : 6
// Enter adjacency matrix : 0 3 0 0 6 5
// 3 0 1 0 0 4
// 0 1 0 6 0 4
// 0 0 6 0 8 5
// 6 0 0 8 0 2
// 5 4 4 5 2 0