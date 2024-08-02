// Reverse an array using pointers

#include <stdio.h>
#define size 5
void swap(int *a , int *b);

int main(){
	int arr[size];
	printf("Enter %d elements in the array - " , size);
	for(int i = 0 ; i < size ; i++){
		scanf("%d" , &arr[i]);
	}
	
	int *ptr = arr;
	int *ptr2 = arr + size - 1; //points to last index
	
	//Print Original Array
	printf("\nOriginal Array : ");
	for(int i = 0 ; i < size ; i++){
		printf("%d\t" , arr[i]);
	}
	
	//Reversing Array
	while(ptr<ptr2){
		swap(ptr , ptr2);
		ptr = ptr + 1;
		ptr2 = ptr2 - 1;
	}
	
	//Print Reversed Array
	printf("\nReversed Array : ");
	for(int i = 0 ; i < size ; i++){
		printf("%d\t" , arr[i]);
	}
}

void swap(int *a , int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
