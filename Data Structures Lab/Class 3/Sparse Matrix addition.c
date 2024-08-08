#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int* Sparse_Matrix_triplet(int row, int column, int** a, int* size);
void print(int size, int x[][3]);
int* Sparse_Matrix_Sum(int* a, int* b, int sizeA, int sizeB, int* sizeSum);

int main() {
    int rows, columns;

    // Ask for matrix dimensions
    printf("Enter number of rows and columns for matrices:\n");
    scanf("%d %d", &rows, &columns);

    // Dynamically allocate matrices a and b
    int** a = (int**)malloc(rows * sizeof(int*));
    int** b = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        a[i] = (int*)malloc(columns * sizeof(int));
        b[i] = (int*)malloc(columns * sizeof(int));
    }

    // Input values for matrix a
    printf("Enter matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element %d %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Input values for matrix b
    printf("Enter matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element %d %d: ", i , j);
            scanf("%d", &b[i][j]);
        }
    }

    int sizeA, sizeB, sizeSum;
    int* matx_1 = Sparse_Matrix_triplet(rows, columns, a, &sizeA);
	printf("Sparse Matrix 1 :\n");
	print(sizeA , (int(*)[3])matx_1);

    int* matx_2 = Sparse_Matrix_triplet(rows, columns, b, &sizeB);
	printf("Sparse Matrix 2 :\n");
	print(sizeB , (int(*)[3])matx_2);

    int* result = Sparse_Matrix_Sum(matx_1, matx_2, sizeA, sizeB, &sizeSum);

    // Print the result
    printf("Sum of sparse matrices:\n");
    print(sizeSum, (int(*)[3])result);

    // Free dynamically allocated memory
    free(matx_1);
    free(matx_2);
    free(result);
    for (int i = 0; i < rows; i++) {
        free(a[i]);
        free(b[i]);
    }
    free(a);
    free(b);

    return 0;
}

int* Sparse_Matrix_triplet(int row, int column, int** a, int* size) {
    int n = row * column;
    int* new_matrix = (int*)malloc((n + 1) * 3 * sizeof(int));
    if (new_matrix == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int x = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (a[i][j] != 0) {
                new_matrix[++x * 3] = i;
                new_matrix[x * 3 + 1] = j;
                new_matrix[x * 3 + 2] = a[i][j];
            }
        }
    }
    new_matrix[0] = row;
    new_matrix[1] = column;
    new_matrix[2] = x;

    *size = x + 1;
    return new_matrix;
}

void print(int size, int x[][3]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", x[i][j]);
        }
        printf("\n");
    }
}

int* Sparse_Matrix_Sum(int* a, int* b, int sizeA, int sizeB, int* sizeSum) {
    int row = a[0], column = a[1];
    if (row != b[0] || column != b[1]) {
        printf("Matrix dimensions do not match for addition\n");
        exit(1);
    }

    int* new_matrix = (int*)malloc((sizeA + sizeB) * 3 * sizeof(int));
    if (new_matrix == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int index = 0, i = 1, j = 1;
    while (i <= sizeA && j <= sizeB) {
        if (a[i * 3] == b[j * 3]) {
            if (a[i * 3 + 1] == b[j * 3 + 1]) {
                new_matrix[index * 3] = a[i * 3];
                new_matrix[index * 3 + 1] = a[i * 3 + 1];
                new_matrix[index * 3 + 2] = a[i * 3 + 2] + b[j * 3 + 2];
                i++;
                j++;
            } else if (a[i * 3 + 1] < b[j * 3 + 1]) {
                new_matrix[index * 3] = a[i * 3];
                new_matrix[index * 3 + 1] = a[i * 3 + 1];
                new_matrix[index * 3 + 2] = a[i * 3 + 2];
                i++;
            } else {
                new_matrix[index * 3] = b[j * 3];
                new_matrix[index * 3 + 1] = b[j * 3 + 1];
                new_matrix[index * 3 + 2] = b[j * 3 + 2];
                j++;
            }
            index++;
        } else if (a[i * 3] < b[j * 3]) {
            new_matrix[index * 3] = a[i * 3];
            new_matrix[index * 3 + 1] = a[i * 3 + 1];
            new_matrix[index * 3 + 2] = a[i * 3 + 2];
            i++;
            index++;
        } else {
            new_matrix[index * 3] = b[j * 3];
            new_matrix[index * 3 + 1] = b[j * 3 + 1];
            new_matrix[index * 3 + 2] = b[j * 3 + 2];
            j++;
            index++;
        }
    }

    while (i <= sizeA) {
        new_matrix[index * 3] = a[i * 3];
        new_matrix[index * 3 + 1] = a[i * 3 + 1];
        new_matrix[index * 3 + 2] = a[i * 3 + 2];
        i++;
        index++;
    }

    while (j <= sizeB) {
        new_matrix[index * 3] = b[j * 3];
        new_matrix[index * 3 + 1] = b[j * 3 + 1];
        new_matrix[index * 3 + 2] = b[j * 3 + 2];
        j++;
        index++;
    }

    *sizeSum = index;
    return new_matrix;
}
