#include <stdio.h>
#include <stdbool.h>

#define N 8

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Checks if placing a queen on board[row][col] is safe
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive utility function to solve N-Queens problem
bool solveNQueensUtil(int board[N][N], int col) {
    // If all queens are placed, print the solution
    if (col >= N) {
        printSolution(board);
        return true;
    }

    bool res = false; // Variable to store if any solution is found

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place queen at board[i][col]
            board[i][col] = 1;

            // Make result true if any placement is successful
            res = solveNQueensUtil(board, col + 1) || res;

            // Backtrack and remove queen from board[i][col]
            board[i][col] = 0;
        }
    }

    return res;
}

// Solves the N-Queens problem using solveNQueensUtil()
void solveNQueens() {
    int board[N][N] = {0}; // Initialize board with 0s

    if (!solveNQueensUtil(board, 0)) {
        printf("No solution exists");
        return;
    }
}

int main() {
    solveNQueens();
    return 0;
}
