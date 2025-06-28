#include <stdio.h>

void add(int n, int A[n][n], int B[n][n], int result[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int n, int A[n][n], int B[n][n], int result[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int n, int A[n][n], int B[n][n], int result[n][n])
{
    if (n == 1)
    {
        result[0][0] = A[0][0] * B[0][0];
        return;
    }

    int mid = n / 2;
    int A11[mid][mid], A12[mid][mid], A21[mid][mid], A22[mid][mid];
    int B11[mid][mid], B12[mid][mid], B21[mid][mid], B22[mid][mid];
    int M1[mid][mid], M2[mid][mid], M3[mid][mid], M4[mid][mid], M5[mid][mid], M6[mid][mid], M7[mid][mid];
    int temp1[mid][mid], temp2[mid][mid];

    // Divide matrices into 4 submatrices
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Calculate M1 to M7
    add(mid, A11, A22, temp1);
    add(mid, B11, B22, temp2);
    strassen(mid, temp1, temp2, M1);

    add(mid, A21, A22, temp1);
    strassen(mid, temp1, B11, M2);

    subtract(mid, B12, B22, temp1);
    strassen(mid, A11, temp1, M3);

    subtract(mid, B21, B11, temp1);
    strassen(mid, A22, temp1, M4);

    add(mid, A11, A12, temp1);
    strassen(mid, temp1, B22, M5);

    subtract(mid, A21, A11, temp1);
    add(mid, B11, B12, temp2);
    strassen(mid, temp1, temp2, M6);

    subtract(mid, A12, A22, temp1);
    add(mid, B21, B22, temp2);
    strassen(mid, temp1, temp2, M7);

    // Combine results into the final matrix
    add(mid, M1, M4, temp1);
    subtract(mid, temp1, M5, temp2);
    add(mid, temp2, M7, result); // top-left block

    add(mid, M3, M5, temp1);
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            result[i][j + mid] = temp1[i][j]; // top-right block
        }
    }

    add(mid, M2, M4, temp1);
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            result[i + mid][j] = temp1[i][j]; // bottom-left block
        }
    }

    add(mid, M1, M3, temp1);
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            result[i + mid][j + mid] = temp1[i][j]; // bottom-right block
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int A[n][n], B[n][n], result[n][n];

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(n, A, B, result);

    printf("Resulting matrix after Strassen's multiplication:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
