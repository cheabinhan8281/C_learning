#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// 전역변수(Global Variable)
int g_num = 0;

char* hello()
{
    static char sz[] = "Hello World";       // static(정적변수)
    return sz;

    static int i = 0;
    i++;
}

int calc(int n1, int n2)
{
    int n3 = n1 + n2;
    return n3;
}

void dummy()
{
    char arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = 'A';
    }
}

// void: 없다
// void*: 모르긴 하지만 어쨌든 주소!

//src 문자열을 전달하여 src 내용을 모두 대문자로 변환하고 반환하는 함수
char* to_upper_case(const char* str)
{
    int bytes = strlen(str) + 1;    // sizeof -> 8바이트(포인터); strlen -> 문자열 길이(포인터가 가리키는 문자열 길이)
    // malloc(할당받을 메모리 크기를 바이트 단위로 지정)
    char* new_sz = (char*)malloc(bytes);      // heap 공간에 bytes만큼 할당 요청, 실패 시 NULL 반환
    if (!new_sz)    // new_sz == NULL(0)
        return NULL;
    for (int i = 0; i < bytes; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            new_sz[i] = str[i] - 32;
        else
            new_sz[i] = str[i];
    }
    return new_sz;
}

// copy_array
// int형 배열
// 배열의 길이
// 반환값: 힙에 할당받은 복사된 (int형) 배열의 주소
int* copy_array(int arr[], size_t len_arr)
{
    size_t bytes = sizeof(int) * len_arr;
    int* new_arr = (int*)malloc(bytes);
    if (!new_arr)
        return NULL;
    for (int i = 0; i < len_arr; i++) {
        new_arr[i] = arr[i];
    }
    return new_arr;
}

void print_array(int arr[], size_t len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}



int main()
{
    char src[] = "hello world";

    

    char* str = to_upper_case(src);
    printf("%s\n", str);

    if (str != NULL)        // NULL일 때 free하면 에러
    {
        free(str);
        str = NULL;         // 주소 표기 시 0 -> NULL
    }

    int arr[] = { 10,20,30,40,50 };
    int* parr = copy_array(arr, 5);
    if (parr)
    {
        print_array(parr, 5);
        free(parr);
        parr = NULL;
    }


    return 0;;
}
