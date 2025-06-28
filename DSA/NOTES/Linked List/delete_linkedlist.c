#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *newnode, *temp;
    struct node *previous; // for case 2
    struct node *nextnode; // for case 3
    head = NULL;
    int choice = 0;

    while (choice == 0) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } 
        else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("To enter a new node press 0; to exit press 1: ");
        scanf("%d", &choice);
    }

    int p;
    printf("1. Delete first node\n2. Delete last node\n3. Delete node at position\n");
    scanf("%d", &p);
    switch (p) {
        case 1: // delete node at 1st position
            temp = head;
            head = head->next;
            free(temp);
            break;
        case 2:
            temp = head;
            while (temp->next != NULL) {
                previous = temp;
                temp = temp->next;
            }
            if (temp == head) { // handle case when there's only one node
                head = NULL;
                free(temp);
            } else {
                previous->next = NULL;
                free(temp);
            }
            break;
        case 3:
            temp = head;
            int pos, i = 1;
            printf("Enter the position: ");
            scanf("%d", &pos);
            while (i < pos - 1) {
                temp = temp->next;
                i++;
            }
            nextnode = temp->next;
            temp->next = nextnode->next;
            free(nextnode);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    temp = head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
