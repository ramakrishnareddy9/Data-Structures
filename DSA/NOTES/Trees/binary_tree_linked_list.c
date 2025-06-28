#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int x;
    printf("enter the data :");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->left = new->right = NULL;
    printf("enter left value of %d\n", x);
    new->left = create();
    printf("enter right value of %d\n", x);
    new->right = create();
}

void print(struct node *a)
{
    if (a != NULL)
    {
        printf("%d ", a->data);
        print(a->left);
        print(a->right);
    }
}

int main()
{
    struct node *root;
    root = create();
    print(root);
}