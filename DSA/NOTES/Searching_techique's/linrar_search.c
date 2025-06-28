#include<stdio.h>
int main(){
    int data = 2,n,found = 0;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n;i++){
        scanf("%d",&a[i]);
    }

    for(int i = 0; i < n;i++){
        if(a[i] == data){
            printf("the data fount at position %d",i);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("data does not exist\n");
    }
    return 0;
}