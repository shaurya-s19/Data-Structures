#include <stdio.h>
void quicksort(int [] , int , int);

int main(){
	int arr[] = {14 , 42 , 53, 25, 15 , 25 , 74 , 26, 47 , 63};
	int n = 10;
	quicksort(arr, 0 , n-1);
	for(int i = 0 ; i < n ; i++){
		printf("%d\t" , arr[i]);
	}
}
int partition(int arr[] , int low , int high){	
	int pivot = arr[low];
	int i = low + 1;
	int j = high;
	int temp;
	
	do{
		while(arr[i] <= pivot){
			i++;
		}
		while(arr[j] >pivot){
			j--;
		}
		
		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}while(i<j);
	
	temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	return j;
}


void quicksort(int arr[] , int low , int high){
	int partitionIndex; //index of pivot after partition
	
	if(low<high){
	partitionIndex = partition(arr , low , high);
	quicksort(arr , low , partitionIndex-1);  //sort left sub-array
	quicksort(arr , partitionIndex + 1 , high); //sort right sub-array
	}
}
