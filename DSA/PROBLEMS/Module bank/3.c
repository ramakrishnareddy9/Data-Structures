#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL, *newnode, *temp, *temp1;

int Twin_sum(int n){
    if(n % 2 != 0){
        return -1;
    }
    else{
        temp = head;
        int max = INT_MIN;
        for(int i = 0; i < (n/2)-1; i++){
            int a = n - 1 - i;
            temp1 = head;
            for(int j = 0;j < a;j++){
                temp = temp->next;
            }
            int x = temp->data + temp1->data;
            if(x > max){
                max = x;
            }
        }
        return max;
    }
}

int main(){
    int choice = 0 , count = 0;
    while (choice==0) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode; 
        } 
        else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("to enter a new node press 0 to exit press 1");
        scanf("%d", &choice);
        count++;
    }

    temp = head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    int result = Twin_sum(count);
    printf("%d",result);
    return 0;
}