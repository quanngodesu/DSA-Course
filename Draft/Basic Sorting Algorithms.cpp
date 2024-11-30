#include <stdio.h>
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        swap(&a[i], &a[min_index]);
    }
}

// Insertion Sort
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

// Display array
void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Display menu
void displayMenu() {
    printf("\nBasic Sorting Algorithms\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Reset Array\n");
    printf("5. Exit\n");
}

int main() {
    int original_arr[] = {2, 1, 4, 3, 7, 8, 6, 5, 10, -2, 9, 11, -3, -4, -1, 12, 0};
    int n = sizeof(original_arr) / sizeof(original_arr[0]);
    int a[n];
    int choice;

    for (int i = 0; i < n; i++) {
        a[i] = original_arr[i];
    }

    do {
        displayMenu();
        printf("Input your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                selectionSort(a, n);
                printf("Sorted Array (Selection Sort): ");
                display(a, n);
                break;

            case 2:
                insertionSort(a, n);
                printf("Sorted Array (Insertion Sort): ");
                display(a, n);
                break;

            case 3:
                bubbleSort(a, n);
                printf("Sorted Array (Bubble Sort): ");
                display(a, n);
                break;

            case 4:
                for (int i = 0; i < n; i++) {
                    a[i] = original_arr[i];
                }
                printf("Array has been reset to original: ");
                display(a, n);
                break;

            case 5:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while (choice != 5); 

    return 0;
}
