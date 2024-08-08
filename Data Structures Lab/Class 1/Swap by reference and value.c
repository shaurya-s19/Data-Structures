// Swap 2 numbers using call by reference & value - no third variable
#include <stdio.h>
void swap_reference(int *num1 , int *num2);
void swap_value(int a , int b);

int main(){
	int num1 = 10 , num2 = 20;
	
	//call by reference
	swap_reference(&num1 , &num2);
	printf("\nSwapped Values by reference : %d %d" , num1 , num2);
	
	//call by value
	swap_value(num1 , num2);
	printf("\nSwapped Values by value : %d %d" , num1 , num2);
	
	return 0;
}

void swap_reference(int *num1 , int *num2){
	*num1 = *num1 + *num2;
	*num2 = *num1 - *num2;
	*num1 = *num1 - *num2;
}

void swap_value(int a , int b){
	a = a + b;
	b = a - b;
	a = a - b;
}

