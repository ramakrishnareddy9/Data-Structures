#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *sortList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *currentNode = head->next;
    struct ListNode *pivotNode = head;
    struct ListNode *leftSublist = head;
    struct ListNode *rightSublist = head;

    int isSorted = 1;

    while (currentNode != NULL)
    {
        if (currentNode->val < pivotNode->val)
        {
            struct ListNode *tempNode = currentNode->next;
            currentNode->next = leftSublist;
            if (currentNode->val > leftSublist->val)
            {
                isSorted = 0;
            }
            leftSublist = currentNode;
            currentNode = tempNode;
        }
        else
        {
            rightSublist->next = currentNode;
            if (rightSublist->val > currentNode->val)
            {
                isSorted = 0;
            }
            rightSublist = currentNode;
            currentNode = currentNode->next;
        }
    }
    rightSublist->next = NULL;

    if (isSorted)
    {
        return leftSublist;
    }

    rightSublist = sortList(pivotNode->next);
    pivotNode->next = NULL;
    leftSublist = sortList(leftSublist);

    pivotNode->next = rightSublist;

    return leftSublist;
}

struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode *head)
{
    struct ListNode *currentNode = head;
    while (currentNode != NULL)
    {
        printf("%d -> ", currentNode->val);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

int main()
{
    struct ListNode *head = createNode(4);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);

    printf("Original list: ");
    printList(head);

    head = sortList(head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}
