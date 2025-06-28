#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int element;
    int index;
} Pair;

void merge(Pair *elements, int low, int mid, int high, int *counter)
{
    Pair *temp = (Pair *)malloc((high - low + 1) * sizeof(Pair));
    int left = low, right = mid + 1, k = 0;

    while (left <= mid && right <= high)
    {
        if (elements[left].element <= elements[right].element)
        {
            temp[k] = elements[right];
            right++;
        }
        else
        {
            counter[elements[left].index] += high - right + 1;
            temp[k] = elements[left];
            left++;
        }
        k++;
    }

    while (left <= mid)
    {
        temp[k] = elements[left];
        left++;
        k++;
    }

    while (right <= high)
    {
        temp[k] = elements[right];
        right++;
        k++;
    }

    for (int i = 0; i < high - low + 1; i++)
    {
        elements[low + i] = temp[i];
    }

    free(temp);
}

void mergeSort(Pair *elements, int low, int high, int *counter)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(elements, low, mid, counter);
        mergeSort(elements, mid + 1, high, counter);
        merge(elements, low, mid, high, counter);
    }
}

int *countSmaller(int *nums, int n, int *returnSize)
{
    Pair *elements = (Pair *)malloc(n * sizeof(Pair));
    int *counter = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        elements[i].element = nums[i];
        elements[i].index = i;
    }

    for (int i = 0; i < n; i++)
    {
        counter[i] = 0;
    }

    mergeSort(elements, 0, n - 1, counter);

    *returnSize = n;
    free(elements);
    return counter;
}

int main()
{
    int nums[] = {5, 2, 6, 1};
    int n = 4;
    int returnSize;
    int *result = countSmaller(nums, n, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
