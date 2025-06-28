#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *newnode, *temp;
    head = NULL;
    int choice = 0, count = 0;

    // Create the linked list by adding nodes
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
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("To enter a new node press 0, to exit press 1: ");
        scanf("%d", &choice);
        count++;
    }

    // Choose an insertion operation
    int p;
    printf("Enter 1 to insert at the beginning \n2 to insert at the end \n3 to insert at a specific position.\n");
    scanf("%d", &p);

    switch (p) {
        case 1: // Insert at beginning
            newnode = (struct node*)malloc(sizeof(struct node));
            if (newnode == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
            printf("Enter the value to insert: ");
            scanf("%d", &newnode->data);
            newnode->next = head;
            head = newnode;
            break;

        case 2: // Insert at end
            newnode = (struct node*)malloc(sizeof(struct node));
            if (newnode == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
            printf("Enter the value to insert: ");
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            break;

        case 3: // Insert at a specific position
            printf("Enter the position to insert at (starting from 0): ");
            int pos;
            scanf("%d", &pos);
            if (pos < 0 || pos > count) {
                printf("Invalid position\n");
                break;
            }
            newnode = (struct node*)malloc(sizeof(struct node));
            if (newnode == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
            printf("Enter the value to insert: ");
            scanf("%d", &newnode->data);

            if (pos == 0) {
                newnode->next = head;
                head = newnode;
            } else {
                temp = head;
                for (int i = 0; i < pos - 1; i++) {
                    temp = temp->next;
                }
                newnode->next = temp->next;
                temp->next = newnode;
            }
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    // Print the linked list
    temp = head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
