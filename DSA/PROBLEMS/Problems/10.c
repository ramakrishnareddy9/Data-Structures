#include <stdio.h>
#include <limits.h> // not completed
#define n 1000
int stack[n];
int top = -1;

void push(int x)
{
    if (top == n - 1)
    {
        printf("stack is full\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("No data in stack");
        return -1;
    }
    else
    {
        int x = stack[top];
        top--;
        return x;
    }
}

void sort(int a[], int m)
{
    int b[m], c[2 * m];
    int i = 0, j = 0, k = 0;
    int last_push = a[i], last_pop = INT_MIN;
    push(a[i]);
    c[k] = 1;
    k++;
    i++;
    while (i != m)
    {
        if (last_push < a[i])
        {
            b[j] = pop();
            c[k] = 0;
            k++;
            if (b[j] < last_pop)
            {
                printf("NOT POSSIBLE\n");
                return;
            }
            else
            {
                last_pop = b[j];
            }
            j++;
            push(a[i]);
            c[k] = 1;
            k++;
            last_push = a[i];
            i++;
        }
        else
        {
            push(a[i]);
            i++;
        }
    }
    while (top != -1)
    {
        b[j] = pop();
        j++;
        c[k] = 0;
        k++;
    }
    for (int i = 0; i < 2 * m; i++)
    {
        if (c[i] == 0)
        {
            printf("POP ,");
        }
        else
        {
            printf("PUSH ,");
        }
    }
    printf("\n");
    printf("the sorted list is : ");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", b[i]);
    }
}

int main()
{
    int m;
    printf("enter no of values : ");
    scanf("%d", &m);
    int a[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, m);
    return 0;
}
