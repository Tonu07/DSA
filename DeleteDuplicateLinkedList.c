#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to remove duplicates from a sorted linked list
void removeDuplicates(struct node *head) {
    struct node *current = head;
    struct node *temp;

    // Traverse the list till the end
    while (current != NULL && current->next != NULL) {
        // If current node’s data is same as next node’s data
        if (current->data == current->next->data) {
            temp = current->next;           // store duplicate node
            current->next = current->next->next; // skip duplicate
            free(temp);                     // free memory
        } else {
            current = current->next;        // move to next node
        }
    }
}

// Function to print linked list
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Helper function to create a new node
struct node* newNode(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Main function
int main() {
    // Creating example list: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
    struct node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(3);
    head->next->next->next->next = newNode(4);
    head->next->next->next->next->next = newNode(4);
    head->next->next->next->next->next->next = newNode(5);

    printf("Original list:\n");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates:\n");
    printList(head);

    return 0;
}