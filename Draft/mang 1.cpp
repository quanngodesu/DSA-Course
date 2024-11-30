#include <stdio.h>
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int a[n];
	printf("Nhap mang: \n");
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int maxCount = 0;
	int maxElement = a[0];
	for(int i = 0; i < n; i++){
		int count = 0; 
		for(int j = 0; j < n; j++){
			if(a[i] == a[j]){
			count ++;
		    }
		}
		if(count > maxCount){
		maxCount = count;
		maxElement = a[i];
	    }	
    }
    printf("Phan tu xuat hien nhieu nhat la %d xuat hien %d lan", maxElement, maxCount);
	return 0;
}