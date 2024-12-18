#include <stdio.h>
#include <string.h>
#define MAX 50

char stack_arr[MAX];
char post[MAX];
int top = -1;

// Push an element onto the stack
void push(char val) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack_arr[top] = val;
    }
}

// Pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0'; // Return null character for underflow
    } else {
        return stack_arr[top--];
    }
}

// Get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0; // Default precedence for non-operators
    }
}

// Convert infix to postfix
void int_to_post(char ar[], int size) {
    char op;
    int j = 0;

    for (int i = 0; i < size; i++) {
        op = ar[i];

        if (op == '(') {
            push(op);
        } else if (op == ')') {
            // Pop until '(' is found
            while (top != -1 && stack_arr[top] != '(') {
                post[j++] = pop();
            }
            pop(); // Remove '(' from the stack
        } else if (op == '+' || op == '-' || op == '*' || op == '/') {
            // Handle operators
            while (top != -1 && precedence(stack_arr[top]) >= precedence(op)) {
                post[j++] = pop();
            }
            push(op);
        } else {
            // Operands go directly to postfix
            post[j++] = op;
        }
    }

    // Pop any remaining operators
    while (top != -1) {
        post[j++] = pop();
    }

    post[j] = '\0'; // Null-terminate the postfix expression
}

// Print the postfix expression
void prnt() {
    printf("Desired output is:\n%s\n", post);
}

int main() {
    char ex[50];

    printf("Enter the expression: ");
    fgets(ex, sizeof(ex), stdin);
    ex[strcspn(ex, "\n")] = '\0'; // Remove newline character if present

    int l = strlen(ex);
    int_to_post(ex, l);
    prnt();

    return 0;
}
