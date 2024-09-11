#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int dataEntry(){
	int data;
	printf("ENTER STACK DATA : \n");
	scanf("%d" , &data);
	return data;
}

struct stack{
	int size;
	int top;
	int *arr;
};

void initializeStack(struct stack *stack){
	stack->size = SIZE;
	stack->top = -1;
	stack->arr = (int *)malloc(SIZE * sizeof(int));
	if(stack->arr == NULL){
		printf("Memory allocation failed\n");
		exit(1);
	} 
}

int isEmpty(struct stack *stack){
	return stack->top == -1;
}

int isFull(struct stack *stack){
	return stack->top == stack->size - 1;
}

void push(struct stack *stack , int data){
	if(isFull(stack)){
		printf("Stack FULL!\n");
		return;
	}
	
	stack->arr[++(stack->top)] = data;
	printf("Pushed into Stack Successfully!\n");
}

int pop(struct stack *stack){
	if(isEmpty(stack)){
		printf("Stack EMPTY!\n");
		return -1;
	}

	return stack->arr[(stack->top)--];
}

int peek(struct stack *stack){
	if(isEmpty(stack)){
		printf("Stack EMPTY!\n");
		return -1;
	}
	
	return stack->arr[stack->top];
}

void printStack(struct stack *stack){
	if(isEmpty(stack)){
		return;
	}
	printf("%d -> ",stack->arr[stack->top]);
	(stack->top)--;
	printStack(stack);
	(stack->top)++;
}

int main(){
	struct stack arr1;
	initializeStack(&arr1);
	
	while(1){
		printf("Enter operation :\n1: PUSH\n2: POP\n3: PEEK\n4: PRINT STACK\n");
		int switchcase;
		scanf("%d" , &switchcase);
		
		switch(switchcase){
			case 1:
				int var = dataEntry();
				push(&arr1 , var);
				break;
			case 2:
				if(pop(&arr1) != -1) printf("Popped top element successfully!\n");
				break;
			case 3:
				printf("TOP ELEMENT --> %d\n" , peek(&arr1));
				break;
			case 4:
				printStack(&arr1);
				printf(" NULL\n");
				break;
			default:
				printf("Invalid INPUT!\n");
		}
		
		printf("Do you want to continue? (Y/N)");
		char runner;
		scanf(" %c" , &runner);
		
		if(runner == 'n' || runner == 'N') break;
	}
	return 0;
}
