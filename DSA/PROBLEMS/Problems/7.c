#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;
int count = 0, count1 = 0;

void sort(int a[], int m);
void queries(int a[], int m, int n);
void display(int a[], int m);
void sort_a();
void remove_a(int a[], int *m);
void create_a(int a[], int m);
void display_a();
void queries_a(int a[], int m, int n);

int main()
{
    int n, m;
    printf("enter the size of the list: ");
    scanf("%d", &m);
    int a[m];
    create_a(a, m);
    printf("enter no.of queries: ");
    scanf("%d", &n);
    queries_a(a, m, n);
    printf("Linked list: ");
    display_a();
    printf("Array: ");
    display(a, m);
    return 0;
}

void create_a(int a[], int m)
{
    for (int i = 0; i < m; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        int data;
        scanf("%d", &data);
        a[i] = data;
        newnode->data = data;
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
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display(int a[], int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void queries_a(int a[], int m, int n)
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
            count1++;
            sort_a();
            sort(a, m);
        }
        if (b == 'R')
        {
            remove_a(a, &m);
        }
        printf("For query %d, the number of operations using array are %d\n", i + 1, count);
        printf("For query %d, the number of operations using linked list are %d\n", i + 1, count1);
        count = 0;
        count1 = 0;
    }
}

void remove_a(int a[], int *m)
{
    sort_a();
    temp = head;
    head = head->next;
    free(temp);
    count1 += 2;

    int min = INT_MAX, j = 0;
    for (int i = 0; i < *m; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            j = i;
        }
    }
    count++;
    for (int i = j; i < *m - 1; i++)
    {
        a[i] = a[i + 1];
        count++;
    }
    (*m)--;
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

void sort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}
