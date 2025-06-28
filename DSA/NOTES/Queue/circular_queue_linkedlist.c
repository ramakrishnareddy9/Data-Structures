#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;

void enqueue(int x){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(rear == NULL){
        front = rear = newnode;
        rear->next = front;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

int dequeue(){
    struct node *temp = front;
    int a;
    if(front == NULL && rear == NULL){
        printf("queue is empty\n");
        return -1;
    }
    else if(front == rear){
        a = front->data;
        front = rear = NULL;
        free(temp);
    }
    else{
        a = front->data;
        front = front->next;
        rear->next = front;
        free(temp);
    }
    return a;
}

void display(){
    struct node *temp = front;
    if(front == NULL && rear == NULL){
        printf("queue is empty\n");
    }
    else{
        while(temp != rear){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    int a = dequeue();
    printf("%d\n",a);
    display();
    return 0;
}