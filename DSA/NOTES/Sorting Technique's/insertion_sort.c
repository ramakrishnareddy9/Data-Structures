#include<stdio.h>

void insertion_sort(int a[],int n){
    for(int i = 1;i < n;i++){
        int current = a[i];
        int j = i - 1;
        while(j >= 0 && current < a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }
}

int main(){
    int n = 5;
    int a[] = {7,8,3,1,2};
    insertion_sort(a,n);
    for(int i = 0;i < n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}