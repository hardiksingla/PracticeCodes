#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

int getPrecedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(const char* infixExpression, char* postfixExpression) {
    struct Stack operatorStack;
    initialize(&operatorStack);
    int postfixIndex = 0;
    
    for (int i = 0; infixExpression[i] != '\0'; i++) {
        char c = infixExpression[i];

        if (c == ' ' || c == ',') {
            continue;
        } else if (isalnum(c)) {
            while (isalnum(c)) {
                postfixExpression[postfixIndex++] = c;
                c = infixExpression[++i];
            }
            i--;
            postfixExpression[postfixIndex++] = ' ';
        } else if (c == '(') {
            push(&operatorStack, c);
        } else if (c == ')') {
            while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != '(') {
                postfixExpression[postfixIndex++] = pop(&operatorStack);
                postfixExpression[postfixIndex++] = ' ';
            }
            if (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] == '(') {
                pop(&operatorStack);
            }
        } else {
            while (!isEmpty(&operatorStack) && getPrecedence(c) <= getPrecedence(operatorStack.items[operatorStack.top])) {
                postfixExpression[postfixIndex++] = pop(&operatorStack);
                postfixExpression[postfixIndex++] = ' ';
            }
            push(&operatorStack, c);
        }
    }

    while (!isEmpty(&operatorStack)) {
        postfixExpression[postfixIndex++] = pop(&operatorStack);
        postfixExpression[postfixIndex++] = ' ';
    }
    
    postfixExpression[postfixIndex] = '\0';
}

int main() {
    char infixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE * 2];

    printf("Enter the infix expression: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);
    infixExpression[strcspn(infixExpression, "\n")] = '\0';

    infixToPostfix(infixExpression, postfixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    return 0;
}
