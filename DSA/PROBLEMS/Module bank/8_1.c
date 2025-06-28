#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

struct node
{
    char name[MAX_NAME_LENGTH];
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(char a[])
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->name, a);
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if (front != NULL)
    {
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}

void print_names_sorted_by_frequency()
{
    struct node *ptr = front;
    char names[MAX_STUDENTS][MAX_NAME_LENGTH];
    int counts[MAX_STUDENTS] = {0};
    int n = 0;

    while (ptr != NULL)
    {
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(names[i], ptr->name) == 0)
            {
                counts[i]++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            strcpy(names[n], ptr->name);
            counts[n] = 1;
            n++;
        }
        ptr = ptr->next;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (counts[i] < counts[j] || (counts[i] == counts[j] && strcmp(names[i], names[j]) > 0))
            {
                int temp_count = counts[i];
                counts[i] = counts[j];
                counts[j] = temp_count;

                char temp_name[MAX_NAME_LENGTH];
                strcpy(temp_name, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp_name);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s: %d\n", names[i], counts[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        char name[MAX_NAME_LENGTH];
        printf("Enter name %d: ", i + 1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        enqueue(name);
    }

    print_names_sorted_by_frequency();

    return 0;
}
