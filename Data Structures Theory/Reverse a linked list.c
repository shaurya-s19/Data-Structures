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
