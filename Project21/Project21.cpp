#include <stdio.h>
int main()
{
    short sarr[2][3][4];
    int iarr[2][3][4];
    printf("sarr 크기: %d\n", sizeof(sarr));
    printf("iarr 크기: %d\n", sizeof(iarr));

    // 3차원 배열 선언과 동시 초기화
    int arr[2][3][4] = {
        {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12}
        },
        {
            {21,22,23,24},
            {25,26,27,28},
            {29,30,31,32}

        }
    };
    printf("\n");
    // 3차원 배열 값 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[0][i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[1][i][j]);
        }
        printf("\n");
    }

    return 0;
}

