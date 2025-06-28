#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *previous;
};
int main(){
    struct node *head,*newnode,*temp;
    struct node *current,*next;
    int choice = 0;
    head = NULL;
    while(choice != 1){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data ");
        scanf("%d" ,&newnode->data);
        newnode->previous = NULL;
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            temp = newnode;
        }
        else{
            temp->next = newnode;
            newnode->previous = temp;
            temp = newnode;
        }
        printf("select 0 to enter a new node or 1 to exit :");
        scanf("%d" ,&choice);
    }
    // reverse
    current = head; 
    while(current != NULL){
        next = current->next;
        current->next = current->previous;
        current->previous = next;
        head = current;
        current = next;
    }
    // print
    temp = head; 
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}