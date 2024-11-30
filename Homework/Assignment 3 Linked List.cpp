#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int ID;
    char name[100];
    int year;
    char nxb[100];
    char topic[100];
    struct Book* next;
};

typedef struct Book Book;

// Ham tao mot cuon sach moi
Book* createBook(int ID, const char* name, int year, const char* nxb, const char* topic) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->ID = ID;
    strcpy(newBook->name, name);
    newBook->year = year;
    strcpy(newBook->nxb, nxb);
    strcpy(newBook->topic, topic);
    newBook->next = NULL;
    return newBook;
}

// Khoi tao danh sach rong
Book* initList() {
    return NULL;
}

// Chen sach vao dau danh sach
void insertAtHead(Book** head, Book* newBook) {
    newBook->next = *head;
    *head = newBook;
}

// Chen sach vao cuoi danh sach
void insertAtEnd(Book** head, Book* newBook) {
    if (*head == NULL) {
        *head = newBook;
    } else {
        Book* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

// Chen sach vao vi tri bat ky
void insertAtPosition(Book** head, Book* newBook, int pos) {
    if (*head == NULL) {
        return;
    } else {
        Book* temp = *head;
        int count = 1;
        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }
        if (temp != NULL) {
            newBook->next = temp->next;
            temp->next = newBook;
        }
    }
}

// Tim sach theo ten
Book* findBook(Book* head, char* name) {
    Book* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Dem so luong sach trong danh sach
int countBooks(Book* head) {
    Book* temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

// Ham in danh sach sach theo dinh dang bang
void displayBooks(Book* head) {
    if (head == NULL) {
        printf("Danh sach trong!\n");
    } else {
        Book* temp = head;
        printf("+----+----------------------------+------+--------------------+--------------------+\n");
        printf("| ID |        Book's Name         | Year |      Publisher     |       Topic        |\n");
        printf("+----+----------------------------+------+--------------------+--------------------+\n");
        while (temp != NULL) {
            printf("| %-2d | %-26s | %-4d | %-18s | %-18s |\n", temp->ID, temp->name, temp->year, temp->nxb, temp->topic);
            temp = temp->next;
        }
        printf("+----+----------------------------+------+--------------------+--------------------+\n");
    }
}

int main() {
    // Khoi tao danh sach sach
    Book* bookList = initList();

    // Tao vai cuon sach
    Book* book1 = createBook(1, "C Programming", 2020, "ABC Publishing", "Programming");
    Book* book2 = createBook(2, "Data Structures", 2019, "XYZ Publishing", "Education");
    Book* book3 = createBook(3, "Algorithms", 2021, "DEF Publishing", "Computer Science");
    Book* book4 = createBook(4, "Android for Beginners", 2024, "MIT Publishing", "Programming");
    Book* book5 = createBook(5, "Tan gai dai cuong", 2005, "HUST Publishing", "Psycology");

    // Chen sach vao danh sach
    insertAtHead(&bookList, book1);
    insertAtEnd(&bookList, book2);
    insertAtPosition(&bookList, book3, 2);
    insertAtEnd(&bookList, book4);
    insertAtPosition(&bookList, book5, 4);

    // In danh sach sach
    printf("Danh sach sach:\n");
    displayBooks(bookList);

    // Tim sach theo ten
    char bookName[100];
    printf("Nhap sach ban muon tim: ");
    fgets(bookName, 100, stdin);
    bookName[strcspn(bookName, "\n")] = '\0';
    
    Book* foundBook = findBook(bookList, bookName);
    if (foundBook != NULL) {
        printf("Tim thay cuon sach: %s\n", foundBook->name);
    } else {
        printf("Khong tim thay cuon sach co ten: %s\n", bookName);
    }

    // Dem so luong sach trong danh sach
    printf("So luong sach trong danh sach: %d\n", countBooks(bookList));

    return 0;
}
