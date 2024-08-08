/*
Declare a 2D array having order 4x4 and fill "1" in main diagonal positions and "0" in remaining positions 
*/


#include <stdio.h>
int main(){
	int arr[4][4];
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			if( i == j )
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
	
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			printf("%d\t" , arr[i][j]);
		}
		printf("\n");
	}
}

