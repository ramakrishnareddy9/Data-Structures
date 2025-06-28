#include <stdio.h>
struct check
{
    char name[100];
    int count;
} A[100];
int c = 0;

void sort(char a[][100], int n);
int strcmp_(char a[], char b[]);
void strcpy_(char a[], char b[]);
void no_same_name(char a[][100], int n);
void display();

int main()
{
    int n;
    printf("enter number of names: ");
    scanf("%d", &n);
    char a[n][100];
    printf("enter the names:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }
    sort(a, n);
    no_same_name(a, n);
    display();
    return 0;
}

void no_same_name(char a[][100], int n)
{
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 1;
        if (i > 0 && strcmp_(a[i], a[i - 1]) == 0)
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp_(a[i], a[j]) == 0)
            {
                count++;
            }
        }
        strcpy_(A[c].name, a[i]);
        A[c].count = count;
        c++;
    }
}

void sort(char a[][100], int n)
{
    char temp[100];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp_(a[i], a[j]) > 0)
            {
                strcpy_(temp, a[i]);
                strcpy_(a[i], a[j]);
                strcpy_(a[j], temp);
            }
        }
    }
}

int strcmp_(char a[], char b[])
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] < b[i])
        {
            return -1;
        }
        else if (a[i] > b[i])
        {
            return 1;
        }
        i++;
    }
    if (a[i] == '\0' && b[i] != '\0')
    {
        return -1;
    }
    if (a[i] != '\0' && b[i] == '\0')
    {
        return 1;
    }
    return 0;
    return 0;
}

void strcpy_(char a[], char b[])
{
    int i = 0;
    while (b[i] != '\0')
    {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';
}

void display()
{
    for (int i = 0; i < c; i++)
    {
        printf("%s - %d\n", A[i].name, A[i].count);
    }
}