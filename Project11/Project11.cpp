
#include <iostream>

int main()
{
    //for 반복문
    /*
    for (초기식:조건식:증감식)
    {
        반복실행할 명령문
    }
    */

    /*
    int i = 0;
    while (i < 10) {
        printf("i=%d\n", i);
        i++;
    }
    */

    /*
    for (int i = 0 ; i < 10 ; i++) 
    {
        printf("i=%d\n", i);
    }
    */

    // for (반복진입하며 처음에 무조건 한번만 실행할 명령문;
    //      처음부터 매 반복시 실행될 명령문, 결과가 0이면 반복 종료;
    //      1회 반복 이후부터 매 반복시 실행될 명령문); 

    //for (int i = 0; i < 5; printf("%d\n", i++));

    //
    for (int i = 2; i <= 10; i += 2) {
        printf("%d\t", i);
    }

    
    for (char ch = 'z'; ch >= 'a'; ch--) {
        printf("%c", ch-32);
    }printf("\n");
    
    for (int i = 0; ; i++) {
        if (i >= 10) break;     // 현재 반복문 즉시 탈출
        printf("%d", i);
    }


    return 0;

}

