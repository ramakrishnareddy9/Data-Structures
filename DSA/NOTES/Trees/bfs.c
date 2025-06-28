#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
struct queue
{
    struct node *data;
    struct queue *next;
};
struct queue *front = NULL, *rear = NULL;

void enqueue(struct node *a)
{
    struct queue *new_node = (struct queue *)malloc(sizeof(struct queue));
    new_node->data = a;
    new_node->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}

struct node *dequeue()
{
    if (front == NULL)
    {
        printf("queue is empty\n");
        return NULL;
    }
    else
    {
        struct queue *temp = front;
        struct node *node_data = front->data;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        free(temp);
        return node_data;
    }
}

int peek(int key)
{
    if (front == NULL)
    {
        printf("queue is empty\n");
        return 0;
    }
    else
    {
        struct node *temp = front->data;
        if (temp->data == key)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

struct node *create()
{
    int x;
    printf("enter data (-1 for null): ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->left = new_node->right = NULL;
    printf("enter left child of %d:\n", x);
    new_node->left = create();
    printf("enter right child of %d:\n", x);
    new_node->right = create();
    return new_node;
}

void bfs(int key)
{
    while (front != NULL)
    {
        struct node *b = dequeue();
        if (b == NULL)
        {
            continue;
        }
        printf("%d ", b->data);
        if (b->data == key)
        {
            printf("\nelement %d found\n", key);
            return;
        }
        if (b->left != NULL)
        {
            enqueue(b->left);
        }
        if (b->right != NULL)
        {
            enqueue(b->right);
        }
    }
    printf("\nelement %d not found\n", key);
}

int main()
{
    struct node *root = create();
    if (root != NULL)
    {
        enqueue(root);
        bfs(9);
    }
    return 0;
}