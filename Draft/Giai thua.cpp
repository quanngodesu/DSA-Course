#include <stdio.h>
int giaiThua(int n){
	if(n <= 1){
		return 1;
	} else {
		return n*giaiThua(n-1);
	}
}
int fibo(int n){
	if(n <= 1){
		return 1;
	} else {
		return fibo(n-1) + fibo(n-2);
	}
}
int giaiThua1(int n){
	if(n<=1){
		return 1;
	}
}
int main(){
	int n;
	printf("Input n: ");
	scanf("%d", &n);
	printf("Giai thua = %d\n", giaiThua(n));
	printf("Fibo = %d", fibo(n));
}