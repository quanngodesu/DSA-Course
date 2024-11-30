#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Dequeued %d\n", queue[front++]);
        if (front > rear) {
            front = rear = -1;  // Reset when all elements are dequeued
        }
    }
}

// Function to peek the front element
void peek() {
    if (front != -1) {
        printf("Front element is %d\n", queue[front]);
    } else {
        printf("Queue is empty\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    peek();      // Output: Front element is 10
    dequeue();   // Output: Dequeued 10
    dequeue();   // Output: Dequeued 20
    peek();      // Output: Front element is 30
    dequeue();   // Output: Dequeued 30
    dequeue();   // Output: Queue Underflow
    return 0;
}
