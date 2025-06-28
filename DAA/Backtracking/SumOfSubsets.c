#include <stdio.h>

void printSubset(int subset[], int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", subset[i]);
    }
    printf("]\n");
}

void findSubsets(int arr[], int n, int index, int subset[], int subsetSize, int currentSum, int target)
{
    if (currentSum == target)
    {
        printSubset(subset, subsetSize);
        return;
    }

    if (index == n || currentSum > target)
    {
        return;
    }

    subset[subsetSize] = arr[index];
    findSubsets(arr, n, index + 1, subset, subsetSize + 1, currentSum + arr[index], target);

    findSubsets(arr, n, index + 1, subset, subsetSize, currentSum, target);
}

int main()
{
    int arr[] = {10, 7, 5, 18, 12, 20, 15};
    int target = 35;
    int n = sizeof(arr) / sizeof(arr[0]);
    int subset[n];

    printf("Subsets with sum = %d:\n", target);
    findSubsets(arr, n, 0, subset, 0, 0, target);

    return 0;
}