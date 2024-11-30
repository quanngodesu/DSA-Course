#include <iostream>
using namespace std;
int findMin(int arr[], int n){
	if(n == 0){
		return arr[0];
	} else {
		return min(arr[n-1], findMin(arr, n-1));
	}
}
int main(){
	int len;
	cout << "Input number of elements: ";
	cin >> len;
	int a[len];
	cout << "Input elements: ";
	for(int i = 0; i < len; i++){
		cin >> a[i];
    }
	cout << "Min = " << findMin(a, len) << endl;
}