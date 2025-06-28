#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main()
{
    struct node *newnode, *temp, *head = NULL, *tail;
    int choose = 0, count = 0;
    while(choose != 1){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d" ,&newnode->data);
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            temp = newnode;
            newnode->next = head;
        }
        else{
            temp->next = newnode;
            newnode->next = head;
            temp = newnode;
            tail = newnode;
        }
    printf("select 0 to enter new node and 1 to stop :");
    scanf("%d",&choose);
    count++;
    }
    int p;
    printf("1.insert at begining\n2.insert at end\n3.insert at ith position");
    scanf("%d" ,&p);
    switch (p)
    {
    case 1:// insertion at begining
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d" ,&newnode->data);
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            newnode->next = head;
        }
        else{
            newnode->next = head;
            head = newnode;
            tail->next = head; // if we not use tail then we have to use loo lt change last value
        }
        break;
    case 2:// insert at end
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d" ,&newnode->data);
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            newnode->next = head;
        }
        else{
            newnode->next = head;// we can use tail->next 
            tail->next = newnode;
        }
        break;
    case 3://insert at ith position
        printf("enter the position :");
        int pos;
        scanf("%d",&pos);
        if(pos > count+1 || pos < 1){
            printf("invalide position");
        }
        else{
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter data :");
            scanf("%d" ,&newnode->data);
            newnode->next = NULL;
            if(head == NULL){
                head = newnode;
                newnode->next = head;
            }
            if(pos == 1){
                newnode->next = head;
                head = newnode;
                tail->next = head;
            }
            else{
                temp = head;
                for (int i = 1; i < pos - 1; i++) {
                    temp = temp->next;
                }
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
        break;
    default:
        break;
    }
    temp = head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
        if(temp == head){
            break;
        }
    }

    return 0;
}