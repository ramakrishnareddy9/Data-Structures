#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *newnode, *temp;
    head = NULL;
    int choice = 0;

    while (choice==0) {
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
        printf("to enter a new node press 0 to exit press 1");
        scanf("%d", &choice);
    }
    // reverse a singley linked list
    struct node *pervious_node,*current_node,*next_node;
    pervious_node = NULL;
    current_node = head;
    next_node = head;
    while(next_node != NULL){
        next_node = next_node->next;
        current_node->next = pervious_node;
        pervious_node = current_node;
        current_node = next_node;
    }
    head=pervious_node;
// display
    temp = head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
int p=19;
    return 0;
}
