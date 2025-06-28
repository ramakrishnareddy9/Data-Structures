#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

float count_quick = 0, count_selection = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    count_quick++;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[smallest] > a[j])
            {
                smallest = j;
            }
        }
        if (smallest != i)
        {
            swap(&a[smallest], &a[i]);
            count_selection++;
        }
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void values()
{
    FILE *data_file = fopen("points_data.txt", "w");
    if (data_file == NULL)
    {
        fprintf(stderr, "Error opening data file\n");
        exit(1);
    }
    fprintf(data_file, "%lf %lf\n", count_selection, count_selection);
    fprintf(data_file, "%lf %lf\n", count_quick, count_quick);
    fclose(data_file);
}

void graph()
{
    FILE *gnuplot_script = fopen("plot_script.gp", "w");
    if (gnuplot_script == NULL)
    {
        fprintf(stderr, "Error creating gnuplot script\n");
        return;
    }
    fprintf(gnuplot_script, "set title 'Graph for Two Points'\n");
    fprintf(gnuplot_script, "set xlabel 'x'\n");
    fprintf(gnuplot_script, "set ylabel 'y'\n");
    fprintf(gnuplot_script, "set xrange [0:30]\n");
    fprintf(gnuplot_script, "set yrange [0:30]\n");
    fprintf(gnuplot_script, "plot 'points_data.txt' with linespoints lw 2 lc 'blue' title 'Line between points'\n");
    fclose(gnuplot_script);
    system("gnuplot -p plot_script.gp");
    remove("points_data.txt");
    remove("plot_script.gp");
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements in array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    clock_t start, end;
    double comp_time;
    int a_copy[n];
    memcpy(a_copy, a, sizeof(a));
    start = clock();
    quick_sort(a, 0, n - 1);
    end = clock();
    comp_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array using Quick Sort:\n");
    print_array(a, n);
    printf("Time taken by Quick Sort: %f seconds\n", comp_time);
    start = clock();
    selection_sort(a_copy, n);
    end = clock();
    comp_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array using Selection Sort:\n");
    print_array(a_copy, n);
    printf("Time taken by Selection Sort: %f seconds\n", comp_time);
    printf("%f %f", count_quick, count_selection);
    values();
    graph();
    return 0;
}
