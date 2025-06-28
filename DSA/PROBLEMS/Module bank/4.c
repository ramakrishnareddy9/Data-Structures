#include <stdio.h>
#include <stdlib.h> //c bit not completed

struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *temp, *head = NULL, *tail = NULL;
int count = 0;

void create(int N)
{
    for (int i = 0; i < N; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            newnode->next = head;
        }
        else
        {
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;
        }
        count++;
    }
}

void display()
{
    if (head != NULL)
    {
        temp = head;
        printf("The reversed linked list is: ");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
    else
    {
        printf("List is empty.\n");
    }
}

void reverse(int n)
{
    struct node *previous = tail, *current = head, *next = NULL;
    temp = head;
    if (count > n)
    {
        for (int i = 0; i < n; i++)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
        temp->next = current;
        tail->next = head;
    }
    else
    {
        printf("n should be less than %d", count);
    }
}

void printK()
{
    int n;
    printf("Enter the k number: ");
    scanf("%d", &n);
    struct node *current = head, *previous = tail, *temp = NULL;
    int c = 0;
    for (int i = 0; i < count; i++)
    {
        if (c == n)
        {
            printf("%d ", current->data);
            temp = current;
            if (current == head)
            {
                head = head->next;
            }
            previous->next = current->next;
            if (current == tail)
            {
                tail = previous;
            }
            current = current->next;
            free(temp);

            c = 0;
        }
        else
        {
            previous = current;
            current = current->next;
            c++;
        }
        if (current == head && i != 0)
        {
            break;
        }
    }
}

int main()
{
    create(10);
    reverse(5);
    display();
    printK();
    return 0;
}
