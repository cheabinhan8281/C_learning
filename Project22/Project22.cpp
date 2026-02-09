#include <stdio.h>
/* 배열 포인터
배열을 가리키는 포인터 변수

int (*arr) [3];

# 포인터 배열
포인터 변수를 요소로 가지는 배열

int* arr [3]
*/

int main()
{
    /*
    int arr[2][3] = {
        {1,2,3},{4,5,6}
    };
    
    // 배열 포인터
    int(*arrptr)[3] = arr;
    
    // 배열의 모든 요소 출력
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arrptr[i][j]);
        }
        printf("\n");
    }
    */
    

    // 예제
    // OXX
    // XOX
    // XXO
    /*
    char arr[3][3] = {};
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                arr[i][j] = 'O';
                printf("%c", arr[i][j]);
                continue;
            }
            arr[i][j] = 'X';
            printf("%c", arr[i][j]);
        }
        printf("\n");
    
    }*/

    //4행 9열 구구단
    /*short arr[4][9];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 9; j++) {
            
            arr[i][j] = (i + 2) * (j + 1);
            printf("%-4d ", arr[i][j]);
        }
        printf("\n");

    }*/

    // 5행 5열 1~25 정수 출력
    short arr[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = i*5 + (j + 1);
            printf("%-4d ", arr[i][j]);
        }
        printf("\n");

    }
    printf("\n");
    short arr2[5][5];
    for (int i = 4; i >= 0 ; i--) {
        for (int j = 4; j >= 0; j--) {
            arr2[i][j] = i * 5 + j+1;
            printf("%-4d ", arr2[i][j]);
        }
        printf("\n");

    }
    /* 1~25 배열 할당
    int cmt = 1;
    cmt++;
    */



    return 0;
}
