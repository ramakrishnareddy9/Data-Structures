#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
struct node *head = NULL, *newnode, *tail = NULL;

void create(int n)
{
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->previous = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->previous = tail;
            tail = newnode;
        }
    }
}

void sort()
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

void remove_duplicates()
{
    struct node *current = head, *temp;

    while (current != NULL && current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            temp = current->next;
            current->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->previous = current;
            }
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}

void palindrome()
{
    struct node *a = head, *b = tail;
    int found = 0;
    while (a != NULL && b != NULL)
    {
        if (a->data != b->data)
        {
            found = 1;
            break;
        }
        a = a->next;
        b = b->previous;
    }
    if (!found)
    {
        printf("the list is palindrome\n");
    }
    else
    {
        printf("the list is not palindrome\n");
    }
}

void equal_to_k(int k)
{
    struct node *a = head;
    struct node *b;
    int found = 0;

    while (a != NULL)
    {
        b = a->next;
        while (b != NULL)
        {
            if (a->data + b->data == k)
            {
                printf("(%d,%d)\t", a->data, b->data);
                found = 1;
            }
            b = b->next;
        }
        a = a->next;
    }

    if (!found)
    {
        printf("no pairs found that sum to %d\n", k);
    }
    printf("\n");
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    create(n);
    printf("the list: ");
    display();
    sort();
    printf("the sorted list is: ");
    display();
    remove_duplicates();
    printf("list without duplicates is: ");
    display();
    palindrome();
    equal_to_k(k);
    return 0;
}