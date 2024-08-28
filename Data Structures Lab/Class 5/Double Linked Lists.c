#include <stdio.h>
#include <stdlib.h>

// Function to get node data from user
int nodeData(){
	int data;
	printf("Enter data of node : \n");
	scanf("%d" , &data);
	return data;
}

// Structure for a double linked list
struct node{
	int data;
	struct node *next;
	struct node *prev;
}*start = NULL , *last = NULL; // Default values NULL


// Function to create and return a node
struct node *createNode(int data){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if(new_node == NULL){
		printf("Memory allocation failed");
		exit(1);
	}
	
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	return new_node;
}

// Function to add node if the list is empty
void nullCase(struct node *new_node){
	start = new_node;
	last = new_node;
}

// Function to add as the first node
void addAtStart(struct node *new_node){
	new_node->next = start;
	new_node->prev = NULL;
	start->prev = new_node;
	start = new_node;
}

// Function to add in the end of list
void addAtEnd(struct node *new_node){
	last->next = new_node;
	new_node->prev = last;
	new_node->next = NULL;
	last = new_node;
}

// Function to add after a given node
void addAfterNode(struct node *new_node , int data){
	struct node *temp = start;
	while(temp->data != data && temp->next != NULL) temp = temp->next;
	
	if(temp->next == NULL){
		printf("%d not in list!\n" , data);
		return;
	}
	else{
		new_node->next = temp->next;
		new_node->prev = temp;
		if(temp->next != NULL) temp->next->prev = new_node;
		else last = new_node;
		temp->next = new_node;
	}
}

// Function to add before a given node
void addBeforeNode(struct node *new_node , int data){
	struct node *temp = start;
	while(temp->data != data && temp!= NULL) temp = temp->next;
	
	if(temp == start) addAtStart(new_node);
	
	if(temp == NULL){
		printf("%d not in list!\n" , data);
		return;
	}
	else{
		temp->prev->next = new_node;
		new_node->next = temp;
		new_node->prev = temp->prev;
		if(temp == last) last = new_node;
		temp->prev = new_node;
	}
}
		
// Function to traverse and print the list
void traverseList(){
	if(start == NULL){
		printf("List is empty!\n");
		exit(1);
	}
	
	struct node *temp = start;
	while(temp!= NULL){
		printf(" %d ->" , temp->data);
		temp = temp->next;
	}
	printf(" NULL\n");
}

// Function to delete first node
void deleteFirst(){
	struct node *temp = start;
	start = temp->next;
	temp->next->prev = start;
	free(temp);
}

// Function to delete last node
void deleteLast(){
	struct node *temp = last;
	last = temp->prev;
	last->next = NULL;
	free(temp);
}

// Function to delete after a given node
void deleteAfterNode(int data){
	struct node *temp = start;
	while(temp->data != data && temp != NULL) temp = temp->next;
	if(temp == NULL){
		printf("%d not in list!\n" , data);
		return;
	}
	struct node *delete_node = temp->next;
	if (delete_node == NULL) {
		printf("No node present after the given node\nNode deletion failed!\n");
		return;
	}
	
	temp->next = delete_node->next; 
	if (delete_node->next != NULL) delete_node->next->prev = temp;
	else last = temp; 
	free(delete_node);
}

int main(){
	int running = 1;
	int task;
	do{
		printf("Enter task-------\n1: Create a node \n2: Traverse List\n3: Delete a node \n");
		scanf("%d" , &task);
		
		switch(task){
			// Case for creating and adding a node at different places in the double linked list
			case 1:
			{
				struct node *new_node = createNode( nodeData() );
				printf("Node created----\n");
				
				if(start == NULL) nullCase(new_node);
				else if(start == last) addAtEnd(new_node);
				else
				{
					int pos;
					printf("Where do you want to add the node-----\n1: Start \n2: End \n3: After a node \n4: Before a node\n");
					scanf("%d" , &pos);
					
					switch(pos)
					{
						case 1:
							addAtStart(new_node);
							break;
							
						case 2:
							addAtEnd(new_node);
							break;
							
						case 3:
							addAfterNode(new_node , nodeData() );
							break;
						
						case 4:	
							addBeforeNode(new_node , nodeData() );
							break;	
						
						default:
							printf("Invalid Input!\n");
					}
					printf("Node successfully added ---\n");
				}
				break;
			}
			
			// Case for traversing the list
			case 2:
				traverseList();
				break;
			
			case 3:
			{
				if(start == NULL){
					printf("List is empty!\n");
					exit(1);
				}
				else if(start == last) start = NULL , last = NULL;
				else
				{
					int pos;
					printf("Which node do you want to delete-----\n1: First \n2: Last \n3:After a node \n");
					scanf("%d" , &pos);
					
					switch(pos)
					{
						case 1:
							deleteFirst();
							break;
						
						case 2:
							deleteLast();
							break;
						
						case 3:
							deleteAfterNode( nodeData() );
							break;
							
						default:
							printf("Invalid Input!\n");
					}
				}
				printf("Node successfully deleted -----\n");
				break;
			}
				
			default:
				printf("Invalid Input!\n");
		}
		
		char next;
		printf("Do you want to continue? (Y/N)\n");
		scanf("\n%c" , &next);
		
		if(next == 'N' || next == 'n') running = 0;
	}while(running == 1);
	
	return 0;
}
