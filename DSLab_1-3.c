// Even and Odd numbers

#include <stdio.h>
#define size 10
int main(){
	int arr[size];
	printf("Enter %d elements in the array : " , size);
	for(int i = 0 ; i < size ; i++){
		scanf("%d" , &arr[i]);
	}
	
	printf("Even Numbers : ");
	for(int i = 0 ; i < size ; i++){
		if(arr[i] % 2 == 0){
			printf("%d\t" , arr[i]);
		}
	}
	
	printf("Odd Numbers : ");
	for(int i = 0 ; i < size ; i++){
		if(arr[i] % 2 != 0){
			printf("%d\t" , arr[i]);
		}
	}
	return 0;
}
