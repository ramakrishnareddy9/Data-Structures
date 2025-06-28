#include <stdio.h>
#include <stdlib.h>

struct node
{
    char name[100];
    int count;
    struct node *next;
    struct node *previous;
};

struct node *front = NULL, *rear = NULL, *current, *next, *temp;

void enqueue(int name[])
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    for (int i = 0; name[i] != '\0'; i++)
    {
        newnode->name[i] = name[i];
    }
    newnode->next = NULL;
    newnode->previous = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
        rear->next = front;
        front->previous = rear;
    }
    else
    {
        rear->next = newnode;
        newnode->previous = rear;
        newnode->next = front;
        rear = newnode;
        front->previous = rear;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
        front->previous = rear;
    }
    free(temp);
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

void no_same_name()
{
    struct node *current = front;
    while (current != NULL)
    {
        current->count = 1;
        struct node *next = current->next;
        while (next != NULL)
        {
            if (strcmp_(current->name, next->name) == 0)
            {
                current->count++;
                struct node *temp = next;
                next = next->next;
                if (temp->previous != NULL)
                {
                    temp->previous->next = temp->next;
                }
                if (temp->next != NULL)
                {
                    temp->next->previous = temp->previous;
                }
                free(temp);
            }
            else
            {
                next = next->next;
            }
        }
        current = current->next;
    }
}

void display()
{
    struct node *current = front;
    while (current != NULL)
    {
        printf("%s (count: %d)\n", current->name, current->count);
        current = current->next;
    }
}

int main()
{
    int n;
    printf("Enter number of names: ");
    scanf("%d", &n);

    char name[100];
    printf("Enter the names:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name);
        enqueue(name);
    }

    no_same_name();
    print_queue();
    return 0;
}