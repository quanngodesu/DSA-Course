#include <stdio.h>

#define MAX 4  // Define the maximum size of the stack

// Check if the stack is empty
int isEmpty(int top) {
    return top == -1;
}

// Check if the stack is full
int isFull(int top) {
    return top == MAX - 1;
}

// Push an element to the stack
void push(int stack[], int *top, int value) {
    if (isFull(*top)) {
        printf("Stack is full! Cannot push %d\n", value);
        return;
    }
    stack[++(*top)] = value;  // Increment top and add value to stack
    printf("%d pushed to the stack\n", value);
}

// Pop an element from the stack
int pop(int stack[], int *top) {
    if (isEmpty(*top)) {
        printf("Stack is empty! Cannot pop\n");
        return -1;
    }
    int poppedValue = stack[(*top)--];  // Return the top element and decrement top
    printf("%d popped from the stack\n", poppedValue);
    return poppedValue;
}

// Display the stack
void display(int stack[], int top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int stack[MAX];  
    int top = -1;    // Initialize the top variable

    int k[8] = {3, 1, 6, 9, 5, 7, 8, 2};
    int a[8] = {1, 0, 1, 1, 1, 1, 1, 0};

    // Perform stack operations based on arrays k[] and a[]
    for (int i = 0; i < 8; i++) {
        if (a[i] == 1) {
            push(stack, &top, k[i]);  // Push element to stack
        } else {
            pop(stack, &top);         // Pop element from stack
            push(stack, &top, k[i]);
        }
    }

    display(stack, top);

    return 0;
}
