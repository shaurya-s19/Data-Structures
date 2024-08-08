#include <stdio.h>
#include <stdlib.h>

int binarySearch(int * , int , int , int);
int sort(int * , int);

int main(){
	int Size;
	printf("Enter size of your array : ");
	scanf("%d" , &Size);
	
	//Dynamically Allocation Array
	int *arr = (int *)malloc(Size * sizeof(int));
	if(arr == NULL){
		printf("Dynamic memory allocation failed \n");
		return -1;
	}
	
	//Accepting array from user
	printf("Enter elements of array : \n");
	for(int i = 0 ; i < Size ; i++){
		printf("Enter element %d : ", i+1);
		scanf("%d" , &arr[i]);
	}
	
	//Sorting the array
	sort(arr , Size);
	
	//User input for element to search
	int Search;
	printf("Enter element to search in this array : ");
	scanf("%d" , &Search);
	
	//Result
	int index = binarySearch(arr , Search , 0 , Size - 1);
	if(index == -1)
		printf("Element %d is not in array\n" , Search);
	else
		printf("Element %d found in array at index %d\n" , Search , index);
	
	//Freeing memory
	free(arr);
	
	return 0;
}

int sort(int * arr , int Size){
	for(int i = 1 ; i <= Size ; i++){
		for(int j = 0 ; j < Size - i ; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int binarySearch(int* arr , int Search , int low , int high){
	if(low > high)
		return -1;
		
	int mid = (low + high ) / 2;
	if(arr[mid] == Search)
		return mid;
	else if (arr[mid] < Search)
		binarySearch(arr , Search , mid + 1 , high);
	else
		binarySearch(arr , Search , low , mid - 1);
}
