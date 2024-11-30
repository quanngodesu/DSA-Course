#include <stdio.h>
int main(){
	float d;
	int t;
	float price = 0;
	printf("Nhap khoang cach: ");
	scanf("%f", &d);
	printf("Nhap thoi gian cho(phut): ");
	scanf("%d", &t);

	if(d <= 2){
		price += d*5;
		d -= 2;
	} else {
		price = 2 * 5;
		price += (d-2)*1.5;
	}
	
	if(t <= 30){
		price += 3;
	} else {
		price += 3;
		price += ((t-30)/10)*0.5;
	}
	
	printf("Price: %.2f", price);
	return 0;

}