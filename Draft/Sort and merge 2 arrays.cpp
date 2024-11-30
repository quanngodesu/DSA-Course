#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            result[k++] = arr1[i++];
        else
            result[k++] = arr2[j++];
    }

    while (i < n1)
        result[k++] = arr1[i++];

    while (j < n2)
        result[k++] = arr2[j++];
}

int main() {
    int arr1[100], arr2[100], result[200], n1, n2;

    cout << "Nhap so luong phan tu arr1[]: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> arr1[i];
    }

    cout << "Nhap so luong phan tu arr2[]: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> arr2[i];
    }

    mergeArrays(arr1, n1, arr2, n2, result);

    cout << "Mang sau khi gop: ";
    for (int i = 0; i < n1 + n2; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
