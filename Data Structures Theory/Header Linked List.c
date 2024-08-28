#include <stdio.h>
#include <stdlib.h>

struct data_node {
    char name[30];
    int roll;
    char gender;
    float cgpa;
    struct data_node *next;
};

struct head_node {
    int cboys, cgirls;
    struct data_node *next;
} *start = NULL;

struct head_node* create_head_node() {
    struct head_node *new_node = (struct head_node*)malloc(sizeof(struct head_node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->cboys = 0;   
    new_node->cgirls = 0;  
    new_node->next = NULL;
    return new_node;
}

struct data_node* createNode() {
    struct data_node *new_node = (struct data_node *)malloc(sizeof(struct data_node));
    if(new_node == NULL){
        printf("Memory allocation failed");
        exit(1);
    }

    printf("Enter name : ");
    scanf("%29s", new_node->name);
    getchar(); 

    printf("Enter Gender : ");
    new_node->gender = getchar();

    printf("Enter roll no. and cgpa : ");
    scanf("%d %f", &new_node->roll, &new_node->cgpa);

    new_node->next = NULL;
    return new_node;
}

void addNodeAtEnd(struct data_node *new_node) {
    if (start == NULL) {
        start = create_head_node();
    }
    
    struct data_node *temp = start->next;
    if (temp == NULL) {
        start->next = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // Update counts based on gender
    if (new_node->gender == 'M' || new_node->gender == 'm') {
        start->cboys++;
    } else if (new_node->gender == 'F' || new_node->gender == 'f') {
        start->cgirls++;
    }
}

void traverse() {
    if (start == NULL || start->next == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("No. of boys -> %d\n", start->cboys);
    printf("No. of girls -> %d\n", start->cgirls);
    
    struct data_node *temp = start->next;
    while (temp != NULL) {
        printf("Name : %s\n", temp->name);
        printf("Roll : %d\n", temp->roll);
        printf("Gender : %c\n", temp->gender);
        printf("CGPA : %f\n", temp->cgpa);
        printf("----------------------------------\n");
        temp = temp->next;
    }
}

int main() {
    int running = 1;
    do {
        struct data_node *node = createNode();
        addNodeAtEnd(node);
        
        char ask;
        printf("Do you want to add a new node ? (Y/N) : ");
        scanf(" %c", &ask);

        if (ask == 'N' || ask == 'n') {
            running = 0;
        }
        
    } while (running == 1);
    
    traverse();
    
    return 0;
}

