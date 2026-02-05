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

/*순차 탐색 알고리즘*/
int find_value(int arr[], size_t count, int value)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == value)
        {
            printf("%d 번 만에 찾음\n", i + 1);
        }
    } 
    return -1;
}

/*이진 탐색 Binary Search*/
int Bsearch(int arr[], size_t count, int value)
{
    // 3개의 인덱싱 변수 준비 (start, middle, end)
    int start = 0;
    int end = count - 1;
    int mid;
    int i = 1;
    while (start <= end)
    {
        mid = (start + end) / 2;        // 현재 상태의 가운데 인덱스
        if (value == arr[mid])
        {
            printf("%d 번 만에 찾음\n", i);
            return mid;
        }
        // 인덱스 범위 재조정
        if (value > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
        i++;
    }
    return -1;
}

/*
학생의 중간고사 점수가 배열로 주어졌을 때 총점과 평균을 반환하는 함수
여러개의 배열 반환할때, return 변수1, 포인터 변수2,3...n
*/
float total_avg(float arr[], size_t count, float* ptot)
{
    float tot = 0.F;
    for (int i = 0; i < count; i++)
        tot += arr[i];
    float avg = tot / count;
    *ptot = tot;

    return avg;
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

    // 정렬을 하는 이유: 효율적 탐색
    const int COUNT = 10000;
    int arr2[COUNT];
    for (int i = 0; i < COUNT; i++)
        arr2[i] = i + 1;

    int result = find_value(arr2, COUNT, 54);
    printf("찾은 인덱스: %d\n", result);
    result = Bsearch(arr2, COUNT, 54);
    printf("찾은 인덱스: %d\n", result);

    float tot, avg;
    float score[] = { 100.F,99.F,88.F };
    avg = total_avg(score, 3, &tot);
    printf("avg = %.2f\n", avg);
    printf("tot = %.2f\n", tot);
    printf("총점 = %.2f, 평균: %.2f\n", tot, avg);


    return 0;
}

