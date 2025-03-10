#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isBalanced(char* n) {
    int stack[100];
    int top = -1;
    int len = strlen(n);

    for (int i = 0; i < len; i++) {
        int num = n[i] - '0';
        if (num >= 1 && num <= 5) {
            stack[++top] = num;
        } else {
            if (top == -1) return false;
            int topNum = stack[top--];
            if (num != 10 - topNum) return false;
        }
    }
    return top == -1;
}

int main() {
    char n1[] = "19192846";
    char n2[] = "123789";
    char n3[] = "146";
    char n4[] = "251598";

    printf("Input: %s\nOutput: %s\n", n1, isBalanced(n1) ? "true" : "false");
    printf("Input: %s\nOutput: %s\n", n2, isBalanced(n2) ? "true" : "false");
    printf("Input: %s\nOutput: %s\n", n3, isBalanced(n3) ? "true" : "false");
    printf("Input: %s\nOutput: %s\n", n4, isBalanced(n4) ? "true" : "false");

    return 0;
}