#include <stdio.h>
#include <math.h>

int main(){
	float a, b, c;
	float delta, x1, x2;
	printf("Nhap a, b, c: ");
	scanf("%f%f%f", &a, &b, &c);
	if(a==0){
		if(b==0){
			if(c==0){
				printf("Vo so nghiem");
			} else {
				printf("Vo nghiem");
			}
		} else {
			printf("1 nghiem: x = %f", -c/b);
		}
	} else {
		delta = b*b - 4*a*c;
		if(delta > 0){
			x1 = (-b + sqrt(delta))/(2*a);
			x2 = (-b - sqrt(delta))/(2*a);
			printf("2 nghiem phan biet x1, x2: \n");
			printf("x1 = %f\nx2 = %f", x1, x2);
		} else if(delta == 0){
			printf("Nghiem kep: x = %f", -b/(2*a));
		} else {
			printf("Vo nghiem");
		}
	}
}