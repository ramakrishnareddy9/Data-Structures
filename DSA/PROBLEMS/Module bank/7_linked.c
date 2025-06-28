#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

void sort_a();
void remove_a();
void create_a(int m);
void display_a();
void queries_a(int n);

int main()
{
    int n, m;
    printf("Enter the size of the linked list: ");
    scanf("%d", &m);
    create_a(m);
    printf("Enter number of queries: ");
    scanf("%d", &n);
    queries_a(n);
    display_a();
    return 0;
}

void create_a(int m)
{
    for (int i = 0; i < m; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void display_a()
{
    temp = head;
    printf("The linked list is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void queries_a(int n)
{
    for (int i = 0; i < n; i++)
    {
        char b;
        scanf(" %c", &b);
        int c;
        if (b == 'I')
        {
            scanf("%d", &c);
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = c;
            newnode->next = head;
            head = newnode;
            sort_a();
        }
        if (b == 'R')
        {
            remove_a();
        }
    }
}

void remove_a()
{
    sort_a();
    temp = head;
    head = head->next;
    free(temp);
}

void sort_a()
{
    if (head == NULL)
    {
        return;
    }
    struct node *a, *b = NULL;
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        a = head;
        while (a->next != b)
        {
            if (a->data > a->next->data)
            {
                int temp = a->data;
                a->data = a->next->data;
                a->next->data = temp;
                swapped = 1;
            }
            a = a->next;
        }
        b = a;
    }
}
