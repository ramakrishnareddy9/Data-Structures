#include<stdio.h>

int stack[1000];
int top = -1,n;

void push(int x){
    if(top == n-1){
        printf("stack is full\n");
    }
    else{
        top++;
        stack[top] = x;
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

void bubble_sort(int a[],int n){
    for(int i = 0;i < n -1;i++){
        int flag = 0;
        for(int j = 0;j < n - i -1;j++){
            if(a[j] < a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
    }
}

int main(){
    printf("enter no.of cable wires\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the cable wires length\n");
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    for(int i = 0;i < n; i++){
        push(a[i]);
    }
    int result = 0;
    for(int i = 0;i < n;i++){
        result += pop(); 
    }
    printf("result = %d",result);

    return 0;
}