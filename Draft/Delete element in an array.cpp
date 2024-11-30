#include <iostream>
using namespace std;

void deleteAtPosition(int arr[], int &n, int pos) {
    for (int i = pos; i < n-1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

int main() {
    int arr[100], n, pos;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhap arr[" << i << "]: ";
        cin >> arr[i];
    }

    while(pos > n || pos < 0){	
        cout << "Nhap vi tri can xoa: ";
        cin >> pos;
	}

    deleteAtPosition(arr, n, pos);

    cout << "Mang sau khi xoa: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
