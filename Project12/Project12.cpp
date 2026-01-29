#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    // 배열 arr 정의
    // 배열의 길이: 5, (n)
    // 배열의 타입: int

    int arr[5];
    arr[0] = 100;           // 배열의 첫번째 자리에 값100 대입
    // 인덱스의 범위: 0 ~ n-1

    //for (int i = 0; i < 5; i++) {   // 0~4
    //    arr[i] = i + 1;
    //    printf("%d\t", arr[i]);     // arr[0], arr[1], ... arr[4]
    //}
    
    ////float형 배열
    float nums[10];
    //nums[0] = 0;
    //for (int j = 0; j < 10; j++) {
    //    nums[j] = (j+1)*5.F;
    //    printf("%.1f\t", nums[j]);
    //}

    // 배열의 초기화
    char sz[3] = { 65,66,67 };
    short my_nums[] = {1,2,3,4,5,6,7};      // 7칸짜리 short형 배열
    long bigs[5] = { 0 };                   // 5칸

    // sz배열의 모든 요소에 정수 값을 입력받아 대입
    /*for (int i = 0; i < 3; i++) {
        printf("입력: ");
        scanf("%hhd", &sz[i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("출력: %hhd\n", sz[i]);
    }*/

    // 배열의 메모리 할당 크기
    //printf("int형의 크기: %llubytes\n", sizeof(int));
    //printf("배열 arr의 크기: %llubytes\n", sizeof(arr));    
    //printf("배열 nums의 크기: %llubytes\n", sizeof(nums));
    //printf("배열 sz의 크기: %llubytes\n", sizeof(sz));
    //printf("배열 my_nums의 크기: %llubytes\n", sizeof(my_nums));
    //printf("배열 bigs의 크기: %llubytes\n", sizeof(bigs));

    //arr[0] = 88;
    //arr[1] = 95;
    //arr[2] = 100;
    //arr[3] = 70;
    //arr[4] = 65;

    //for (int i = 0; i < 5; i++)
    //{
    //    for (int j = 0; j < 4; j++)
    //    {
    //        if (arr[j] > arr[j + 1])
    //        {
    //            // 두 값 서로 교환
    //            int tmp = arr[j];
    //            arr[j] = arr[j + 1];
    //            arr[j + 1] = tmp;
    //        }
    //            
    //    }
    //}
    //for (int i = 0; i < 5; i++)
    //{
    //    printf("%d\t", arr[i]);
    //}

    // arr 배열의 값들의 합과 평균
    /*int total = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] =", i);
        scanf("%d", &arr[i]);
        total += arr[i];
    }
    float average = total / (sizeof(arr) / sizeof(int));
    printf("값: %d, 평균: %.2f", total, average);*/


    // int(4byte) *5 = arr[5] (20byte)
    // 배열 크기 = 배열 타입의 크기 * 배열의 길이
    // 정적배열: 배열 크기 고정(<-> 동적배열)

    //이 배열의 아이템 개수 출력
    short numbers[] = { 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9 };
    short length = sizeof(numbers) / sizeof(short);
    printf("numbers의 아이템 개수: %hd\n", length);
    // 마지막 배열에 100 대입 후 마지막 값 출력
    numbers[length-1] = 100;
    printf("numbers[%hd] = %hd\n\n", length-1, numbers[length-1]);

    //for 문을 이용해 numbers 배열에 1~ 개수까지의 수를 순서대로 대입
    for (int i = 0; i < length; i++)
    {
        numbers[i] = i + 1;
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }



    return 0;
}

