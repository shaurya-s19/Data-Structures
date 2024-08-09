#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node in the polynomial
struct Node {
    int data;       // Coefficient of the term
    int degree;     // Degree of the term
    struct Node *next; // Pointer to the next term
};

// Function to insert a new term into the polynomial
struct Node* insert(struct Node *polynomial, int data, int degree) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->degree = degree;
    ptr->next = NULL;

    // If the list is empty or needs to be inserted at the beginning
    if (polynomial == NULL || polynomial->degree < degree) {
        ptr->next = polynomial;
        return ptr;
    }

    // Traverse to the correct position
    struct Node *p = polynomial;
    while (p->next != NULL && p->next->degree > degree) {
        p = p->next;
    }
    
    // If the term with the same degree exists, update its coefficient
    if (p->next != NULL && p->next->degree == degree) {
        p->next->data += data;
        free(ptr);
    } else {
        // Insert the new node
        ptr->next = p->next;
        p->next = ptr;
    }

    return polynomial;
}

// Function to traverse and print the polynomial
void LinkedListTraversal(struct Node *ptr) {
    printf("\nReceived polynomial  ---> ");
    
    bool firstTerm = true;
    while (ptr != NULL) {
        if (ptr->data != 0) { // Only print non-zero terms
            if (!firstTerm) {
                printf(" + ");
            }
            printf("%dx^%d", ptr->data, ptr->degree);
            firstTerm = false;
        }
        ptr = ptr->next;
    }
    if (firstTerm) {
        printf("0"); // Handle case where all terms are zero
    }
    printf("\n");
}

// Function to sum two polynomials
struct Node* sum(struct Node *polynomial1, struct Node *polynomial2) {
    struct Node *resultant = NULL;
    struct Node *p1 = polynomial1;
    struct Node *p2 = polynomial2;

    // Traverse both polynomials
    while (p1 != NULL && p2 != NULL) {
        if (p1->degree == p2->degree) {
            // Add coefficients if degrees match
            int sum = p1->data + p2->data;
            resultant = insert(resultant, sum, p1->degree);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->degree > p2->degree) {
            // Insert term from polynomial1
            resultant = insert(resultant, p1->data, p1->degree);
            p1 = p1->next;
        } else {
            // Insert term from polynomial2
            resultant = insert(resultant, p2->data, p2->degree);
            p2 = p2->next;
        }
    }

    // Insert remaining terms from polynomial1
    while (p1 != NULL) {
        resultant = insert(resultant, p1->data, p1->degree);
        p1 = p1->next;
    }

    // Insert remaining terms from polynomial2
    while (p2 != NULL) {
        resultant = insert(resultant, p2->data, p2->degree);
        p2 = p2->next;
    }

    return resultant;
}

int main() {
    // Define Linked lists for different polynomials
    struct Node *polynomial1 = NULL;
    struct Node *polynomial2 = NULL;

    for (int inputs = 1; inputs <= 2; inputs++) {
        int degree, val, terms;
        printf("\nEnter total terms in the polynomial %d : ", inputs);
        scanf("%d", &terms);

        // Taking input for polynomial
        for (int i = 0; i < terms; i++) {
            printf("\nEnter Degree : ");
            scanf("%d", &degree);

            printf("\nEnter Coefficient of Degree %d : ", degree);
            scanf("%d", &val);

            // Insert new term into the polynomial
            if (inputs == 1) {
                polynomial1 = insert(polynomial1, val, degree);
            } else {
                polynomial2 = insert(polynomial2, val, degree);
            }
        }

        // Print the polynomial
        if (inputs == 1) {
            printf("Polynomial 1:");
            LinkedListTraversal(polynomial1);
        } else {
            printf("Polynomial 2:");
            LinkedListTraversal(polynomial2);
        }
    }
    
    // Add Polynomials and print the result
    struct Node *resultant = sum(polynomial1, polynomial2);
    printf("Sum of polynomials:");
    LinkedListTraversal(resultant);

    // Free memory
    struct Node *current = polynomial1;
    struct Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    current = polynomial2;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    current = resultant;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

