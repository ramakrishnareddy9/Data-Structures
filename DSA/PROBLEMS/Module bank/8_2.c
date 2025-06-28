#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a structure to represent the heap nodes
typedef struct
{
    int value;
    int list_index;
    int element_index;
} HeapNode;

// Function prototypes
void minHeapify(HeapNode heap[], int size, int root);
void buildMinHeap(HeapNode heap[], int size);
HeapNode extractMin(HeapNode heap[], int *size);
void insertHeap(HeapNode heap[], int *size, HeapNode node);
void sort(int a[][4], int m, int n);

int main()
{
    int m, n;
    printf("Enter the number of lists (m) and number of elements per list (n): ");
    scanf("%d %d", &m, &n);

    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        printf("Enter elements of list %d: \n", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    sort(a, m, n);
    return 0;
}

// Function to perform heapify operation
void minHeapify(HeapNode heap[], int size, int root)
{
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && heap[left].value < heap[smallest].value)
    {
        smallest = left;
    }
    if (right < size && heap[right].value < heap[smallest].value)
    {
        smallest = right;
    }
    if (smallest != root)
    {
        HeapNode temp = heap[root];
        heap[root] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, size, smallest);
    }
}

// Function to build the min-heap
void buildMinHeap(HeapNode heap[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        minHeapify(heap, size, i);
    }
}

// Function to extract the minimum element from the heap
HeapNode extractMin(HeapNode heap[], int *size)
{
    if (*size <= 0)
    {
        HeapNode empty = {INT_MAX, -1, -1};
        return empty;
    }
    HeapNode root = heap[0];
    if (*size > 1)
    {
        heap[0] = heap[*size - 1];
        minHeapify(heap, *size, 0);
    }
    (*size)--;
    return root;
}

// Function to insert a new element into the heap
void insertHeap(HeapNode heap[], int *size, HeapNode node)
{
    (*size)++;
    int i = *size - 1;
    heap[i] = node;

    while (i != 0 && heap[(i - 1) / 2].value > heap[i].value)
    {
        HeapNode temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Function to merge the sorted lists and print the sorted output
void sort(int a[][4], int m, int n)
{
    HeapNode heap[m];
    int heap_size = 0;

    // Initialize the heap with the first element of each list
    for (int i = 0; i < m; i++)
    {
        HeapNode node = {a[i][0], i, 0};
        insertHeap(heap, &heap_size, node);
    }

    int result[m * n];
    int result_size = 0;

    // Process the heap and extract the minimum element
    while (heap_size > 0)
    {
        HeapNode min_node = extractMin(heap, &heap_size);
        result[result_size++] = min_node.value;

        // Insert the next element from the same list into the heap
        if (min_node.element_index + 1 < n)
        {
            HeapNode new_node = {a[min_node.list_index][min_node.element_index + 1], min_node.list_index, min_node.element_index + 1};
            insertHeap(heap, &heap_size, new_node);
        }
    }

    // Print the sorted result
    printf("Sorted output: ");
    for (int i = 0; i < result_size; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
}
