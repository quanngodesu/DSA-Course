#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Function to add an element to the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
        printf("Pushed %d\n", value);
    }
}

// Function to remove an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped %d\n", stack[top--]);
    }
}

// Function to peek the top element
void peek() {
    if (top != -1) {
        printf("Top element is %d\n", stack[top]);
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    peek();      // Output: Top element is 30
    pop();       // Output: Popped 30
    pop();       // Output: Popped 20
    peek();      // Output: Top element is 10
    pop();       // Output: Popped 10
    pop();       // Output: Stack Underflow
    return 0;
}
