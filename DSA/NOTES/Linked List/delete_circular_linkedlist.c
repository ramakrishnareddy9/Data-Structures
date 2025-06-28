#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *newnode, *temp, *head = NULL, *tail, *previous;
    int choose = 0, count = 0;
    while (choose != 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
            newnode->next = head;
        }
        else
        {
            temp->next = newnode;
            newnode->next = head;
            temp = newnode;
            tail = newnode;
        }
        printf("select 0 to enter new node and 1 to stop :");
        scanf("%d", &choose);
        count++;
    }
    int p;
    printf("1.delete at begining\n2.delete at end\n3.delete at ith position\n");
    scanf("%d", &p);
    switch (p)
    {
    case 1: // delete at begining
        if (head != NULL)
        {
            if (head == tail)
            {
                free(head);
                head = tail = NULL;
            }
            else
            {
                temp = head;
                head = head->next;
                tail->next = head;
                free(temp);
            }
        }
        else
        {
            printf("linked list does not exist ");
        }
        break;
    case 2: // delete at end
        if (head != NULL)
        {
            if (head == tail)
            {
                free(head);
            }
            else
            {
                temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = head;
                free(tail);
                tail = temp;
            }
        }
        break;
    case 3: // delete at ith position
        printf("enter position :");
        int pos;
        scanf("%d", &pos);
        if (pos > count + 1 || pos < 1)
        {
            printf("invalide position");
        }
        else if (pos == 1)
        {
            if (head != NULL)
            {
                if (head == tail)
                {
                    free(head);
                    head = tail = NULL;
                }
                else
                {
                    temp = head;
                    head = head->next;
                    tail->next = head;
                    free(temp);
                }
            }
            else
            {
                printf("linked list does not exist ");
            }
        }
        else
        {
            previous = head;
            for (int i = 1; i < pos - 1; i++)
            {
                previous = previous->next;
            }
            temp = previous->next;
            previous->next = temp->next;
            if (temp == tail)
            {
                tail = previous;
            }
            free(temp);
        }
        break;
    default:
        break;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        if (temp == head)
        {
            break;
        }
    }

    return 0;
}