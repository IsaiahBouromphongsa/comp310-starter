#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// LinkedList structure
struct LinkedList {
    struct Node* head;
};

// Function to push a new node at the beginning of the linked list
void push(struct LinkedList* llist, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = llist->head;
    llist->head = new_node;
}

// Function to delete a node with a given key from the linked list
void deleteNode(struct LinkedList* llist, int key) {
    struct Node *temp = llist->head, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        llist->head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct LinkedList* llist) {
    struct Node* tnode = llist->head;
    while (tnode != NULL) {
        printf("%d ", tnode->data);
        tnode = tnode->next;
    }
}

// Main function
int main() {
    struct LinkedList llist;
    llist.head = NULL;

    push(&llist, 7);
    push(&llist, 1);
    push(&llist, 3);
    push(&llist, 2);

    printf("Created Linked list is:\n");
    printList(&llist);

    deleteNode(&llist, 1);

    printf("\nLinked List after Deletion of 1:\n");
    printList(&llist);

    return 0;
}
