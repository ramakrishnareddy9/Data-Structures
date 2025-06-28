#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *array_to_bst(int arr[], int idx1, int idx2)
{
    if (idx1 > idx2)
    {
        return NULL;
    }
    int mid = (idx1 + idx2) / 2;
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = arr[mid];
    root->left = array_to_bst(arr, idx1, mid - 1);
    root->right = array_to_bst(arr, mid + 1, idx2);
    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    struct node *root = array_to_bst(arr, 0, n - 1);
    inorder(root);
    return 0;
}
