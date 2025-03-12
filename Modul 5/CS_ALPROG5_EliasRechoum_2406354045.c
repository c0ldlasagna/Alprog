#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char* data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
}Stack;

void popLast(Stack * stack){
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* current = stack->top;
    Node* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        stack->top = NULL;
    }
    free(current);
}

void pop(Stack* stack){
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

void push(Stack* stack, char* data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

void peek(Stack* stack){
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", stack->top->data);
}

void display(Stack* stack){
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* current = stack->top;
    printf("History:\n");
    while (current != NULL) {
        printf("%s", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    int choice;
    char data[64];
    Stack history;
    history.top = NULL;
    while(1){
        printf("1. Add history\n");
        printf("2. Delete first history\n");
        printf("3. Delete last history\n");
        printf("4. Print all history\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        while(getchar() != '\n'); 
        switch (choice)
        {
        case 1:
            printf("Enter history: ");
            fgets(data,64,stdin);
            push(&history, data);
            printf("\n");
            break;
        case 2:
            pop(&history);
            printf("\n");
            break;
        case 3:
            popLast(&history);
            printf("\n");
            break;
        case 4:
            display(&history);
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Invalid input.\n");
            printf("\n");
            break;
        }
    }    
}