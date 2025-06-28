#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define FALSE 0
#define TRUE 1

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node **adjList;
};

struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjList = (struct Node **)malloc(vertices * sizeof(struct Node *));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void dfs(struct Graph *graph, int v, int *visited)
{
    struct Node *w;
    visited[v] = TRUE;
    printf("%d ", v);

    for (w = graph->adjList[v]; w != NULL; w = w->next)
    {
        if (!visited[w->vertex])
        {
            dfs(graph, w->vertex, visited);
        }
    }
}

int main()
{
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);

    // Reading graph input similar to the second code
    for (int i = 0; i < vertices; i++)
    {
        int numNeighbors;
        printf("\nEnter the number of neighbors for vertex %d: ", i);
        scanf("%d", &numNeighbors);

        for (int j = 0; j < numNeighbors; j++)
        {
            int neighbor;
            printf("Enter neighbor %d of vertex %d: ", j + 1, i);
            scanf("%d", &neighbor);
            addEdge(graph, i, neighbor);
        }
    }

    // Visited array
    int visited[MAX_VERTICES] = {FALSE};

    printf("DFS Traversal starting from vertex 0:\n");
    dfs(graph, 0, visited);

    return 0;
}
