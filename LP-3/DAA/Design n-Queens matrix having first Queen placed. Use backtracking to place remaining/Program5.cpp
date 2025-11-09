#include <stdio.h>
#include <string.h>

#define N 8  // You can change this for different board sizes

// Function to check if placing a queen is safe
int isSafe(char mat[][N], int r, int c) {
    // Check column
    for (int i = 0; i < r; i++)
        if (mat[i][c] == 'Q') return 0;

    // Check upper-left diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j] == 'Q') return 0;

    // Check upper-right diagonal
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
        if (mat[i][j] == 'Q') return 0;

    return 1;
}

// Function to print board
void printSolution(char mat[][N]) {
    printf("\nFinal N-Queens Matrix:\n\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", mat[i][j]);
        printf("\n");
    }
}

// Recursive function to solve N-Queens
int nQueen(char mat[][N], int r) {
    if (r == N) {
        printSolution(mat);
        return 1; // Found a valid solution
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(mat, r, i)) {
            mat[r][i] = 'Q';
            if (nQueen(mat, r + 1))
                return 1; // Stop after first valid solution
            mat[r][i] = '-'; // Backtrack
        }
    }
    return 0;
}

int main() {
    char mat[N][N];
    memset(mat, '-', sizeof(mat));

    int row, col;
    printf("Enter initial position of first Queen (row and column 0-%d): ", N - 1);
    scanf("%d %d", &row, &col);

    // Place the first queen manually
    mat[row][col] = 'Q';

    printf("\nInitial matrix with first queen placed:\n\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", mat[i][j]);
        printf("\n");
    }

    printf("\nSolving...\n");

    // ✅ FIXED: Start solving from the next row after the manually placed queen
    if (!nQueen(mat, row + 1)) {
        printf("\nNo solution found!\n");
    }

    return 0;
}
