#include <stdio.h>

#define MAX 100

struct Job
{
    int id;
    int profit;
    int deadline;
};

void sort_by_profit(struct Job jobs[], int n)
{
    int i, j;
    struct Job temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int find_max_deadline(struct Job jobs[], int n)
{
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++)
    {
        if (jobs[i].deadline > max)
        {
            max = jobs[i].deadline;
        }
    }
    return max;
}

void job_sequencing(struct Job jobs[], int n)
{
    int i, j;
    int max_deadline = find_max_deadline(jobs, n);
    int slot[MAX];
    for (i = 0; i <= max_deadline; i++)
    {
        slot[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = jobs[i].deadline; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = jobs[i].id;
                break;
            }
        }
    }

    printf("Job sequence: ");
    for (i = 1; i <= max_deadline; i++)
    {
        if (slot[i] != -1)
        {
            printf("J%d ", slot[i]);
        }
    }
    printf("\n");
}

int main()
{
    int n, i;
    struct Job jobs[MAX];

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter job details (id profit deadline):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &jobs[i].id, &jobs[i].profit, &jobs[i].deadline);
    }

    sort_by_profit(jobs, n);
    job_sequencing(jobs, n);

    return 0;
}
// Enter number of jobs : 6
// Enter job details(id profit deadline) : 1 75 3
// 2 60 1
// 3 80 2
// 4 30 2
// 5 90 1
// 6 40 3