#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 20

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int frequency;
} Student;

typedef struct
{
    Student students[MAX_STUDENTS];
    int size;
} PriorityQueue;

void initPriorityQueue(PriorityQueue *pq)
{
    pq->size = 0;
}

void push(PriorityQueue *pq, Student student)
{
    pq->students[pq->size] = student;
    pq->size++;
    int i = pq->size - 1;
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (pq->students[parent].frequency < pq->students[i].frequency ||
            (pq->students[parent].frequency == pq->students[i].frequency &&
             strcmp(pq->students[parent].name, pq->students[i].name) > 0))
        {
            Student temp = pq->students[parent];
            pq->students[parent] = pq->students[i];
            pq->students[i] = temp;
            i = parent;
        }
        else
        {
            break;
        }
    }
}

Student pop(PriorityQueue *pq)
{
    Student student = pq->students[0];
    pq->students[0] = pq->students[pq->size - 1];
    pq->size--;
    int i = 0;
    while (2 * i + 1 < pq->size)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int max = i;
        if (pq->students[left].frequency > pq->students[max].frequency ||
            (pq->students[left].frequency == pq->students[max].frequency &&
             strcmp(pq->students[left].name, pq->students[max].name) < 0))
        {
            max = left;
        }
        if (right < pq->size && (pq->students[right].frequency > pq->students[max].frequency ||
                                 (pq->students[right].frequency == pq->students[max].frequency &&
                                  strcmp(pq->students[right].name, pq->students[max].name) < 0)))
        {
            max = right;
        }
        if (max != i)
        {
            Student temp = pq->students[max];
            pq->students[max] = pq->students[i];
            pq->students[i] = temp;
            i = max;
        }
        else
        {
            break;
        }
    }
    return student;
}

int main()
{
    char names[][MAX_NAME_LENGTH] = {"Rahul", "Anshul", "Rahul", "Ravi", "Rahul", "Vansh", "Neeraj", "Rahul", "Vansh", "Anshul"};
    int n = sizeof(names) / sizeof(names[0]);

    PriorityQueue pq;
    initPriorityQueue(&pq);

    Student frequencyMap[MAX_STUDENTS];
    int uniqueCount = 0;

    // Step 1: Count frequencies
    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++)
        {
            if (strcmp(frequencyMap[j].name, names[i]) == 0)
            {
                frequencyMap[j].frequency++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            strcpy(frequencyMap[uniqueCount].name, names[i]);
            frequencyMap[uniqueCount].frequency = 1;
            uniqueCount++;
        }
    }

    // Step 2: Push unique names with their frequencies to the priority queue
    for (int i = 0; i < uniqueCount; i++)
    {
        push(&pq, frequencyMap[i]);
    }

    // Step 3: Pop from the priority queue and print the names
    printf("Most frequent names: ");
    while (pq.size > 0)
    {
        Student student = pop(&pq);
        printf("%s (%d times) ", student.name, student.frequency);
    }
    printf("\n");

    return 0;
}