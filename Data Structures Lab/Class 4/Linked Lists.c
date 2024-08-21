#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LISTS 10

// Define a structure for a node
struct node {
    int data;
    struct node *next;
};

// Define a structure to hold multiple lists
struct list_manager {
    struct node *start;
} lists[MAX_LISTS];

// Function to get the length of a linked list
int get_length(struct node *start) {
    struct node *ptr = start;
    int length = 0;
    while (ptr != NULL) {
        ptr = ptr->next;
        length++;
    }
    return length;
}

// Function to traverse and print a linked list
void traverse(struct node *start) {
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

// Function to create and add a new node to a linked list with user-defined position
void createNode(struct list_manager *list, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory Allocation Failed!");
        exit(1);
    }

    ptr->data = data;
    ptr->next = NULL;

    if (list->start == NULL) {
        // If the list is empty, set the new node as the start
        list->start = ptr;
    } else {
        int input;
        struct node *temp = list->start;

        printf("Where do you want to add the node?\n1: Start\n2: End\n3: After a Node\n4: Before a Node\n");
        printf("Enter your choice: ");

        if (scanf("%d", &input) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            free(ptr); // Free memory if node is not added
            return;
        }

        while (getchar() != '\n'); // Clear the input buffer

        switch (input) {
            case 1:
                // Add node at the start
                ptr->next = list->start;
                list->start = ptr;
                break;
                
            case 2:
                // Add node at the end
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = ptr;
                break;
                
            case 3: {
                // Add node after a specific node
                int value;
                printf("Enter the value of the node after which to add: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    free(ptr); // Free memory if node is not added
                    return;
                }

                while (temp != NULL && temp->data != value) {
                    temp = temp->next;
                }
                if (temp == NULL) {
                    printf("Node with value %d not found.\n", value);
                    free(ptr); // Free memory if node is not added
                    return;
                }
                ptr->next = temp->next;
                temp->next = ptr;
                break;
            }
                
            case 4: {
                // Add node before a specific node
                int value;
                printf("Enter the value of the node before which to add: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    free(ptr); // Free memory if node is not added
                    return;
                }

                struct node *prev = NULL;
                while (temp != NULL && temp->data != value) {
                    prev = temp;
                    temp = temp->next;
                }
                if (temp == NULL) {
                	printf("Node with value %d not found.\n", value);
                    free(ptr); // Free memory if node is not added
                    return;
                }
                if (prev == NULL) {
                    // Insert at the start
                    ptr->next = list->start;
                    list->start = ptr;
                } else {
                    // Insert before a specific node
                    prev->next = ptr;
                    ptr->next = temp;
                }
                break;
            }
            
            default:
                // Handle invalid input
                printf("Invalid Input!\n");
                free(ptr); // Free memory if node is not added
                return;
        }
    }
    printf("----Node Created Successfully----\n");
}

// Seperate function to create a node at the end for merge() function
void createNodeAtEnd(struct list_manager *list, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory Allocation Failed!");
        exit(1);
    }

    ptr->data = data;
    ptr->next = NULL;

    if (list->start == NULL) {
        // If the list is empty, set the new node as the start
        list->start = ptr;
    } else {
        // Traverse to the end of the list
        struct node *temp = list->start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void deleteNode(struct list_manager *list){
	struct node *current = list->start;
	struct node *prev = NULL;
	
	if(list->start == NULL){
		printf("List is empty!");
		return;
	}
	else if (current->next == NULL) {
		// List has only one node
		free(current);
		list->start = NULL;
		return;
	    }
	else {
		int input;
		printf("Which node you want to delete?\n1: Beginning\n2: Last\n3: After a Node\n");
		printf("Enter your choice: ");

		if (scanf("%d", &input) != 1) {
		    printf("Invalid input. Please enter a number.\n");
		    while (getchar() != '\n'); // Clear the input buffer
		    return;
		}

		while (getchar() != '\n'); // Clear the input buffer

		switch (input) {
			case 1:
				list->start = current->next;
				break;
			
			case 2:
				while(current->next != NULL){
					prev =  current;
					current = current->next;
				}
				
				prev->next = NULL;
				break;
			
			case 3:
				int data;	
				struct node *next = current->next;
					
				printf("Enter data of previous node : \n");
				if (scanf("%d", &data) != 1) { 
				    printf("Invalid input. Please enter a number.\n");
				    while (getchar() != '\n'); // Clear the input buffer
				    return;
				}
		        
		        	while (getchar() != '\n'); // Clear the input buffer
				
				while(current->data != data && current->next != NULL){
					current = next;
					next = current->next;
				}
				
				if(current->next == NULL){
					printf("%d not in list" , data);
				}
				else {
					current->next = next->next;
				}
				break;
					
			default:
				// Handle invalid input
                		printf("Invalid Input!\n");
                		return;
		}
	}
	
	printf("---------- Node deleted Successfully -----------\n");
}

// Function to reverse a linked list
void reverse(struct list_manager *list) {
    struct node *ptr = list->start;
    struct node *prev = NULL;
    struct node *current = ptr;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->start = prev;
}

// Function to merge sorted linked lists
void merge(struct list_manager *list1 , struct list_manager *list2 , struct list_manager *list3){
    list3->start = NULL;

    // Check for valid lists
    if (list1 == NULL || list2 == NULL || list3 == NULL) {
        printf("One or more list pointers are NULL.\n");
        return;
    }
    
	struct node *temp1 = list1->start;
	struct node *temp2 = list2->start;
	struct node *temp3 = list3->start;

	while( (temp1 != NULL) && (temp2 != NULL) ){
		if(temp1->data < temp2->data){
			createNodeAtEnd(list3 , temp1->data);
			temp1 = temp1->next;
		}
		
		else if(temp1->data > temp2->data){
			createNodeAtEnd(list3 , temp2->data);
			temp2 = temp2->next;
		}
		
		// Both are equal , add one of them
		else{
			createNodeAtEnd(list3 , temp1->data);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}

	// Append remaining nodes from list 1
	while(temp1 != NULL){
		createNodeAtEnd(list3 , temp1->data);
		temp1 = temp1->next;
	}

	// Append remaining nodes from list 2
	while(temp2 != NULL){
		createNodeAtEnd(list3 , temp2->data);
		temp2 = temp2->next;
	}
}

void sort(struct list_manager *list) {
    if (list->start == NULL) return;

    int swapped;
    struct node *ptr1;
    struct node *ptr2 = NULL;

    do {
        swapped = 0;
        ptr1 = list->start;

        while (ptr1->next != ptr2) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1; // Mark the end of the sorted portion
    } while (swapped);
    
    printf("---------- List Sorted ----------");
}

int main() {
    int input;
    bool loop = true;
    int list_index = 0;

    while (loop) {
        printf("\nList Management Menu:\n");
        printf("1: Select List (0 to %d)\n", MAX_LISTS - 1);
        printf("2: Create a node\n3: Traverse & Print\n4: Reverse\n5: Merge Sorted lists\n6: Delete a Node\n7: Sort list\n8: Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &input) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        while (getchar() != '\n'); // Clear the input buffer

        switch (input) {
            case 1:
                // Select the list to operate on
                printf("Enter list index (0 to %d): ", MAX_LISTS - 1);
                if (scanf("%d", &list_index) != 1 || list_index < 0 || list_index >= MAX_LISTS) {
                    printf("Invalid list index.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    continue;
                }
                while (getchar() != '\n'); // Clear the input buffer
                break;
                
            case 2:
		        int data;
		        printf("Enter data: ");
		        if (scanf("%d", &data) != 1) { 
		            printf("Invalid input. Please enter a number.\n");
		            while (getchar() != '\n'); // Clear the input buffer
		            continue;
		        }
		        
		        while (getchar() != '\n'); // Clear the input buffer
		        
		        createNode(&lists[list_index], data);
                break;
                
            case 3:
                traverse(lists[list_index].start);
                break;
                
            case 4:
                reverse(&lists[list_index]);
                break;
                
            case 5:
            	merge(&lists[0] , &lists[1] , &lists[2]);
            	break;
            	
            case 6:
            	deleteNode(&lists[list_index]);
            	break;
            
            case 7:
            	sort(&lists[list_index]);
            	break;
            	
            case 8:
                loop = false;
                break;
                
            default:
                printf("Invalid Input\n");
        }
        
        if (input != 8) { // Check if the user chose to exit
            char ask;
            printf("Do you want to continue? (y/n): ");
            ask = getchar();
            while (getchar() != '\n'); // Clear the input buffer

            if (ask == 'n' || ask == 'N') loop = false;
        }
    }
    return 0;
}

