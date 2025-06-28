#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *previous;
};
int main(){
    struct node *head,*newnode,*temp;
     struct node *tail; //store address of last node & mainly used for insertion 
    int choice = 0, count = 0;// count used in case 3,4
    head = NULL;
    while(choice != 1){
        newnode = (struct node*)malloc(sizeof(struct node));
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
            tail = newnode; // used to store address of last node
        }
        printf("select 0 to enter a new node or 1 to exit :");
        scanf("%d" ,&choice);
        count++;
    }
    int p;
    printf("1. insert at bedining\n2.insert at end\n3. insert at ith position\n");
    scanf("%d" ,&p);
    switch (p)
    {
    case 1:// insert at begining
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter new node data :");
        scanf("%d" ,&newnode->data);
        newnode->next = head;
        newnode->previous = NULL;
        if(head == NULL){
            head = newnode;
        }
        else{
            head->previous=newnode;
            head = newnode;
        }
        break;
    case 2:// inserting at end 
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter new node data :");
        scanf("%d" ,&newnode->data);
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            newnode->previous = NULL;
        }
        else{
            newnode->previous = tail;
            tail->next = newnode;
            tail = newnode;
        }
    case 3:// insert at ith position 
        printf("enter the position :");
        int pos;
        scanf("%d" ,&pos);
        if(pos < 1 || pos > count){
            printf("in valid position number ");
        }
        else if(pos == 1){
           newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter new node data :");
            scanf("%d" ,&newnode->data);
            newnode->next = head;
            newnode->previous = NULL;
            if(head == NULL){
                head = newnode;
            }
            else{
                head->previous=newnode;
                head = newnode;
            }
        }
        else{
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter new node data :");
            scanf("%d" ,&newnode->data);
            temp = head;
            for(int i = 1; i < pos-1; i++){
                temp = temp->next;
            }
            newnode->previous = temp;
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->next->previous = newnode;
        }
    default:
        break;
    }
    temp = head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}