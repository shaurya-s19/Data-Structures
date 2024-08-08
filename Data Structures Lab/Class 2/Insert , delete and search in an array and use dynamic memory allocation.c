
 /*
1) define an array having 10 integers , delete an element in a particular position and display the objected array

2) declare an array and input 5 integers to this array using pointer ,  using dynamic memory allocation.


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int insert(int *arr , int num , int pos , int length);
int delete(int *arr , int num , int length);
int search(int *arr , int num , int length;);

int main(){
	int n;   
	printf("Enter size of array : ");
	scanf("%d" , &n);
	
	int *arr = (int *)malloc(n * sizeof(int));
	
	printf("Insert elements in array : ");
	for(int i = 0; i < n ; i++){
		scanf("%d" , arr+i);
	}
	
	int num , pos;
	int choice;	
		
	printf("Current Array : \n");
	for(int i = 0 ; i < n ; i++){
		printf("%d\t" , arr[i]);
	}
	
	printf("\n1: INSERT\n2: DELETE\n3: SEARCH\nEnter task to be performed : ");
	scanf("%d" , &choice);

	switch(choice){
		case 1:
			printf("\nEnter element to be inserted : ");
			scanf("%d" , &num); 
			
			printf("\nEnter position to insert : ");
			scanf("%d" , &pos);
			
			insert(arr , num , pos , n);
			break;
	
		case 2:
			printf("\nEnter number of elements to be deleted : ");
			scanf("%d" , &num);
			
			delete(arr , num ,n);
			break;
		case 3:
			printf("\nEnter element to search : ");
			scanf("%d" , &num);
			
			search(arr , num , n);
			break;
	}
	
	return 0;
}

int insert(int *arr , int num , int pos , int length){

	printf("\nAfter Insertion : \n");
	
	for(int i = length - 1 ; i >= pos ; i--){
		arr[i] = arr[i-1];
	}
	arr[pos-1] = num;
		
	for(int i = 0 ; i < length ; i++){
		printf("%d\t" , arr[i]);
	}
}

int delete(int *arr, int num , int length){	
	int pos;
	for(int x = 1 ; x <= num ; x++){	
	
		printf("\nEnter Position of Element to be deleted : ");
		scanf("%d" , &pos);
		
		printf("\nAfter Deletion : \n");
	
		for(int i = pos ; i < length ; i++){
			arr[i-1] = arr[i];
		}
		arr[length - 1] = 0;
		
		for(int i = 0 ; i < length - x  ; i++){
			printf("%d\t" , arr[i]);
		}
		
	}
}

int search(int *arr , int num , int length){
	bool found = 0;
	for(int i = 0 ; i < length ; i++){
		if(num == arr[i])
			printf("Element found at index : %d" , i);
			found = true;
	}
	
	if(found == false)
		printf("Element not found");
}
