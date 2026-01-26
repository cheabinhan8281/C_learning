#include <iostream>
#include <conio.h>      // 콘솔 입출력 함수가 정의된 헤더파일, WinOS 단독 사용(MSC컴파일러만 지원)


//반복문: while, do-while, for

int main()
{
    // while 반복문: 조건식의 결과가 참인동안 반복 실행
    // 조건식의 결과에 따라 한번도 실행되지 않을 수 있음
    // 반복 조건 판단 -> 반복
    // 반복 횟수가 명확하지 않을 때 주로 사용
    /*
    while (조건식) 
    {
        반복 실행할 명령문
    }
    */

    int i = 0;
    while (i < 5) {
        printf("i = %d\n", i + 1);
        i++;
    }

    i = 0;
    while (i++ < 15) printf("=");
    printf("\n");

    i = 1;
    int total = 0;      // total 변수 선언, 0 초기화
    // 1+2+...+10
    while (i < 11) {
        total += i;
        i++;
    }printf("%d\n", total);

    // 0부터 10까지 짝수들의 합
    i = 1;
    int total2 = 0;
    while (i < 11) {
        if (i % 2 == 0) {
            total2 += i;
        } i++;
    }printf("%d\n", total2);

    i = 0;
    while (i++ < 15) printf("=");
    printf("\n");

    // 구구단
    i = 1;
    while (i < 10) {
        printf("2 x %d = %d\n", i, i * 2);
        i++;
    }

    //
    int ch = 0;
    while (ch != 'x') {
        printf("종료하려면 'x'키를 입력하세요: ");
        //_getch();
        ch = _getch();       // conio.h 헤더 파일 포함
        printf("%c\n", ch);
    }

    //1부터 100까지의 합을 구하세요
    i = 1;
    total = 0;
    while (1)       //무한 반복
    {
        total += i;
        i++;
        // 반복문 안에서 탈출조건을 체크하여 탈출
        if (i > 100) break; // i가 100보다 크다면
    } printf("%d\n", total);

    // 반복문 중첩
    int dan = 2;        // 단수 설정 변수 선언
    while (dan < 10) {
        printf("---%d단---\n", dan);
        i = 1;
        while (i < 10) {
            printf("%d x %d = %d\n", dan, i, i * dan);
            i++;
        } dan++;
    }

    i = 1;        
    while (i < 10) {
        dan = 2;
        while (dan < 10) {
            printf("%dx%d =%d\t", dan, i, i * dan);
            dan++;
        } 
        printf("\n");
        i++;
    }

    // 1~99 테이블 모양 출력
    i = 1;
    while(i<100) {
        printf("%d\t", i);
        if (i % 10 == 0) printf("\n");
        i++;
    }



    return 0;
}

