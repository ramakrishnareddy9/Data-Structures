#include<stdio.h>

#define N 10
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int a){
    if(rear == N-1){
        printf("queue is full");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = a;
    }
    else{
        rear++;
        queue[rear] = a;
    }
}

int dequeue(){
    if(front == -1){
        printf("queue is empty ");
    }
    else if(rear == front){
         rear = front = -1;
    }
    else{
        int x = queue[front];
        front++;
        return x; // as x is removed
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("queue is empty");
    }
    else{
        for(int i = front;i <= rear;i++){
            printf("%d ",queue[i]);
        }
    }
}

void peek(){
    if(front == -1 && rear == -1){
         printf("queue is empty");
    }
    else{
        printf("%d ",queue[front]);
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    int x = dequeue();
    printf("%d\n",x);
    display();
    return 0;
}
