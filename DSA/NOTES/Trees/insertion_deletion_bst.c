#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create(int x)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->left = new->right = NULL;
    return new;
}

struct node *insert(struct node *root, int x)
{
    if (root == NULL)
    {
        return create(x);
    }
    else if (x < root->data)
    {
        root->left = insert(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = insert(root->right, x);
    }
    return root;
}

void search(int x, int *count, struct node *root)
{
    if (root->data == x)
    {
        (*count)++;
        printf("\nElement fount at postion %d", *count);
    }
    else if (x < root->data && root->left != NULL)
    {
        (*count)++;
        search(x, count, root->left);
    }
    else if (x > root->data && root->right != NULL)
    {
        (*count)++;
        search(x, count, root->right);
    }
}

struct node *findMin(struct node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

struct node *delete(int x, struct node *root)
{
    if (root == NULL)
    {
        return root;
    }
    if (x < root->data)
    {
        root->left = delete (x, root->left);
    }
    else if (x > root->data)
    {
        root->right = delete (x, root->right);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete (temp->data, root->right);
    }
    return root;
}

void display(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        display(root->left);
        display(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 7);
    display(root);
    int count = 0;
    search(10, &count, root);
    printf("\nDeleting 10...\n");
    root = delete (10, root);
    printf("In-order traversal after deletion: ");
    display(root);
    return 0;
}