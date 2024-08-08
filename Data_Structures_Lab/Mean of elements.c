// Accept any 10 integers in an array and find their mean

#include <stdio.h>
#define size 10
int main(){
	int sum = 0;
	float mean;
	int arr[size];
	
	printf("Enter elements of array : ");
	for(int i = 0 ; i < size ; i++){
		scanf("%d" , &arr[i]);
		sum += arr[i];
	}
	
	mean = sum / 10.0;
	printf("Sum is : %d \nMean is : %f", sum , mean);
	return 0;
}
