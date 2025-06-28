#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0

typedef struct node
{
    int vertex;
    struct node *link;
} node;

node *graph[MAX_VERTICES];
int visited[MAX_VERTICES];

node *create_node(int v)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->vertex = v;
    new_node->link = NULL;
    return new_node;
}

void dfs(int v)
{
    node *w;
    visited[v] = TRUE;
    printf("%d ", v);

    for (w = graph[v]; w != NULL; w = w->link)
    {
        if (!visited[w->vertex])
        {
            dfs(w->vertex);
        }
    }
}

void add_edge(int u, int v)
{
    node *new_node = create_node(v);
    new_node->link = graph[u];
    graph[u] = new_node;

    new_node = create_node(u);
    new_node->link = graph[v];
    graph[v] = new_node;
}

void init_visited()
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        visited[i] = FALSE;
    }
}

int main()
{
    int vertices, edges;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    init_visited();

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    printf("DFS traversal starting from vertex 0:\n");
    dfs(0);

    return 0;
}
