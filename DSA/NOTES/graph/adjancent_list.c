#include <stdio.h>
#include <stdlib.h>

int no_vertices;

struct node
{
    int data;
    struct node *next;
};

void readgraph(struct node *ad[])
{
    struct node *newnode;
    int i, j, k, data;

    for (i = 0; i < no_vertices; i++)
    {
        struct node *last = NULL;
        printf("\nEnter the number of neighbors of %d: ", i);
        scanf("%d", &k);

        for (j = 0; j < k; j++)
        {
            printf("Enter the value of %d neighbor of %d: ", j + 1, i);
            scanf("%d", &data);

            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;
            newnode->next = NULL;

            if (ad[i] == NULL)
            {
                ad[i] = newnode;
            }
            else
            {
                last->next = newnode;
            }

            last = newnode;
        }
    }
}

void printgraph(struct node *ad[])
{
    struct node *ptr = NULL;
    int i;

    for (i = 0; i < no_vertices; i++)
    {
        ptr = ad[i];
        printf("\nThe neighbors of %d are: ", i);
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int i, ch;
    printf("Enter the total number of vertices: ");
    scanf("%d", &no_vertices);

    struct node *adj[no_vertices];

    for (i = 0; i < no_vertices; i++)
    {
        adj[i] = NULL;
    }

    readgraph(adj);

    do
    {
        printf("\nEnter 1 to Print the adjacency list\nEnter 2 to Exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printgraph(adj);
            break;
        case 2:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (ch != 2);

    return 0;
}