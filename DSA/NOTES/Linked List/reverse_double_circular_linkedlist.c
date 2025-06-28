#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *previous;
};

int main() {
    struct node *head = NULL, *newnode, *temp, *tail = NULL;
    int choice = 0;
    while (choice != 1) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->previous = NULL;

        if (head == NULL) {
            head = newnode;
            tail = newnode;
            newnode->next = head;
            newnode->previous = head;
        } else {
            tail->next = newnode;
            newnode->previous = tail;
            newnode->next = head;
            head->previous = newnode;
            tail = newnode;
        }
        printf("Select 0 to enter a new node or 1 to exit: ");
        scanf("%d", &choice);
    }
    
    struct node *current = head;
    struct node *nextnode = NULL;
    if (head != NULL) {
        do {
            nextnode = current->next;
            current->next = current->previous;
            current->previous = nextnode;
            current = current->previous;
        } while (current != head);

        nextnode = head;
        head = tail;
        tail = nextnode;
    }

    temp = head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        if(temp == head){
            break;
        }
    }

    return 0;
}
