#include<stdio.h>

int stack[1000];
int top = -1;

void inner_sort(int a[], int current, int j) {
    if (j >= 0 && current < a[j]) {
        a[j + 1] = a[j];
        j--;
        inner_sort(a, current, j);
    }
    else 
    {
        a[j + 1] = current;
        return;
    }
}

void insertion_sort(int a[], int n, int i) {
    if (i == n) {
        return;
    }
    else
    {
        int current = a[i];
        int j = i - 1;
        inner_sort(a, current, j);
        insertion_sort(a, n, i + 1);
    }
}

void push(int x) {
    if (top == 1000 - 1) {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int main() {
    int n;
    printf("Enter number of gifts\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the gift number from top to bottom\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        push(a[i]);
    }
    insertion_sort(stack, n, 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", stack[i]);
    }
    return 0;
}
