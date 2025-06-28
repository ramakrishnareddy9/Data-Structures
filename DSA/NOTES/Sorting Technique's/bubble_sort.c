#include<stdio.h>

void bubble_sort(int a[],int n){
    for(int i = 0;i < n -1;i++){
        int flag = 0;
        for(int j = 0;j < n - i -1;j++){
            if(a[j] > a[j + 1]){
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
    int n = 5;
    int a[] = {16,15,6,8,5};
    bubble_sort(a,n);
    for(int i = 0;i < n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}