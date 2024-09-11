#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

// Structure of Stack
struct stack{
	int size;
	int top;
	int *arr;
};

// Checks for empty stack
int isEmpty(struct stack *stack){
	if(stack->top == -1) return 1;
	return 0;
}

// Checks for stack overflow
int isFull(struct stack *stack){
	if(stack->top == stack->size - 1) return 1;
	return 0;
}

// Function to push value into stack
void push(struct stack *stack , int value){
	if(isFull(stack)){
		printf("Stack Overflow\n");
		return;
	}
	stack->top++;
	stack->arr[stack->top] = value;
	printf("Pushed %d in the stack ---\n", value);
}

// Function to pop value from stack
int pop(struct stack *stack){
	if(isEmpty(stack)){
		printf("Stack Underflow\n");
		return -1;
	}
	int value = stack->arr[stack->top];
	stack->top--;
	return value;
}

// Function to display a value at a given position
int peek(struct stack *stack , int position){
	if(stack->top -position +1 < 0){
		printf("Invalid position!\n");
		return -1;
	}
	return stack->arr[stack->top - position + 1];
}

// Function to traverse and print all the elements of the stack
void traverse(struct stack *stack){
	if(isEmpty(stack)){
		printf("Stack is empty!");
		return;
	}
	int index = 0;
	while(index != stack->top + 1){
		printf("Value at position %d --> %d \n", index+1 , stack->arr[index]);
		index++;
	}
}

int main(){
	
	// Creating a structure stack that has a max size and contains array of integers as data
	struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
	stack->size = SIZE;
	stack->top = -1;
	stack->arr = (int *)malloc(stack->size * sizeof(int));
	
	int running = 1;
	int task;
	do{
		printf("Enter task to perform -----\n1: Push \n2: Pop \n3: Peek\n4: Traverse\n5: Top & Bottom\n");
		scanf(" %d" , &task);
		
		switch(task){
		
			// Pushes value into stack
			case 1:
				int value;
				printf("Enter value : \n");
				scanf(" %d" , &value);
				push(stack , value);
				break;
				
			// Pops value from stack
			case 2:
				int deleted = pop(stack);
				if(deleted != -1) printf("Deleted %d from stack\n" , deleted);
				break;
				
			// Print value at a given position
			case 3:
				int pos;
				printf("Enter position : \n");
				scanf(" %d" , &pos);
				int data = peek(stack , pos);
				if(data != -1) printf("Value at %d is %d \n", pos , data);
				break;
			
			// Print stack elements	
			case 4:
				traverse(stack);
				break;
			
			// Print top and bottom elements of the stack
			case 5:
				printf("Value at top  --> %d \n", stack->arr[stack->top]);
				printf("Value at bottom  ---> %d \n" , stack->arr[0]);
				break;
			
			// Default case	
			default:
				printf("Invalid input!\n");
		}
		
		char ask;
		printf("Do you want to continue? (Y/N)\n");
		scanf("\n %c" , &ask);
		
		if(ask == 'n' || ask == 'N') running = 0;
	}while(running == 1);
	return 0;
}
