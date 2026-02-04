#include <stdio.h>
#include <iostream>

// 배열을 매개변수로 받는 함수를 정의할 때 반드시 배열의 주소와 배열 아이템 개수 같이 제공해야함
void print_array(int arr[], size_t count)       // 배열 들어오는 자리임, int arr[] == int* arr
{
    printf("arr의 주소: %p\n", arr);
    for (int i = 0; i < count; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void print_value(int n)
{
    printf("%d\n", n);
}



int main()
{
    int a = 10;
    int b = 5;
    int c = 3;
    print_value(a);
    print_value(b);
    



    int n = 5;
    printf("n의 주소: %p\n", &n);

    int arr[100];
    int arr2[200];

    printf("arr의 주소: %p\n", arr);               // arr == arr[0]의 주소
    printf("arr[0]의 주소: %p\n", &arr[0]);
    printf("arr+1의 주소: %p\n", arr + 1);         // arr + 1 == arr[1]의 주소
    printf("arr[1]의 주소: %p\n", &arr[1]);
    printf("arr+2의 주소: %p\n", arr + 2);
    printf("arr[2]의 주소: %p\n", &arr[2]);

    int *p = arr;       // 포인터 변수: 8바이트
    char* sz;

    for (int i = 0; i < 100; i++)
    {
        arr[i] = i + 1;
    }
    for (int i = 0; i < 200; i++)
    {
        arr2[i] = i + 1;
    }

    printf("arr[5] = %d\n", arr[5]);
    printf("p[5] = %d\n", p[5]);

    // 배열을 전달하는 함수 호출
    print_array(arr,100);
    printf("\n\n\n");
    print_array(arr2,200);


    return 0;
}
