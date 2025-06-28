#include <stdio.h>
#include <stdlib.h>

#define N 8

// Function to add two matrices
void add(int A[N][N], int B[N][N], int C[N][N], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subtract(int A[N][N], int B[N][N], int C[N][N], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen's algorithm for matrix multiplication
void strassen(int A[N][N], int B[N][N], int C[N][N], int size)
{
    if (size == 2)
    {
        // Base case: Multiply 2x2 matrices directly
        int P1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
        int P2 = (A[1][0] + A[1][1]) * B[0][0];
        int P3 = A[0][0] * (B[0][1] - B[1][1]);
        int P4 = A[1][1] * (B[1][0] - B[0][0]);
        int P5 = (A[0][0] + A[0][1]) * B[1][1];
        int P6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
        int P7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

        C[0][0] = P1 + P4 - P5 + P7;
        C[0][1] = P3 + P5;
        C[1][0] = P2 + P4;
        C[1][1] = P1 - P2 + P3 + P6;
        return;
    }

    int newSize = size / 2;
    int A11[N][N], A12[N][N], A21[N][N], A22[N][N];
    int B11[N][N], B12[N][N], B21[N][N], B22[N][N];
    int C11[N][N], C12[N][N], C21[N][N], C22[N][N];
    int M1[N][N], M2[N][N], M3[N][N], M4[N][N], M5[N][N], M6[N][N], M7[N][N];
    int temp1[N][N], temp2[N][N];

    // Divide A and B into sub-matrices
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate the 7 Strassen multiplications
    add(A11, A22, temp1, newSize);
    add(B11, B22, temp2, newSize);
    strassen(temp1, temp2, M1, newSize);

    add(A21, A22, temp1, newSize);
    strassen(temp1, B11, M2, newSize);

    subtract(B12, B22, temp2, newSize);
    strassen(A11, temp2, M3, newSize);

    subtract(B21, B11, temp2, newSize);
    strassen(A22, temp2, M4, newSize);

    add(A11, A12, temp1, newSize);
    strassen(temp1, B22, M5, newSize);

    subtract(A21, A11, temp1, newSize);
    add(B11, B12, temp2, newSize);
    strassen(temp1, temp2, M6, newSize);

    subtract(A12, A22, temp1, newSize);
    add(B21, B22, temp2, newSize);
    strassen(temp1, temp2, M7, newSize);

    // Calculate final sub-matrices of C
    add(M1, M4, temp1, newSize);
    subtract(temp1, M5, temp2, newSize);
    add(temp2, M7, C11, newSize);

    add(M3, M5, C12, newSize);
    add(M2, M4, C21, newSize);

    add(M1, M3, temp1, newSize);
    subtract(temp1, M2, temp2, newSize);
    add(temp2, M6, C22, newSize);

    // Combine sub-matrices into C
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int M[N][N], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d  ", M[i][j]);
        printf("\n");
    }
}

int main()
{
    int A[N][N] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {9, 10, 11, 12, 13, 14, 15, 16},
        {1, 18, 19, 20, 2, 2, 2, 2},
        {8, 9, 4, 2, 2, 3, 3, 3},
        {3, 3, 3, 3, 3, 3, 3, 4},
        {4, 4, 4, 4, 4, 4, 4, 4},
        {4, 5, 5, 5, 5, 5, 5, 5},
        {5, 5, 5, 6, 6, 6, 6, 6}};

    int B[N][N] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4, 4, 4, 4},
        {5, 5, 5, 5, 5, 5, 5, 5},
        {6, 6, 6, 6, 6, 6, 6, 6},
        {7, 7, 7, 7, 7, 7, 7, 7},
        {8, 8, 8, 8, 8, 8, 8, 8}};

    int C[N][N] = {0};

    strassen(A, B, C, N);

    printf("Resultant Matrix:\n");
    printMatrix(C, N);

    return 0;
}