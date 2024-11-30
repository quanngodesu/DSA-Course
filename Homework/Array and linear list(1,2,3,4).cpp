#include <stdio.h>
#include <stdlib.h>

void insert(int arr[], int *n, int element, int position) {
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*n)++;
}

void Delete(int arr[], int *n, int position) {
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void merge(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        result[k++] = arr1[i++];
    }
    while (j < n2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang a: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));  
    
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    
    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    int element, position, choice, m;
    do{
    printf("\n\n1. Insert\n");
    printf("2. Delete\n");
    printf("3. Merge\n");
    printf("4. 2D Array using pointers\n");
    printf("0. Exit\n");
    printf("\nNhap lua chon cua ban: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nInsert: ");
            printf("\nNhap gia tri va vi tri cua phan tu ban muon chen: ");
            scanf("%d%d", &element, &position);
            insert(a, &n, element, position);
            printf("Mang luc sau: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            break;

        case 2:
            printf("\nDelete:");
            printf("\nNhap vi tri cua phan tu ban muon xoa: ");
            scanf("%d", &position);
            Delete(a, &n, position);
            printf("Mang luc sau: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            break;

        case 3:
            printf("\nMerge:");
            printf("\nNhap so luong phan tu cua mang b: ");
            scanf("%d", &m);

            int *b = (int *)malloc(m * sizeof(int));  
            for (int i = 0; i < m; i++) {
                printf("Nhap b[%d]: ", i);
                scanf("%d", &b[i]);
            }

            int *result = (int *)malloc((n + m) * sizeof(int)); 
            merge(a, n, b, m, result);
            
            printf("Mang sau khi merge: ");
            for (int i = 0; i < n + m; i++) {
                printf("%d ", result[i]);
            }
            
            free(b);      
            free(result);  
            break;

        case 4:
            printf("Nhap so hang va cot: ");
            int row, col;
            scanf("%d%d", &row, &col);

            int **arr = (int **)malloc(row * sizeof(int *)); 
            for (int i = 0; i < row; i++) {
                arr[i] = (int *)malloc(col * sizeof(int)); 
            }

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    printf("a[%d][%d] = ", i, j);
                    scanf("%d", &arr[i][j]);
                }
            }

            printf("Mang 2 chieu: \n");
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    printf("%d  ", arr[i][j]);
                }
                printf("\n");
            }

            for (int i = 0; i < row; i++) {
                free(arr[i]);
            }
            free(arr);
            break;

        default:
            break;
       }
    } while (choice != 0);
    

    free(a);  
    return 0;
}
