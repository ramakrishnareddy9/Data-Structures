#include<stdio.h>

void selection_sort(int a[],int n){
    for(int i = 0;i < n - 1;i++){
        int smallest = i;
        for(int j = i + 1;j < n;j++){
            if(a[smallest] > a[j]){
                smallest = j;
            }
            int temp = a[smallest];
            a[smallest] = a[i];
            a[i] = temp;
        }
    }
}
int main(){
    int n = 5;
    int a[] = {7,4,18,8,3};
    selection_sort(a,n);
    for(int i = 0;i < n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}