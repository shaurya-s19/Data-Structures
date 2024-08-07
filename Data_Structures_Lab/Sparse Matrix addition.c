#include <stdio.h>
void Sparse_Matrix_triplet(int row , int column , int a[row][column]);
void print(int row , int x[row][3]);

int main(){
	int a[4][4] , b[4][4];
	printf("Enter matrix 1\n");
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			printf("Element %d %d : " , i , j);
			scanf("%d" , &a[i][j]);
		}
	}
	
	Sparse_Matrix_triplet(4 , 4 , a);
	return 0;
}



void Sparse_Matrix_triplet(int row , int column , int a[row][column]){
	int n = row*column;
	int new_matrix[n+1][3];
	int x = 0;
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < column ; j++){
			if(a[i][j] != 0){
				x++;
				new_matrix[x][0] = i;
				new_matrix[x][1] = j;
				new_matrix[x][2] = a[i][j];
			}
		}
	}
	new_matrix[0][0] = row;
	new_matrix[0][1] = column;
	new_matrix[0][2] = x;
	
	print(x , new_matrix);
}

void print(int row , int x[row][3]){
	for(int i = 0 ; i <= row ; i++){
		for(int j = 0 ; j < 3 ; j++){
			printf("%d\t" , x[i][j]);
		}
		printf("\n");
	}
}
