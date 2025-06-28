#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *newnode, *temp, *head = NULL, *tail = NULL;
    int choose = 0, count = 0;
    while (choose != 1) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            newnode->next = head; 
        } else {
            tail->next = newnode;
            newnode->next = head; 
            tail = newnode;
        }
        printf("Select 0 to enter new node and 1 to stop: ");
        scanf("%d", &choose);
        count++;
    }
    if (head != NULL) {
        struct node *previous = tail, *current = head, *next = NULL;
        do {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        } while (current != head);
        head = previous; 
        tail = head->next; 
    }

    if (head != NULL) {
        temp = head;
        printf("The reversed linked list is: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    } else {
        printf("List is empty.\n");
    }

    return 0;
}
