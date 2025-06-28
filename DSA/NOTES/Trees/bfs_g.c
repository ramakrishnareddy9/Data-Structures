#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0

typedef struct queue *queue_pointer;

typedef struct queue
{
    int vertex;
    queue_pointer link;
} queue;

int visited[MAX_VERTICES];
queue_pointer graph[MAX_VERTICES];

void addq(queue_pointer *front, queue_pointer *rear, int v)
{
    queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
    temp->vertex = v;
    temp->link = NULL;

    if (*rear == NULL)
    {
        *front = *rear = temp;
    }
    else
    {
        (*rear)->link = temp;
        *rear = temp;
    }
}

int deleteq(queue_pointer *front)
{
    if (*front == NULL)
        return -1;

    int vertex = (*front)->vertex;
    queue_pointer temp = *front;
    *front = (*front)->link;

    free(temp);
    return vertex;
}

void bfs(int start_vertex, int num_vertices)
{
    queue_pointer front = NULL, rear = NULL;
    printf("%d ", start_vertex);
    visited[start_vertex] = TRUE;
    addq(&front, &rear, start_vertex);

    while (front != NULL)
    {
        int v = deleteq(&front);
        for (queue_pointer w = graph[v]; w != NULL; w = w->link)
        {
            if (!visited[w->vertex])
            {
                printf("%d ", w->vertex);
                addq(&front, &rear, w->vertex);
                visited[w->vertex] = TRUE;
            }
        }
    }
}

int main()
{
    int num_vertices, num_edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++)
    {
        graph[i] = NULL;
        visited[i] = FALSE;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges (u v) where u and v are the vertices of the edge:\n");
    for (int i = 0; i < num_edges; i++)
    {
        scanf("%d %d", &u, &v);

        queue_pointer new_node = (queue_pointer)malloc(sizeof(queue));
        new_node->vertex = v;
        new_node->link = graph[u];
        graph[u] = new_node;

        new_node = (queue_pointer)malloc(sizeof(queue));
        new_node->vertex = u;
        new_node->link = graph[v];
        graph[v] = new_node;
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &v);

    printf("BFS starting from vertex %d: ", v);
    bfs(v, num_vertices);

    return 0;
}
