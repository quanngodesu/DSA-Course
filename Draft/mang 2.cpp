#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    
    int a[n];
    printf("Nhap mang: \n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    // Step 1: Find the range of input values
    int minValue = INT_MAX, maxValue = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] < minValue) minValue = a[i];
        if (a[i] > maxValue) maxValue = a[i];
    }
    
    // Step 2: Initialize a frequency array
    int range = maxValue - minValue + 1;
    int b[range];
    for (int i = 0; i < range; i++) {
        b[i] = 0;
    }
    
    // Step 3: Count the frequency of each element
    for (int i = 0; i < n; i++) {
        b[a[i] - minValue]++;
    }

    // Step 4: Find the element with the maximum frequency
    int maxFreq = 0;
    int mostFreqElement = a[0];
    
    for (int i = 0; i < n; i++) {
        if (b[a[i] - minValue] > maxFreq) {
            maxFreq = b[a[i] - minValue];
            mostFreqElement = a[i];
        }
    }

    printf("Phan tu xuat hien nhieu nhat la %d voi tan suat xuat hien la %d lan\n", mostFreqElement, maxFreq);
    
    return 0;
}
