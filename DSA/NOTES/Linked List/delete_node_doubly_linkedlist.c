#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *previous;
};
int main(){
    struct node *head,*newnode,*temp;
    struct node *tail;
    int choice = 0, count=0;
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
        tail = newnode;
        count++;
    }
    int p;
    printf("1.delete at begining\n2. at end\n3.at ith position\n");
    scanf("%d" ,&p);
    switch (p)
    {
    case 1: // delete node at  begining 
        temp = head;
        head = temp->next;
        head->previous = NULL;
        free(temp);
        break;
    case 2: // delete node at end
        temp = tail;
        tail = tail->previous;
        tail->next = NULL;
        free(temp);
        break;
    case 3: // delete at ith position
        printf("enter the position :");
        int pos;
        scanf("%d" ,&pos);
        temp = head;
        if(pos == 1){
            temp = head;
            head = temp->next;
            head->previous = NULL;
            free(temp);
        }
        else if(pos > count){
            printf("invalid position ");
        }
        else{ 
            for(int i = 1; i < pos; i++){
                temp = temp->next;
            }
            if(temp->next != NULL){
                temp->next->previous = temp->previous;
                temp->previous->next = temp->next;
            }
            else{
                temp->previous = NULL;
            }
            free(temp);
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
    }
    return 0;
}