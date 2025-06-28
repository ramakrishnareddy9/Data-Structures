#include<stdio.h>
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int data = 11;
    int l = 0,r = 10 - 1 ,mid = 0, found = 0;
    while(l <= r){
        mid = (l + r) / 2;
        if(data == a[mid]){
            printf("the position is %d",mid);
            found = 1;
            break;
        }
        else if(data < a[mid]){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    if(!found){
        printf("data does not exist\n");
    }

    return 0;
}