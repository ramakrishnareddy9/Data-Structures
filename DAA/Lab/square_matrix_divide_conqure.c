#include <stdio.h>

void divideAndConquer(int n, int A[n][n], int B[n][n], int C[n][n]);
void matrixMult(int n, int A[n][n], int B[n][n], int C[n][n]);

void matrixMult(int n, int A[n][n], int B[n][n], int C[n][n])
{
    divideAndConquer(n, A, B, C);
}

void divideAndConquer(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int mid = n / 2;

    int A11[mid][mid], A12[mid][mid], A21[mid][mid], A22[mid][mid];
    int B11[mid][mid], B12[mid][mid], B21[mid][mid], B22[mid][mid];
    int M1[mid][mid], M2[mid][mid], M3[mid][mid], M4[mid][mid], M5[mid][mid], M6[mid][mid], M7[mid][mid];
    int M8[mid][mid];

    // Divide the matrices into four sub-matrices
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

    // Recursively multiply the sub-matrices
    matrixMult(mid, A11, B11, M1);
    matrixMult(mid, A12, B21, M2);
    matrixMult(mid, A11, B12, M3);
    matrixMult(mid, A12, B22, M4);
    matrixMult(mid, A21, B11, M5);
    matrixMult(mid, A22, B21, M6);
    matrixMult(mid, A21, B12, M7);
    matrixMult(mid, A22, B22, M8);

    // Combine the results to form the final matrix
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            C[i][j] = M1[i][j] + M2[i][j];
            C[i][j + mid] = M3[i][j] + M4[i][j];
            C[i + mid][j] = M5[i][j] + M6[i][j];
            C[i + mid][j + mid] = M7[i][j] + M8[i][j];
        }
    }
}

int main()
{
    int n;

    printf("Enter the size of the matrices (n x n): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

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

    matrixMult(n, A, B, C);

    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
