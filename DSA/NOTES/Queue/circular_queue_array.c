#include<stdio.h>

#define N 10
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if((rear + 1) % N == front){
        printf("queue is full \n");
    }
    else{
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

int dequeue(){
    if(front == -1 && rear == -1){
        printf("queue is empty \n");
        return -1;
    }
    else if(front == rear){
        int a = queue[rear];
        front = rear = -1;
        return a;
    }
    else{
        int a = queue[front];
        front = (front + 1) % N;
        return a;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("queue is empty \n");
    }
    else{
        int i = front;
        while(i != rear){
            printf("%d ",queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n",queue[rear]);
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    int a = dequeue();
    printf("%d\n",a);
    display();
    return 0;
}