#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void findTopThree(Node* head) {
    int first = -1, second = -1, third = -1;
    Node* current = head;
    while (current != NULL) {
        if (current->data > first) {
            third = second;
            second = first;
            first = current->data;
        } else if (current->data > second) {
            third = second;
            second = current->data;
        } else if (current->data > third) {
            third = current->data;
        }
        current = current->next;
    }
    printf("Top 3 largest numbers are: %d, %d, %d\n", first, second, third);
}

int main() {
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 4);
    insert(&head, 50);
    insert(&head, 30);
    insert(&head, 15);

    findTopThree(head);

    return 0;
}