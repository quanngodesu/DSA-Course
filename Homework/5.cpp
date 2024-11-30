#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Gioi han kich thuoc cua stack

// Cau truc cho stack
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Ham khoi tao stack
void initStack(Stack *s) {
    s->top = -1;  // Stack rong
}

// Ham kiem tra xem stack co rong khong
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Ham kiem tra xem stack co day khong
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Ham them phan tu vao stack
void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->items[++s->top] = value;
    } else {
        printf("Stack day! Khong the them phan tu.\n");
    }
}

// Ham lay phan tu tu stack
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack rong! Khong the lay phan tu.\n");
        return -1; // Tra ve -1 neu stack rong
    }
}

// Ham dao nguoc day so
void reverseArray(int arr[], int n) {
    Stack s;
    initStack(&s);

    // Day tat ca cac phan tu vao stack
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }

    // Lay cac phan tu tu stack va dua vao mang
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua day: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));  // Cap phat bo nho cho mang
    printf("Nhap cac phan tu cua day:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // Dao nguoc day so
    reverseArray(arr, n);

    // In ra day so da dao nguoc
    printf("Day so da dao nguoc:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);  // Giai phong bo nho
    return 0;
}
