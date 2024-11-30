#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Gioi han kich thuoc cua hang doi

// Cau truc cho hang doi
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Ham khoi tao hang doi
void initQueue(Queue *q) {
    q->front = -1;  // Vi tri dau hang doi
    q->rear = -1;   // Vi tri cuoi hang doi
}

// Ham kiem tra xem hang doi co rong khong
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Ham kiem tra xem hang doi co day khong
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Ham them phan tu vao hang doi
void enqueue(Queue *q, int value) {
    if (!isFull(q)) {
        if (q->front == -1) {
            q->front = 0;  // Neu hang doi rong
        }
        q->items[++q->rear] = value;
    } else {
        printf("Hang doi day! Khong the them phan tu.\n");
    }
}

// Ham xoa phan tu tu hang doi
int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        int item = q->items[q->front];
        if (q->front >= q->rear) {
            // Neu chi con 1 phan tu
            q->front = q->rear = -1;  // Reset lai hang doi
        } else {
            q->front++;
        }
        return item;
    } else {
        printf("Hang doi rong! Khong the xoa phan tu.\n");
        return -1; // Tra ve -1 neu hang doi rong
    }
}

// Ham lay phan tu o dau hang doi
int front(Queue *q) {
    if (!isEmpty(q)) {
        return q->items[q->front];
    } else {
        printf("Hang doi rong! Khong the lay phan tu.\n");
        return -1; // Tra ve -1 neu hang doi rong
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, value;

    do {
        printf("\n1. Them phan tu vao hang doi\n");
        printf("2. Xoa phan tu khoi hang doi\n");
        printf("3. Lay phan tu o dau hang doi\n");
        printf("4. Kiem tra hang doi co rong khong\n");
        printf("5. Kiem tra hang doi co day khong\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Da xoa phan tu: %d\n", value);
                }
                break;
            case 3:
                value = front(&q);
                if (value != -1) {
                    printf("Phan tu o dau hang doi: %d\n", value);
                }
                break;
            case 4:
                if (isEmpty(&q)) {
                    printf("Hang doi rong.\n");
                } else {
                    printf("Hang doi khong rong.\n");
                }
                break;
            case 5:
                if (isFull(&q)) {
                    printf("Hang doi day.\n");
                } else {
                    printf("Hang doi khong day.\n");
                }
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}
