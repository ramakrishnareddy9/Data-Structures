#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main()
{
    struct node *newnode, *temp, *head = NULL;
    int choose = 0;
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
        }
    printf("select 0 to enter new node and 1 to stop :");
    scanf("%d",&choose);
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