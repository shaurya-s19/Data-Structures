#include <stdio.h>
#include <stdlib.h>

int main(){
	int row , column;
	int sum = 0;
	printf("Enter dimensions of matrix : ");
	scanf("%d %d" , &row , &column);
	
	//Creating Matrix Dynamically
	int **arr = (int **)malloc(row * sizeof(int *));
	for(int i = 0 ; i < row ; i++){
		arr[i] = (int *)malloc(column * sizeof(int));
	}
	
	if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    	}
	
	//Scanning Elements of Matrix and Finding Sum
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < column ; j++){
			printf("\nEnter Element %d %d : " , i , j);
			scanf("%d" , &arr[i][j] );
			sum += arr[i][j];
		}
	}
	
	//Printing the matrix and sum
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < column ; j++){
			printf("%d\t" , arr[i][j]);
		}
		printf("\n");
	}
	printf("The sum of elements of matrix is : %d\n" , sum);
	
	//Freeing Memory
	for(int i = 0 ; i < row ; i++){
		free(arr[i]);
	}
	free(arr);
	
	return 0;
}
