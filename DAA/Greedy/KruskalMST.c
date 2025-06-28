#include <stdio.h>

#define MAX 100

int parent[MAX];

int findSet(int u)
{
    while (u != parent[u])
    {
        u = parent[u];
    }
    return u;
}

void unionSets(int u, int v)
{
    int pu = findSet(u);
    int pv = findSet(v);
    parent[pu] = pv;
}

struct Edge
{
    int u, v, weight;
};

void sortEdges(struct Edge edges[], int E)
{
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = i + 1; j < E; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

int main()
{
    int V, E;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter each edge as: u v weight\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    sortEdges(edges, E);

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int totalWeight = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        int pu = findSet(u);
        int pv = findSet(v);

        if (pu != pv)
        {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            totalWeight += edges[i].weight;
            unionSets(pu, pv);
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);
    return 0;
}

// Enter number of vertices : 6
// Enter number of edges : 9
// Enter each edge as : u v weight
// 0 1 4
// 0 2 4
// 1 2 2
// 1 3 5
// 2 3 8
// 2 4 10
// 3 4 2
// 3 5 6
// 4 5 3
