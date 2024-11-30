#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isSafe(int **a, int row, int col, int N) {
    int i, j;

    for (j = 0; j < col; j++) {
        if (a[row][j]) {
            return false;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (a[i][j]) {
            return false;
        }
    }

    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (a[i][j]) {
            return false;
        }
    }
    return true;
}

void display(int **a, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", a[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool solveQueensUtil(int **a, int col, int N, int *count) {
    if (col >= N) {
        (*count)++;
        display(a, N);
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(a, i, col, N)) {
            a[i][col] = 1;
            res = solveQueensUtil(a, col + 1, N, count) || res;
            a[i][col] = 0;  // Backtrack
        }
    }
    return res;
}

void solveQueens(int N, int *count) {
    int **a = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        a[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            a[i][j] = 0;
        }
    }

    solveQueensUtil(a, 0, N, count);

    for (int i = 0; i < N; i++) {
        free(a[i]);
    }
    free(a);
}

int main() {
    int N, count = 0;
    printf("Input size of board: ");
    scanf("%d", &N);
    solveQueens(N, &count);
    printf("Total number of solutions: %d\n", count);
    return 0;
}
