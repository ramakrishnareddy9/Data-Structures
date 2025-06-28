#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int x){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop(){
    struct node *temp;
    if(top == NULL){
        printf("stack is empty\n");
        return -1;
    }
    else{
        int x;
        temp = top;
        x = top->data;
        top = top->next;
        free(temp);
        return x;
    }
}

int peek(){
    if(top == NULL){
        printf("stack is empty\n");
        return -1;
    }
    else{
        return top->data;
    }
}

void display(){
    struct node *temp;
    temp = top;
    if(temp == NULL){
        printf("stack is empty\n");
    }
    else{
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    int a = peek();
    printf("peek = %d\n",a);
    int b = pop();
    printf("pop = %d\n",b);
    display();
    return 0;
}