#include <stdio.h>
#include <string.h>
int sum(int arr[], int n){
	if(n==0){
		return 0;
	} else {
		return arr[n-1] + sum(arr, n-1);
	}
}
void reverse(char *str)
{
   if (*str)
   {
       reverse(str+1);
       printf("%c", *str);
   }
}
//void reverse2(char str)
int main(){
	int s[5] = {1,2,3,4,5};
	printf("%d\n", sum(s, 5));
	char a[100];
	printf("Nhap chuoi a: ");
	scanf("%s", a);
	reverse(a);
}