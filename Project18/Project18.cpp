#include <stdio.h>      // 표준 입출력 관련 함수
#include <stdlib.h>     // 표준 라이브러리 관련 함수
#include <time.h>       // 시스템(컴퓨터) 시간 관련 함수

// 난수 반환 함수
//제한 범위 1~n까지 난수 생성
int make_random(int start, int end)
{
    if (start >= end)
        return 0;
    int range = end - start;
    return rand() % range + start;

}
void make_random_array(int arr[], size_t count)
{
    for (int i = 0; i < count; i++)
        arr[i] = make_random(30, 100);
}
void print_array(int arr[], size_t count)
{
    for (int i = 0; i < count; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}
void change(int* n1, int* n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;

}
// 배열 아이템 오름차순 정렬
void sort_array(int arr[], size_t count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                change(&arr[j], &arr[j + 1]);     
            }
        }
    }
}
int find_max(int arr[], size_t count)
{

    /*sort_array(arr,count);
    return arr[count-1];*/
    int max = arr[0];
    for (int i = 1; i < count; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int arr[15];

    // 난수를 생성하기 위해 반드시 난수 생성 엔진 초기화 필수
    srand(time(NULL));

    make_random_array(arr, 15);

    print_array(arr, 15);
    sort_array(arr,15);
    print_array(arr, 15);
    printf("%d\n",find_max(arr, 15));
    
    
    return 0;
}

