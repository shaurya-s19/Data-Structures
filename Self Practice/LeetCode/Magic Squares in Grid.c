#include <stdio.h>

#define MAX_SIZE 10
#define MAGIC_SUM 15


int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    // Iterate over all possible 3x3 subgrids
    for (int r = 0; r <= row - 3; r++) {
        for (int c = 0; c <= col - 3; c++) {
            // Check if the current 3x3 subgrid is a magic square
            int sum_row1 = grid[r][c] + grid[r][c+1] + grid[r][c+2];
            int sum_row2 = grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2];
            int sum_row3 = grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2];
            int sum_col1 = grid[r][c] + grid[r+1][c] + grid[r+2][c];
            int sum_col2 = grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1];
            int sum_col3 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2];
            int sum_dia1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
            int sum_dia2 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];

            // Check if all sums are equal to MAGIC_SUM
            if (sum_row1 == MAGIC_SUM && sum_row2 == MAGIC_SUM && sum_row3 == MAGIC_SUM &&
                sum_col1 == MAGIC_SUM && sum_col2 == MAGIC_SUM && sum_col3 == MAGIC_SUM &&
                sum_dia1 == MAGIC_SUM && sum_dia2 == MAGIC_SUM) {
                count++;
            }
        }
    }
}

int main() {
    int grid[MAX_SIZE][MAX_SIZE];
    int row, col;
    int count = 0;

    // Input grid dimensions
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);

    // Input grid values
    printf("Enter the grid values:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
	
    // Print the count of magic squares found
    printf("Number of 3x3 magic squares: %d\n", count);

    return 0;
}

