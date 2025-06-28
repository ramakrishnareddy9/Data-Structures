#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
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

int dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }

    struct node *temp = front;
    int a = front->data;

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
    return a;
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    int a = dequeue();
    printf("%d\n", a);
    display();
    return 0;
}
