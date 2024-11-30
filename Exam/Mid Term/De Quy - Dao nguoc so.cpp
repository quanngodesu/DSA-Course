#include <iostream>
using namespace std;

int reverseNumber(int n, int reversed = 0) {
    // Điều kiện dừng khi số n bằng 0
    if (n == 0) 
        return reversed;
    // Gọi đệ quy để xử lý phần còn lại của số
    return reverseNumber(n / 10, reversed * 10 + n % 10);
}

int main() {
    int n;
    cout << "Nhap mot so nguyen duong: ";
    cin >> n;

    // Kiểm tra xem n có phải là số nguyên dương không
    if (n > 0) {
        int reversedNumber = reverseNumber(n);
        cout << "So dao nguoc: " << reversedNumber << endl;
    } else {
        cout << "Vui long nhap so nguyen duong." << endl;
    }

    return 0;
}
