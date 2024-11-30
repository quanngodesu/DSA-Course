#include <stdio.h>
void bubbleSort(int arr[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
	int arr[] = {1,3,2,7,6,4,5,9,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    display(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array: ");
    display(arr, n);
}