#include <stdio.h>

#define MAX 20

int board[MAX], n;

int isSafe(int row, int col)
{
    int i;

    for(i = 0; i < row; i++)
    {

        if(board[i] == col ||
           board[i] - i == col - row ||
           board[i] + i == col + row)
        {
            return 0;
        }
    }

    return 1;
}

void printSolution()
{
    int i, j;

    printf("\nSolution:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

void solveNQueens(int row)
{
    int col;

    if(row == n)
    {
        printSolution();
        return;
    }

    for(col = 0; col < n; col++)
    {
        if(isSafe(row, col))
        {
            board[row] = col;

            solveNQueens(row + 1);
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);

    solveNQueens(0);

    return 0;
}
