#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define FALSE 0
#define TRUE 1

typedef struct node
{
    int vertex;
    struct node *link;
} node_pointer;

typedef struct queue
{
    int vertex;
    struct queue *link;
} queue_pointer;

int visited[MAX_VERTICES];
node_pointer *graph[MAX_VERTICES];

queue_pointer *createQueue()
{
    queue_pointer *q = (queue_pointer *)malloc(sizeof(queue_pointer));
    q->link = NULL;
    return q;
}

void addq(queue_pointer **front, queue_pointer **rear, int v)
{
    queue_pointer *newNode = (queue_pointer *)malloc(sizeof(queue_pointer));
    newNode->vertex = v;
    newNode->link = NULL;
    if (*rear == NULL)
    {
        *front = *rear = newNode;
    }
    else
    {
        (*rear)->link = newNode;
        *rear = newNode;
    }
}

int deleteq(queue_pointer **front)
{
    if (*front == NULL)
    {
        return -1; // Queue is empty
    }
    int vertex = (*front)->vertex;
    queue_pointer *temp = *front;
    *front = (*front)->link;
    free(temp);
    return vertex;
}

void addEdge(node_pointer **graph, int src, int dest)
{
    node_pointer *newNode = (node_pointer *)malloc(sizeof(node_pointer));
    newNode->vertex = dest;
    newNode->link = graph[src];
    graph[src] = newNode;
}

void readGraph(node_pointer **graph, int vertices)
{
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
}

void bfs(int v)
{
    node_pointer *w;
    queue_pointer *front = NULL, *rear = NULL;

    printf("%d ", v);
    visited[v] = TRUE;
    addq(&front, &rear, v);

    while (front)
    {
        v = deleteq(&front);
        for (w = graph[v]; w; w = w->link)
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
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++)
    {
        graph[i] = NULL;
        visited[i] = FALSE;
    }

    readGraph(graph, vertices);

    printf("BFS Traversal starting from vertex 0:\n");
    bfs(0);

    return 0;
}
