#include <stdio.h>
#include <stdlib.h>
struct dynamicArray{
    int n; // lưu số phần tử của mảng
    int* arr;
};

int main()
{
    // khởi tạo danh sách tuyến tính rỗng
    struct dynamicArray da;
    da.n = 0;
    da.arr = NULL;
    // thêm một phần tử có giá trị x vào danh sách: 
    int x = 3;
    da.n++;
    if(da.arr == NULL)
        da.arr = (int*)malloc(sizeof(int));
    else 
        da.arr = (int*)realloc(da.arr, da.n*sizeof(int));
    da.arr[da.n-1] = x; 
    // bớt một phần tử ở cuối danh sách
    if(da.arr != NULL)
    {
        da.n--;
        da.arr = (int*)realloc(da.arr, da.n*sizeof(int));
    }
    
    const int N = 5;
    const int M = 256;
    int a1[N] = {0};             //{0, 0, 0, 0, 0}
    int a2[N] = {3, 2, 5};       //{3, 2, 5, 0, 0}
    int a3[N] = {3, 2, 5, 1, 4};
    int max = -1;
    int maxid = -1;
    int h[M] = {0};
    for(int i = 0; i < N; i++)
        h[a3[i]]++;



    printf("%p\n", a3);          // tên của mảng là địa chỉ của phần tử đầu tiên của mảng
    int a4[N][N] = {{1, 2, 3, 4, 5}, 
                    {0, 1, 4, 5, 8}, 
                    {3, 2, 4, 5, 1}, 
                    {1, 4, 5, 7, 4}, 
                    {0, 1, 3, 4, 6}}; 
    return 0;
}