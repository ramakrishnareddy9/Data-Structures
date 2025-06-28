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
    if(front == NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    if(front == NULL && rear == NULL){
        printf("queue is empty");
    }
    else{
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}

void display(){
    if(front == NULL && rear == NULL){
        printf("queue is empty");
    }
    else{
        struct node *temp;
        temp = front;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    display();
    return 0;
}
