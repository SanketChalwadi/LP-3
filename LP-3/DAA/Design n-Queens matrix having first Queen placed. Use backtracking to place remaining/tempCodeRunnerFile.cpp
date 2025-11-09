#include <stdio.h>
#include <string.h>

#define N 8  // Change this value for different board sizes

// Function to check if placing a queen is safe
int isSafe(char mat[][N], int r, int c) {
    for (int i = 0; i < r; i++)
        if (mat[i][c] == 'Q') return 0;

    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j] == 'Q') return 0;

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
        return 1; // Return after first valid solution
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(mat, r, i)) {
            mat[r][i] = 'Q';
            if (nQueen(mat, r + 1))
                return 1; // Found solution
            mat[r][i] = '-'; // backtrack
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
    
    // Start backtracking from the next row
    if (!nQueen(mat, 0)) {
        printf("\nNo solution found!\n");
    }

    return 0;
}
