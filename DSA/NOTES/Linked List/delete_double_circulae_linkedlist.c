#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *previous;
};

int main() {
    struct node *head = NULL, *newnode, *temp, *tail = NULL;
    int choice = 0 ,count = 0;
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
        count++;
    }
    int p;
    printf("1.insertion at begining\n2.insert at end\n3.insert at ith position\n");
    scanf("%d",&p);
    switch (p)
    {
    case 1:
        temp = head;
        if(head == NULL){
            printf("list is empty");
        }
        else if(head->next == NULL){
            head = tail = NULL;
            free(temp);
        }
        else{
            head = head->next;
            head->previous = tail;
            tail->next = head;
            free(temp);
        }
        break;
    case 2:
        temp = tail;
        if(head == NULL){
            printf("list is empty");
        }
        else if(head->next == NULL){
            head = tail = NULL;
            free(temp);
        }
        else{
            tail = tail->previous;
            tail->next = head;
            head->previous = tail;
            free(temp);
        }
        break;
    case 3:
        printf("enter the position :");
        int pos;
        scanf("%d",&pos);
        if(pos < 1 || pos > count){
            printf("invalid position");
        }
        else if(pos == 1){
            temp = head;
            if(head == NULL){
                printf("list is empty");
            }
            else if(head->next == NULL){
                head = tail = NULL;
                free(temp);
            }
            else{
                head = head->next;
                head->previous = tail;
                tail->next = head;
                free(temp);
            }
        }
        else{
            temp = head;
            for(int i = 1;i < pos;i++){
                temp = temp->next;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            if(temp->next == head){
                tail = temp->previous;
                free(temp);
            }
            else{
                free(temp);
            }
        }
        
        break;
    default:
        break;
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
