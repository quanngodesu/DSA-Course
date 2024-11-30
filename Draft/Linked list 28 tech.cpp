#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	char name[100];
	int age;
	float gpa;
	struct Student *next;
};
typedef struct Student student;

// Function to create a new student
student* createStudent(const char* name, int age, float gpa) {
	student* newStudent = (student*)malloc(sizeof(student));
	if (newStudent == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	strcpy(newStudent->name, name);
	newStudent->age = age;
	newStudent->gpa = gpa;
	newStudent->next = NULL;
	return newStudent;
}

// Initialize the student list (returns NULL)
student* initList() {
	return NULL;
}

// Insert student at the head of the list
void insertAtHead(student** head, student* newStudent) {
	newStudent->next = *head;
	*head = newStudent;
}

// Insert student at the end of the list
void insertAtEnd(student** head, student* newStudent) {
	if (*head == NULL) {
		*head = newStudent;
	} else {
		student* temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newStudent;
	}
}

// Insert student at a specific position
void insertAtPos(student** head, student* newStudent, int pos) {
	if (pos == 0) {
		insertAtHead(head, newStudent);
		return;
	}
	
	student* temp = *head;
	int count = 0;

	// Traverse the list until reaching the position or the end
	while (temp != NULL && count < pos - 1) {
		temp = temp->next;
		count++;
	}

	// Insert new student at the position
	if (temp != NULL) {
		newStudent->next = temp->next;
		temp->next = newStudent;
	} else {
		// If position is greater than the length, insert at the end
		insertAtEnd(head, newStudent);
	}
}

// Display the list of students
void display(student* head) {
	if (head == NULL) {
		printf("Danh sach sinh vien trong!\n");
	} else {
		printf("+------------------------+-------+---------+\n");
		printf("|         Name           |  Age  |  GPA    |\n");
		printf("+------------------------+-------+---------+\n");
		while (head != NULL) {
			printf("| %-22s | %-5d | %-7.2f |\n", head->name, head->age, head->gpa);
			head = head->next;
		}
		printf("+------------------------+-------+---------+\n");
	}
}

// Count the number of students in the list
int count(student* head) {
	int count = 0;
	student* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

// Find a student by name
student* find(student* head, const char* name) {
	student* temp = head;
	while (temp != NULL) {
		if (strcmp(temp->name, name) == 0) {  // Use strcmp to compare strings
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
student* sortByAge(student* head) {
	if (head == NULL || head->next == NULL) {
		return head;  // If list is empty or has only one student, no sorting needed
	}
	int swapped;
	student* temp;
	student* lastPtr = NULL;  // Marks the end of the sorted part of the list

	do {
		swapped = 0;
		temp = head;

		while (temp->next != lastPtr) {
			if (temp->age > temp->next->age) {
				// Swap the data of current node and next node
				char nameTemp[100];
				strcpy(nameTemp, temp->name);
				strcpy(temp->name, temp->next->name);
				strcpy(temp->next->name, nameTemp);

				int ageTemp = temp->age;
				temp->age = temp->next->age;
				temp->next->age = ageTemp;

				float gpaTemp = temp->gpa;
				temp->gpa = temp->next->gpa;
				temp->next->gpa = gpaTemp;

				swapped = 1;
			}
			temp = temp->next;
		}
		lastPtr = temp;  // Move last pointer backward after each pass
	} while (swapped);

	return head;
}
student* sortByGPA(student* head) {
	if (head == NULL || head->next == NULL) {
		return head;  // If list is empty or has only one student, no sorting needed
	}
	int swapped;
	student* temp;
	student* lastPtr = NULL;  // Marks the end of the sorted part of the list

	do {
		swapped = 0;
		temp = head;

		while (temp->next != lastPtr) {
			if (temp->gpa < temp->next->gpa) {
				// Swap the data of current node and next node
				char nameTemp[100];
				strcpy(nameTemp, temp->name);
				strcpy(temp->name, temp->next->name);
				strcpy(temp->next->name, nameTemp);

				int ageTemp = temp->age;
				temp->age = temp->next->age;
				temp->next->age = ageTemp;

				float gpaTemp = temp->gpa;
				temp->gpa = temp->next->gpa;
				temp->next->gpa = gpaTemp;

				swapped = 1;
			}
			temp = temp->next;
		}
		lastPtr = temp;  // Move last pointer backward after each pass
	} while (swapped);

	return head;
}
student* deleteStudent(student* head, int pos) {
    if (head == NULL) {
        return head;  // List is empty
    }

    student* temp = head;

    // Deleting the head node
    if (pos == 0) {
        head = temp->next;  // Change head to point to the next node
        free(temp);  // Free the old head
        return head;  // Return the new head
    }

    // Find the node before the node to be deleted
    for (int count = 0; temp != NULL && count < pos - 1; count++) {
        temp = temp->next;
    }

    // If the position is more than the number of nodes
    if (temp == NULL || temp->next == NULL) {
        return head;  // Position is invalid, return original head
    }

    // Node temp->next is the node to be deleted
    student* nextNode = temp->next->next;  // Store pointer to the next node
    free(temp->next);  // Free memory of the node to be deleted
    temp->next = nextNode;  // Unlink the deleted node from the list

    return head;  // Return the (possibly unchanged) head
}


int main() {
	int choice, age, pos;
	float gpa;
	char name[100];
	student* studentList = initList();
	student* foundStudent = NULL;

	
	do {
		printf("\nChuong trinh quan ly sinh vien: \n");
		printf("+------------------------------------------+\n");
		printf("|1. Them sinh vien o dau danh sach         |\n");
		printf("|2. Them sinh vien o cuoi danh sach        |\n");
		printf("|3. Them sinh vien o vi tri xac dinh       |\n");
		printf("|4. Dem so luong sinh vien                 |\n");
		printf("|5. Tim sinh vien theo ten                 |\n");
		printf("|6. Sap xep theo tuoi                      |\n");
		printf("|7. Sap xep theo GPA                       |\n");
		printf("|8. Xoa sinh vien                          |\n");
		printf("|9. In danh sach sinh vien                 |\n");
		printf("|10. Thoat chuong trinh                    |\n");
		printf("+------------------------------------------+\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);
		getchar();  // Consume newline character after scanf

		switch (choice) {
			case 1:
				printf("Nhap ten sinh vien: ");
				fgets(name, sizeof(name), stdin);
				name[strlen(name) - 1] = '\0';  // Remove newline character
				printf("Nhap tuoi: ");
				scanf("%d", &age);
				printf("Nhap GPA: ");
				scanf("%f", &gpa);
				insertAtHead(&studentList, createStudent(name, age, gpa));
				break;
			case 2:
				printf("Nhap ten sinh vien: ");
				fgets(name, sizeof(name), stdin);
				name[strlen(name) - 1] = '\0';  // Remove newline character
				printf("Nhap tuoi: ");
				scanf("%d", &age);
				printf("Nhap GPA: ");
				scanf("%f", &gpa);
				insertAtEnd(&studentList, createStudent(name, age, gpa));
				break;
			case 3:
				printf("Nhap ten sinh vien: ");
				fgets(name, sizeof(name), stdin);
				name[strlen(name) - 1] = '\0';  // Remove newline character
				printf("Nhap tuoi: ");
				scanf("%d", &age);
				printf("Nhap GPA: ");
				scanf("%f", &gpa);
				printf("Nhap vi tri: ");
				scanf("%d", &pos);
				insertAtPos(&studentList, createStudent(name, age, gpa), pos);
				break;
			case 4:
				printf("So luong sinh vien: %d\n", count(studentList));
				break;
			case 5:
				printf("Nhap ten sinh vien can tim: ");
				fgets(name, sizeof(name), stdin);
				name[strlen(name) - 1] = '\0';  // Remove newline character
				foundStudent = find(studentList, name);
				if (foundStudent != NULL) {
					printf("Sinh vien tim thay: %-22s", foundStudent->name);
				} else {
					printf("Khong tim thay sinh vien!\n");
				}
				break;
			case 6:
				studentList = sortByAge(studentList);
				printf("Danh sach da duoc sap xep theo tuoi!\n");
				break;
			case 7:
				studentList = sortByGPA(studentList);
				printf("Danh sach da duoc sap xep theo GPA!\n");
				break;
			case 8:
				printf("Nhap vi tri sinh vien muon xoa: ");
				int pos;
				scanf("%d", &pos);
				studentList = deleteStudent(studentList, pos);
				break;
			case 9:
				display(studentList);
				break;
			case 10:
				printf("Thoat chuong trinh!\n");
				break;
			default:
				printf("Lua chon khong hop le!\n");
		}
	} while (choice != 10);

	return 0;
}
