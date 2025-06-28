#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *create(int n)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->value = n;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct Node *insert(struct Node *node, int n)
{
    if (node == NULL)
    {
        return create(n);
    }
    else if (n < node->value)
    {
        node->left = insert(node->left, n);
    }
    else if (n > node->value)
    {
        node->right = insert(node->right, n);
    }
    return node;
}

void print(struct Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->value);
        print(node->left);
        print(node->right);
    }
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 25);
    print(root);
    return 0;
}
