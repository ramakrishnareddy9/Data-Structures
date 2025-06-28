#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a stack structure
typedef struct
{
    int *data;
    int top;
    int capacity;
} Stack;

// Function to create a stack with a given capacity
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an element onto the stack
void push(Stack *stack, int item)
{
    if (stack->top < stack->capacity - 1)
    {
        stack->data[++stack->top] = item;
    }
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->data[stack->top--];
    }
    return -1; // Indicate an error or empty stack
}

// Function to get the top element of the stack
int peek(Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->data[stack->top];
    }
    return -1; // Indicate an error or empty stack
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to compare two integers (for qsort)
int compareIntegers(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Function to sort using a single stack
void sortWithStack(int *inputArray, int length)
{
    // Create a stack with the same capacity as the input array
    Stack *stack = createStack(length);
    int *sortedArray = (int *)malloc(length * sizeof(int));
    int operationsCount = 0;

    // Create a sorted array
    for (int i = 0; i < length; i++)
    {
        sortedArray[i] = inputArray[i];
    }
    // Sort the sortedArray
    qsort(sortedArray, length, sizeof(int), compareIntegers);

    // Initialize the index for the sorted array
    int index = 0;

    // Process each element in the input array
    for (int i = 0; i < length; i++)
    {
        // Push the current element onto the stack
        push(stack, inputArray[i]);
        printf("PUSH\n");
        operationsCount++;

        // Pop elements from the stack to match the sortedArray
        while (!isEmpty(stack) && peek(stack) == sortedArray[index])
        {
            pop(stack);
            printf("POP\n");
            operationsCount++;
            index++;
        }
    }

    // Check if sorting was successful
    if (index == length)
    {
        // Successfully sorted, print the operations
        printf("Operations count: %d\n", operationsCount);
    }
    else
    {
        // Not possible to sort
        printf("NOT POSSIBLE\n");
    }

    // Free allocated memory
    free(stack->data);
    free(stack);
    free(sortedArray);
}

int main()
{
    int inputArray1[] = {10, 702, 36, 125, 82};
    int length1 = sizeof(inputArray1) / sizeof(inputArray1[0]);
    printf("Sorting first array:\n");
    sortWithStack(inputArray1, length1);

    int inputArray2[] = {1023, 5029, 158};
    int length2 = sizeof(inputArray2) / sizeof(inputArray2[0]);
    printf("Sorting second array:\n");
    sortWithStack(inputArray2, length2);

    return 0;
}
