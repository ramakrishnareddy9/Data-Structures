#include <stdio.h>

#define MAX 8

void add(int A[MAX][MAX], int B[MAX][MAX], int res[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = A[i][j] + B[i][j];
}

void subtract(int A[MAX][MAX], int B[MAX][MAX], int res[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = A[i][j] - B[i][j];
}

void split(int parent[MAX][MAX], int child[MAX][MAX], int row, int col, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            child[i][j] = parent[i + row][j + col];
}

void join(int child[MAX][MAX], int parent[MAX][MAX], int row, int col, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            parent[i + row][j + col] = child[i][j];
}

void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
    int T1[MAX][MAX], T2[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];

    split(A, A11, 0, 0, newSize);
    split(A, A12, 0, newSize, newSize);
    split(A, A21, newSize, 0, newSize);
    split(A, A22, newSize, newSize, newSize);
    split(B, B11, 0, 0, newSize);
    split(B, B12, 0, newSize, newSize);
    split(B, B21, newSize, 0, newSize);
    split(B, B22, newSize, newSize, newSize);

    add(A11, A22, T1, newSize);
    add(B11, B22, T2, newSize);
    strassen(T1, T2, M1, newSize);

    add(A21, A22, T1, newSize);
    strassen(T1, B11, M2, newSize);

    subtract(B12, B22, T1, newSize);
    strassen(A11, T1, M3, newSize);

    subtract(B21, B11, T1, newSize);
    strassen(A22, T1, M4, newSize);

    add(A11, A12, T1, newSize);
    strassen(T1, B22, M5, newSize);

    subtract(A21, A11, T1, newSize);
    add(B11, B12, T2, newSize);
    strassen(T1, T2, M6, newSize);

    subtract(A12, A22, T1, newSize);
    add(B21, B22, T2, newSize);
    strassen(T1, T2, M7, newSize);

    add(M1, M4, T1, newSize);
    subtract(T1, M5, T2, newSize);
    add(T2, M7, C11, newSize);

    add(M3, M5, C12, newSize);
    add(M2, M4, C21, newSize);

    add(M1, M3, T1, newSize);
    subtract(T1, M2, T2, newSize);
    add(T2, M6, C22, newSize);

    join(C11, C, 0, 0, newSize);
    join(C12, C, 0, newSize, newSize);
    join(C21, C, newSize, 0, newSize);
    join(C22, C, newSize, newSize, newSize);
}

int main()
{
    int n, A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter size of the matrix (power of 2, max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, n);

    printf("Product of matrices A and B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
