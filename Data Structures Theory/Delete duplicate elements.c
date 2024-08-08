#include <stdio.h>
#include <stdlib.h>
void delete(int , int* , int);

int main(){
	int size;
	printf("Enter size of array");
	scanf("%d" , &size);
	
	//Creating array dynamically
	int *arr = (int *)malloc(size * sizeof(int));
	if(arr == NULL){
		printf("Memory Allocation Failed\n");
		return -1;
	}
	
	//Accepting user input in array and printing it
	for(int i = 0 ; i < size ; i++){
		printf("Enter element %d : " , i+1);
		scanf("%d" , &arr[i]);
	}
	printf("Array Created : \n");
	for(int i = 0 ; i < size ; i++){
		printf("%d\t" , arr[i]);
	}
	
	//Deletion of duplicate elements
	for(int i = 0 ; i < size ; i++){
		for(int j = i+1 ; j < size ; j++){
			if(arr[i] == arr[j]){
				delete( j , arr , size);
				size--;
				j--;
			}
		}
	}
	
	//Printing array after deletion
	printf("\nArray after deletion : \n");
	for(int i = 0 ; i < size ; i++){
		printf("%d\t" , arr[i]);
	}
	
	//Freeing memory
	free(arr);
	
	return 0;
}

void delete(int x, int * arr , int size){
	for(int i = x ; i < size - 1 ; i++){
		arr[i] = arr[i+1];
	}
}
