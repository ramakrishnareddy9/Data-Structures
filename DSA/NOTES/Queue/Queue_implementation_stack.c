#include<stdio.h>

#define N 10
int s1[N];
int s2[N];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int x){
    if(top1 == N-1){
        printf("Queue is full");
    }
    else{
        top1++;
        s1[top1] = x;
    }
}

int pop1(){
    return s1[top1--];
}

void push2(int x){
    if(top2 == N-1){
        printf("Queue is full");
    }
    else{
        top2++;
        s2[top2] = x;
    }
}

int pop2(){
    return s2[top2--];
}

void enqueue(int x){
    push1(x);
    count++;
}

int dequeue(){
    if(top1 == -1 && top2 == -1){
        printf("the stack is empty");
    }
    else{
        for(int i = 0;i < count;i++){
            int a = pop1();
            push2(a);
        }
        int b = pop2();
        count--;
        for(int i = 0;i < count;i++){
            int a = pop2();
            push1(a);
        }
        return b;
    }
}

void display(){
    for(int i = 0;i <= top1;i++){
        printf("%d ",s1[i]);
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    int c = dequeue();
    printf("%d\n",c);
    display();
    return 0;
}