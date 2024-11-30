#include <iostream>
using namespace std;

void insertAtPosition(int arr[], int &n, int value, int pos) {
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
}

int main() {
    int arr[100], n, value, pos;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhap arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Nhap gia tri can chen: ";
    cin >> value;

    cout << "Nhap vi tri chen: ";
    cin >> pos;

    insertAtPosition(arr, n, value, pos);

    cout << "Mang sau khi chen: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
