#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *new_head = NULL;
    struct ListNode *tail = NULL;

    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            if (new_head == NULL)
            {
                new_head = list1;
                tail = new_head;
            }
            else
            {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        }
        else
        {
            if (new_head == NULL)
            {
                new_head = list2;
                tail = new_head;
            }
            else
            {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }

    if (list1 != NULL)
    {
        tail->next = list1;
    }
    if (list2 != NULL)
    {
        tail->next = list2;
    }

    return new_head;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (listsSize <= 0)
    {
        return NULL;
    }
    struct ListNode *head = lists[0];

    for (int i = 1; i < listsSize; i++)
    {
        head = mergeTwoLists(head, lists[i]);
    }
    return head;
}

struct ListNode *createList(int arr[], int size)
{
    struct ListNode *head = NULL;
    struct ListNode *temp = NULL;

    for (int i = 0; i < size; i++)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return head;
}

void printList(struct ListNode *head)
{
    struct ListNode *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        int a[m];
    }
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};

    struct ListNode *list1 = createList(arr1, 3);
    struct ListNode *list2 = createList(arr2, 3);
    struct ListNode *list3 = createList(arr3, 2);

    struct ListNode *lists[] = {list1, list2, list3};

    struct ListNode *mergedList = mergeKLists(lists, 3);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
