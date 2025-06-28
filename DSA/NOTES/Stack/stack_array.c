#include<stdio.h>
#define n 5
int stack[n];
int top = -1;

void push(){
    int x;
    if(top == n-1){
        printf("stack is full\n");
    }
    else{
        for(int i = 0; i< n;i++){
            printf("entre the value :");
            scanf("%d",&x);
            top++;
            stack[top] = x;
        }
    }
}
int pop(){
    if(top == -1){
        printf("No data in stack");
        return -1;
    }
    else{
        int x = stack[top];
        top--;
        return x;
    }
}
int peek(){
    int x;
    if(top == -1){
        printf("stack is empty");
        return -1;
    }
    else{
        return stack[top];
    }
}
void display(){
    printf("1. Print stack from beginning\n2. Print stack from end\n");
    int p;
    scanf("%d", &p);
    switch (p) {
        case 1:
            for (int i = 0; i <= top; i++) {
                printf("%d ", stack[i]);
            }
            printf("\n");
            break;
        case 2:
            for (int i = top; i >= 0; i--) {
                printf("%d ", stack[i]);
            }
            printf("\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}
int main(){
    int a = 1, b, c;
    while(a != 0){
        printf("1.push\n2.pop\n3.peek\n4.display\nenter 0 to exit\n");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            push();
            break;
        case 2:
            b = pop();
            printf("%d\n",b);
            break;
        case 3:
            c = peek();
            printf("%d",c);
            break;
        case 4:
            display();
            break;
        default:
            break;
        }
    }
    return 0;
}