#include <stdio.h>
int main(){
	int N;
	printf("Nhap N: ");
	scanf("%d", &N);
	int a[N];
	printf("Nhap mang so nguyen: ");
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}
	printf("Cac so chan trong mang la: ");
	for(int i = 0; i < N; i++){
		if(a[i] % 2 == 0) printf("%d ", a[i]);
	}
	return 0;
}