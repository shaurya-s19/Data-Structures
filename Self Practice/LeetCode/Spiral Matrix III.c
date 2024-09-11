#include <stdio.h>
#include <stdlib.h>

int* spiralMatrixIII(int rows, int cols, int rStart, int cStart, int* returnSize) {
    int* res = (int*)malloc(rows * cols * 2 * sizeof(int));
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
    int d = 0, r = rStart, c = cStart, k = 0;
    *returnSize = rows * cols;

    for (int i = 0; i < rows * cols; i++) {
        res[k++] = r;
        res[k++] = c;
        int nr = r + dir[d][0], nc = c + dir[d][1];
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
            d = (d + 1) % 4;
            nr = r + dir[d][0];
            nc = c + dir[d][1];
        }
        r = nr;
        c = nc;
    }

    return res;
}

void printMatrix(int rows, int cols, int* res) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)calloc(cols, sizeof(int));
    }

    for (int i = 0; i < rows * cols; i += 2) {
        matrix[res[i]][res[i + 1]] = i / 2 + 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printSpiralOrder(int* res, int returnSize) {
    for (int i = 0; i < returnSize; i += 2) {
        printf("(%d, %d) ", res[i], res[i + 1]);
    }
    printf("\n");
}

int main() {
    int rows = 5, cols = 6, rStart = 1, cStart = 4;
    int returnSize;
    int* res = spiralMatrixIII(rows, cols, rStart, cStart, &returnSize);

    printf("Matrix in Spiral Order:\n");
    printMatrix(rows, cols, res);

    printf("Spiral Order Coordinates:\n");
    printSpiralOrder(res, returnSize);

    free(res);
    return 0;
}
