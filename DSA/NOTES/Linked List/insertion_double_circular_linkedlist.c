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
    case 1://insert at begining
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data :");
        scanf("%d",&newnode->data);
        if(head == NULL){
            head = tail = newnode;
            newnode->previous = tail;
            newnode->next = head;
        }
        else{
            newnode->next = head;
            head->previous = newnode;
            newnode->previous = tail;
            tail->next = newnode;
            head = newnode;
        }
        break;
    case 2:
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data :");
        scanf("%d",&newnode->data);
        if(head == NULL){
            head = tail = newnode;
            newnode->previous = tail;
            newnode->next = head;
        }
        else{
            newnode->previous = tail;
            tail->next = newnode;
            newnode->next = head;
            head->previous = newnode;
            tail = newnode;
        }
    case 3:
        printf("enter the position :");
        int pos;
        scanf("%d",&pos);
        if(pos < 1 || pos > count){
            printf("invalid position");
        }
        else if(pos == 1){
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter the data :");
            scanf("%d",&newnode->data);
            if(head == NULL){
                head = tail = newnode;
                newnode->previous = tail;
                newnode->next = head;
            }
            else{
                newnode->next = head;
                head->previous = newnode;
                newnode->previous = tail;
                tail->next = newnode;
                head = newnode;
            }
        }
        else{
            temp = head;
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter the data :");
            scanf("%d",&newnode->data);
            for(int i = 1; i < pos - 1; i++){
                temp = temp->next;
            }
            newnode->previous = temp;
            newnode->next = temp->next;
            temp->next->previous = newnode;
            temp->next = newnode;
        }
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
