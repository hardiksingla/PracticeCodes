#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int items[MAX_SIZE];
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

int evaluatePostfix(const char* postfixExpression) {
    struct Stack operandStack;
    initialize(&operandStack);

    for (int i = 0; postfixExpression[i] != '\0'; i++) {
        char c = postfixExpression[i];

        if (c >= '0' && c <= '9') {
            push(&operandStack, c - '0');
        } else if (c == ' ') {
            continue;
        } else {
            int operand2 = pop(&operandStack);
            int operand1 = pop(&operandStack);

            switch (c) {
                case '+':
                    push(&operandStack, operand1 + operand2);
                    break;
                case '-':
                    push(&operandStack, operand1 - operand2);
                    break;
                case '*':
                    push(&operandStack, operand1 * operand2);
                    break;
                case '/':
                    push(&operandStack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&operandStack);
}

int main() {
    char postfixExpression[MAX_SIZE];
    
    printf("Enter the postfix expression: ");
    fgets(postfixExpression, sizeof(postfixExpression), stdin);
    postfixExpression[strcspn(postfixExpression, "\n")] = '\0';

    int result = evaluatePostfix(postfixExpression);

    printf("Result of evaluation: %d\n", result);

    return 0;
}
