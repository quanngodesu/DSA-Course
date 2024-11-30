#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Event {
    char title[100];
    int start_time; // HHMM format
    int end_time;
    int priority; // Lower number indicates higher priority
    struct Event* left;
    struct Event* right;
} Event;

typedef struct Reminder {
    char message[100];
    struct Reminder* next;
} Reminder;

typedef struct Queue {
    Reminder* front;
    Reminder* rear;
} Queue;

// Function prototypes for event management
Event* createEvent(char* title, int start_time, int end_time, int priority);
Event* insertEvent(Event* root, Event* new_event);
void inOrderTraversal(Event* root);
void freeTree(Event* root);

// Function prototypes for reminder management
Queue* createQueue();
void enqueue(Queue* q, char* message);
void displayReminders(Queue* q);
void freeQueue(Queue* q);

int main() {
    Event* root = NULL;
    Queue* reminders = createQueue();
    int n, start_time, end_time, priority;
    char title[100];

    // Input number of events
    printf("Enter the number of events: ");
    scanf("%d", &n);
    getchar(); // Consume the newline character

    for (int i = 0; i < n; i++) {
        // Input event details
        printf("Enter title for event %d: ", i + 1);
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = 0; // Remove newline

        printf("Enter start time (HHMM) for event %d: ", i + 1);
        scanf("%d", &start_time);
        printf("Enter end time (HHMM) for event %d: ", i + 1);
        scanf("%d", &end_time);
        printf("Enter priority (lower number indicates higher priority) for event %d: ", i + 1);
        scanf("%d", &priority);
        getchar(); // Consume the newline character

        // Create and insert the event
        root = insertEvent(root, createEvent(title, start_time, end_time, priority));
    }

    // Display events in table format
    printf("\nScheduled Events:\n");
    printf("-------------------------------------------------------------\n");
    printf("| %-25s | %-10s | %-10s | %-8s |\n", "Event Title", "Start Time", "End Time", "Priority");
    printf("-------------------------------------------------------------\n");
    inOrderTraversal(root);
    printf("-------------------------------------------------------------\n");

    // Input number of reminders
    printf("Enter the number of reminders: ");
    scanf("%d", &n);
    getchar(); // Consume the newline character

    for (int i = 0; i < n; i++) {
        // Input reminder message
        printf("Enter reminder message %d: ", i + 1);
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = 0; // Remove newline

        // Enqueue the reminder
        enqueue(reminders, title);
    }

    // Display reminders
    printf("\nReminders:\n");
    displayReminders(reminders);

    // Clean up
    freeTree(root);
    freeQueue(reminders);
    return 0;
}

// Create a new event
Event* createEvent(char* title, int start_time, int end_time, int priority) {
    Event* new_event = (Event*)malloc(sizeof(Event));
    strcpy(new_event->title, title);
    new_event->start_time = start_time;
    new_event->end_time = end_time;
    new_event->priority = priority;
    new_event->left = new_event->right = NULL;
    return new_event;
}

// Insert an event into the BST
Event* insertEvent(Event* root, Event* new_event) {
    if (root == NULL) return new_event;
    if (new_event->start_time < root->start_time) {
        root->left = insertEvent(root->left, new_event);
    } else {
        root->right = insertEvent(root->right, new_event);
    }
    return root;
}

// In-order traversal to print events in table format
void inOrderTraversal(Event* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("| %-25s | %-10d | %-10d | %-8d |\n",
               root->title, root->start_time, root->end_time, root->priority);
        inOrderTraversal(root->right);
    }
}

// Free the BST
void freeTree(Event* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue a reminder
void enqueue(Queue* q, char* message) {
    Reminder* new_reminder = (Reminder*)malloc(sizeof(Reminder));
    strcpy(new_reminder->message, message);
    new_reminder->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = new_reminder;
        return;
    }
    q->rear->next = new_reminder;
    q->rear = new_reminder;
}

// Function to display reminders in table format
void displayReminders(Queue* q) {
    Reminder* current = q->front;
    printf("----------------------------------------------------\n");
    printf("| %-40s |\n", "Reminder Message");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        printf("| %-40s |\n", current->message);
        current = current->next;
    }
    printf("----------------------------------------------------\n");
}

// Free the queue
void freeQueue(Queue* q) {
    while (q->front != NULL) {
        Reminder* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}
