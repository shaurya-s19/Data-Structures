// Accept integers in an array and find the largest and second largest without sorting

#include <stdio.h>
#define size 10
int main(){
	int largest = 0 , second_largest = 0 , temp = 0;
	int arr[size];
	
	printf("Enter %d elements in the array : " , size);
	for(int i = 0 ; i < size ; i++){
		scanf("%d" , &arr[i]);
	}
	
	largest = arr[0];
	second_largest = arr[1];
	if(largest < second_largest){
		temp = largest;
		largest = second_largest;
		second_largest = temp;
	}
	
	for(int i = 2 ; i < size ; i++){
		if(arr[i] > largest){
			second_largest = largest;
			largest = arr[i];
		}
		else if(arr[i] > second_largest && arr[i] != largest){
			second_largest = arr[i];
		}
	}
	
	printf("Largest : %d \nSecond Largest : %d" , largest , second_largest);
	return 0;
}
