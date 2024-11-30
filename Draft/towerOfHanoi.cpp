
#include <stdio.h>
void towerOfHanoi(int n, char from_rod, char to_rod, char temp_rod, int *count) {
    if (n == 1) {
        printf("Move disk 1 from rod %c --> rod %c\n", from_rod, to_rod);
        (*count)++;
        return;
    }
    towerOfHanoi(n - 1, from_rod, temp_rod, to_rod, count);
    printf("Move disk %d from rod %c --> rod %c\n", n, from_rod, to_rod);
    (*count)++;
    towerOfHanoi(n - 1, temp_rod, to_rod, from_rod, count);
}

void towerOfHanoi2(int n, char A, char C, char B){
	static int count = 0;
	if(n == 1){
		printf("Move disk 1 from %c --> %c\n", A, C);
		count ++;
		return;
	}
	towerOfHanoi2(n-1, A, B, C);
	printf("Move disk %d from %c --> %c\n", n, A, C);
	count ++;
	towerOfHanoi2(n-1, B, C, A);
	if(n == 1){
		printf("It takes at least %d steps to do.", count);
	}
	
}
int main() {
    int n, steps = 0;
    printf("Input the number of disks: ");
    scanf("%d", &n);
//    towerOfHanoi(n, 'A', 'C', 'B', &steps);
//    printf("It takes at least %d steps to do.\n", steps);
    
    towerOfHanoi2(n, 'A', 'C', 'B');
    return 0;
}
