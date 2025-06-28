#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_float(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

int partition(float arr[], int low, int high, int profit[], int weight[])
{
    float pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(&profit[i], &profit[j]);
            swap(&weight[i], &weight[j]);
            swap_float(&arr[i], &arr[j]);
        }
    }
    swap(&profit[i + 1], &profit[high]);
    swap(&weight[i + 1], &weight[high]);
    swap_float(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(float arr[], int low, int high, int profit[], int weight[])
{
    if (low < high)
    {
        int pi = partition(arr, low, high, profit, weight);
        quick_sort(arr, low, pi - 1, profit, weight);
        quick_sort(arr, pi + 1, high, profit, weight);
    }
}

void sort(int profit[], int weight[], float x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        x[i] = (float)profit[i] / weight[i];
    }
    quick_sort(x, 0, n - 1, profit, weight);
}

void knapsack(int profit[], int weight[], float x[], int n, int maxweight)
{
    float PRofit = 0.0;
    int WEight = 0;
    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= maxweight - WEight)
        {
            WEight += weight[i];
            PRofit += profit[i];
        }
        else
        {
            PRofit += profit[i] * ((float)(maxweight - WEight) / weight[i]);
            continue;
        }
    }
    printf("profit = %f", PRofit);
}

int main()
{
    int n = 7, maxweight = 15;
    int profit[] = {10, 5, 15, 7, 6, 18, 3};
    int weight[] = {2, 3, 5, 7, 1, 4, 1};
    float x[n];
    sort(profit, weight, x, n);
    knapsack(profit, weight, x, n, maxweight);
    return 0;
}
