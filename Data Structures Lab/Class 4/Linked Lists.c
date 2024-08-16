#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
} *start = NULL;

// Function to get the length of the linked list
int get_length() {
    struct node *ptr = start;
    int length = 0;
    while (ptr != NULL) {
        ptr = ptr->next;
        length++;
    }
    return length;
}

// Function to traverse and print the linked list
void traverse() {
    struct node *ptr = start;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to create and add a new node to the linked list
void createNode(int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory Allocation Failed!");
        exit(1);
    }

    ptr->data = data;
    ptr->next = NULL;
    
    if (start == NULL) {
        // If the list is empty, set the new node as the start
        start = ptr;
    } 
    else {
        int input;
        struct node *temp = start;
        
        printf("Where do you want to add the node?\n1: Start\n2: End\n3: After a Node\n4: Before a Node\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &input) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            return;
        }
        
        while (getchar() != '\n'); // Clear the input buffer
        
        switch (input) {
            case 1:
                // Add node at the start
                ptr->next = start;
                start = ptr;
                break;
                
            case 2:
                // Add node at the end
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = ptr;
                break;
                
            default:
                // Handle invalid input
                printf("Invalid Input!\n");
                free(ptr); // Free memory if node is not added
                return;
        }
    }
    printf("----Node Created Successfully----\n");
}

// Function to reverse a linked list
void reverse(){
	struct node *ptr = start;
	struct node *prev = NULL;
	struct node *current = ptr;
	struct node *next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	start = prev;
}

int main() {
    int input;
    bool loop = true;
    
    while (loop) {
        printf("\n1: Create a node\n2: Traverse & Print\n3: Reverse\n4: Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &input) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        while (getchar() != '\n'); // Clear the input buffer
        
        switch (input) {
            case 1:
                int data;
                printf("Enter data: ");
                if (scanf("%d", &data) != 1) { 
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    continue;
                }
                
                while (getchar() != '\n'); // Clear the input buffer
                
                createNode(data);
                break;
                
            case 2:
                traverse();
                break;
                
            case 3:
                reverse();
                break;
                
            case 4:
                loop = false;
                break;
                
            default:
                printf("Invalid Input\n");
        }
        
        if (input != 4) { // Check if the user chose to exit
            char ask;
            printf("Do you want to continue? (y/n): ");
            ask = getchar();
            while (getchar() != '\n'); // Clear the input buffer

            if (ask == 'n' || ask == 'N') loop = false;
        }
    }
    return 0;
}

