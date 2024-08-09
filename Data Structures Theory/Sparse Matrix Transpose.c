#include <stdio.h>
#include <stdlib.h>

// Function to transpose
void transpose(int val, int **sparse_matrix) {
    for (int i = 0; i < val; i++) {
        int temp = sparse_matrix[i][0];  // Swapping columns
        sparse_matrix[i][0] = sparse_matrix[i][1];
        sparse_matrix[i][1] = temp;
    }

    // Sort Rows based on the first column
    int temp[3];
    for (int i = 0; i < val - 1; i++) {
        for (int j = i + 1; j < val; j++) {
            if (sparse_matrix[i][0] > sparse_matrix[j][0]) {
                for (int k = 0; k < 3; k++) {
                    temp[k] = sparse_matrix[i][k];
                    sparse_matrix[i][k] = sparse_matrix[j][k];
                    sparse_matrix[j][k] = temp[k];
                }
            }
        }
    }
}

void print(int val , int **sparse_matrix){
    for (int i = 0; i < val; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", sparse_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int val;
    printf("Enter count of non-zero integers:\n");
    scanf("%d", &val);

    // Memory Allocation
    int **sparse_matrix = (int **)malloc(val * sizeof(int *));
    if (sparse_matrix == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < val; i++) {
        sparse_matrix[i] = (int *)malloc(3 * sizeof(int));
        if (sparse_matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }

    // Accepting Values
    for (int i = 0; i < val; i++) {
        for (int j = 0; j < 3; j++) {
            printf("\nEnter value for index %d %d: ", i, j);
            scanf("%d", &sparse_matrix[i][j]);
        }
    }

    // Print Original Matrix
    printf("---------------Sparse Matrix---------------\n");
    print(val ,   sparse_matrix);

    // Call transpose function
    transpose(val, sparse_matrix);

    // Print Sorted Matrix
    printf("---------------Transpose Matrix---------------\n");
    print(val , sparse_matrix);

    // Free Memory
    for (int i = 0; i < val; i++) {
        free(sparse_matrix[i]);
    }
    free(sparse_matrix);

    return 0;
}

