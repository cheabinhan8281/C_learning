#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void print_array(int* arr, size_t len)
{
    printf("arr의 크기: %llu bytes\n", sizeof(arr));
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}

int copy_array(int arr[], size_t len, int** ppDest)
{
    // int* p = *ppDest;
    size_t bytes = sizeof(int) * len;
    int* pArr = (int*)malloc(bytes);
    if (!pArr) return NULL;

    memcpy(pArr, arr, bytes);       // arr -> pArr bytes만큼 복사
    *ppDest = pArr;                 // main.p = pArr;
    
    return bytes/sizeof(int);
}

void swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    
}


int main()
{
    int n = 10;         // n; 사이즈: 4바이트, 값: 10
    int* p = &n;        // p; 사이즈: 8바이트, 값: n의 주소
    int arr[3] = { 1,2,3 };
    p = arr;            // p; 사이즈: 8바이트, 값: arr

    // 1차원 포인터 변수: 일반 변수의 주소 + 1차원 배열의 주소 저장
    // 2차원 포인터 변수: 1차원 포인터 변수의 주소 저장

    printf("arr의 크기: %llu bytes\n", sizeof(arr));
    printf("p의 크기: %llu bytes\n", sizeof(p));
    print_array(arr, 3);

    int count = copy_array(arr, 3, &p);
    print_array(p, count);
    //printf("pArr의 크기: %llu bytes\n", sizeof(pArr));

    if (p)
    {
        free(p);
        p = NULL;
    }

    // 2차원 포인터 변수
    int** pp = &p;
    int n1 = 10;
    int n2 = 5;
    swap(&n1, &n2);

    return 0;
}

