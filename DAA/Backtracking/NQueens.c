#include <stdio.h>

int count = 0;

int canPlace(int board[][20], int n, int x, int y)
{
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
            return 0;
    }

    int i = x, j = y;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return 0;
        i--;
        j--;
    }

    i = x;
    j = y;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return 0;
        i--;
        j++;
    }

    return 1;
}

void printBoard(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solveNQueenAllPossibleWays(int n, int board[][20], int i)
{
    if (i == n)
    {
        count++;
        printf("Solution #%d:\n", count);
        printBoard(n, board);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            solveNQueenAllPossibleWays(n, board, i + 1);
            board[i][j] = 0;
        }
    }
}

int main()
{
    int n = 8;
    int board[20][20] = {0};

    solveNQueenAllPossibleWays(n, board, 0);
    printf("Total solutions: %d\n", count);

    return 0;
}
