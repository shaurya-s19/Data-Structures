#include <stdio.h>
#include <stdlib.h>

int data_entry(){
	int data;
	printf("Enter node data : \n");
	scanf("%d" , &data);
	return data;
}

struct node{
	int data;
	struct node *next;
}*start = NULL , *last = NULL;

struct node *createNode(int data){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void addAtStart(struct node *new_node){
	start = new_node;
	last = new_node;
	new_node->next = start;
}

void addAtLast(struct node *new_node){
	if(start == NULL){
		addAtStart(new_node);
	}
	last->next = new_node;
	new_node->next = start;
	last = new_node;
}

void addBeforeNode(struct node *new_node , int data){
	if(start == NULL){
		addAtStart(new_node);
		return;
	}
	struct node *temp = start;
	struct node *prev;
	do{
		prev = temp;
		temp = temp->next;
	}while(temp->data != data && temp != start);
	
	if(temp == start){
		printf("Node not in list");
		return;
	}
	new_node->next = temp;
	prev->next = new_node;
}

void addAfterNode(struct node *new_node , int data){
	if(start == NULL){
		addAtStart(new_node);
		return;
	}
	
	struct node *temp = start;
	while(temp->data != data && temp != start){
		temp = temp->next;
	}
	
	if(temp == last){
		addAtLast(new_node);
		return;
	}
	
	new_node->next = temp->next;
	temp->next = new_node;
}

void traverse(){
	if(start == NULL){
		printf("List is empty!");
		return;
	}
	struct node *temp = start;
	do{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}while(temp != start);
	
	printf(" NULL\n");
}

void deleteStart(){
	struct node *temp = start;
	last->next = temp->next;
	start = start->next;
	free(temp);
}

void deleteLast(){
	struct node *temp = start;
	struct node *prev;
	while(temp != last){
		prev = temp;
		temp = temp->next;
	}
	prev->next = start;
	free(temp);
}

int main(){
	while(1){
		int runner;
		printf("1: Create a node \n2: Traverse \n3: Delete\n");
		scanf("%d" , &runner);
		switch(runner){
			case 1:
				int data = data_entry();
				struct node *new_node = createNode(data);
				
				int node_runner;
				printf("1: Start \n2: End \n3: Before Node \n4: After Node\n");
				scanf("%d" , &node_runner);
				
				switch(node_runner){
					case 1:
						addAtStart(new_node);
						break;
					case 2:
						addAtLast(new_node);
						break;
					case 3:
						data = data_entry();
						addBeforeNode(new_node , data);
						break;
					case 4:
						data = data_entry();
						addAfterNode(new_node , data);
						break;
					default:
						printf("Invalid !");
				}
				printf("Node created-------------\n");
				break;
			case 2:
				traverse();
				break;
			case 3:
				printf("1: Start \n2: End \n3: Before Node \n4: After Node\n");
				scanf("%d" , &node_runner);
				
				switch(node_runner){
					case 1:
						deleteStart();
						break;
					case 2:
						deleteLast();
						break;
					default:
						printf("Invalid");
				}
				printf("Node deleted-----------------\n");
				break;
				
			default:
				printf("Invalid !");
		}
		
		char runner_condition;
		printf("Do you want to continue? (Y/N)");
		scanf(" %c" , &runner_condition);
		
		if(runner_condition == 'n' || runner_condition == 'N') break;
	}
	return 0;
}
		
	
