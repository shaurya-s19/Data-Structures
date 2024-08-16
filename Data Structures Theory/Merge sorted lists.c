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

