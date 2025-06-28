#include <stdio.h>
#include <stdlib.h> // 3/4 completed

struct node
{
    int count;
    char name[10];
    struct node *next;
};
struct node *front = NULL, *rear = NULL, *constant, *moving, *temp;
int n;

void enqueue(char a[])
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int i = 0;
    while (a[i] != '\0')
    {
        newnode->name[i] = a[i];
        i++;
    }
    newnode->count = 0;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        struct node *temp_1 = front;
        front = front->next;
        free(temp_1);
    }
}

void dequeue_constant()
{
    if (front == NULL && rear == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        constant = front;
        front = front->next;
        constant->next = NULL;
    }
}

void enqueue_constant()
{
    if (front == NULL && rear == NULL)
    {
        front = rear = constant;
    }
    else
    {
        rear->next = constant;
        rear = constant;
    }
}

void dequeue_moving()
{
    if (front == NULL && rear == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        temp = front;
        front = front->next;
        temp->next = NULL;
    }
}

void enqueue_moving()
{
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int strcmp_(char a[], char b[])
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] < b[i])
        {
            return -1;
        }
        else if (a[i] > b[i])
        {
            return 1;
        }
        i++;
    }
    if (a[i] == '\0' && b[i] != '\0')
    {
        return -1;
    }
    if (a[i] != '\0' && b[i] == '\0')
    {
        return 1;
    }
    return 0;
}

void main_function(int n)
{
    int p = n;
    for (int i = 0; i < n; i++)
    {
        dequeue_constant();
        moving = front;
        while (moving != NULL)
        {
            if (strcmp_(constant->name, moving->name) == 0)
            {
                constant->count++;
                dequeue();
                p--;
            }
            else
            {
                dequeue_moving();
                enqueue_moving();
            }
        }
        enqueue_constant();
    }
    n = p;
}

int main()
{
    printf("enter n value : ");
    scanf("%d", &n);
    int a[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a);
        enqueue(a);
    }

    return 0;
}
