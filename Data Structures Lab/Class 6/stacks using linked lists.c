#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
int currentSize = 0;

int dataEntry(){
	int data;
	printf("Enter STACK DATA : \n");
	scanf("%d" , &data);
	return data;
}

struct stack{
	int data;
	struct stack *next;
}*start = NULL;

struct stack *createNode(){
	struct stack *new_node = (struct stack *)malloc(sizeof(struct stack));
	if(new_node == NULL){
		printf("Memory allocation failed! \n");
		exit(1);
	}
	new_node->data = dataEntry();
	new_node->next = NULL;
	return new_node;
}

int isEmpty(){
	return start == NULL;
}

int isFull(){
	return currentSize >= SIZE;
}

void push(){
	if(isFull()){
		printf("Stack OVERFLOW!\n");
		return;
	}
	
	struct stack *new_node = createNode();
	new_node->next = start;
	start = new_node;
	currentSize++;	
}

int pop(){
	if(isEmpty()){
		printf("Stack UNDERFLOW!\n");
		return -1;
	}
	
	struct stack *temp = start;
	int node_data = temp->data;
	start = start->next;
	free(temp);
	currentSize--;
	return node_data;
}

// Recursive display function
void displayRecursive(struct stack *node) {
    if (node == NULL) {
        return;
    }
    printf("%d -> ", node->data);
    displayRecursive(node->next);
}

// Wrapper function for recursive display
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    displayRecursive(start);
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
