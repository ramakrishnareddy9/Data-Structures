#include<stdio.h>

#define N 10
int deque[N];
int front = -1, rear = -1;

void enqueue_front(int x){
    if((front == 0 && rear == N - 1) || (front == rear + 1)){
        printf("deque is full\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        deque[front] = x;
    }
    else if(front == 0){
        front = N - 1;
        deque[front] = x;
    }
    else{
        front--;
        deque[front] = x;
    }
}

void enqueue_rear(int x){
    if((front == 0 && rear == N - 1) || (front == rear + 1)){
        printf("deque is full\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        deque[rear] = x;
    }
    else if(rear == N-1){
        rear = 0;
        deque[rear] = x;
    }
    else{
        rear++;
        deque[rear] = x;
    }
}

int dequeue_front(){
    if(front == -1 && rear == -1){
        printf("deque is empty\n");
        return -1;
    }
    else if(front == rear){
        int x = deque[rear];
        rear = front = -1;
        return x;
    }
    else if(front == N -1){
        int x = deque[front];
        front = 0;
        return x;
    }
    else{
        int x = deque[front];
        front++;
        return x;
    }
}

int dequeue_rear(){
    if(front == -1 && rear == -1){
        printf("deque is empty\n");
        return -1;
    }
    else if(front == rear){
        int x = deque[rear];
        rear = front = -1;
        return x;
    }
    else if(rear == 0){
        int x = deque[rear];
        rear = N - 1;
        return x;
    }
    else{
        int x = deque[rear];
        rear--;
        return x;
    }
}

void display(){
    int i = front;
    while(i != rear){
        printf("%d ",deque[i]);
        i = (i + 1) % N;
    }
    printf("%d\n",deque[rear]);
}

int main(){
    enqueue_front(5);
    enqueue_front(4);
    enqueue_front(1);
    display();
    return 0;
}