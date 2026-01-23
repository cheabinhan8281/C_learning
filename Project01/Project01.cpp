//C언어
//함수들로 코드를 구성하는 언어
//코드의 실행은 main 함수에서 시작해서 끝남
//문장 끝 ; 마무리

#include<stdio.h>

//entry point(시작점)
int main()
{
    //출력함수
    printf("Hello World\n");

    //변수
    //byte: 데이터를 처리하는 최소단위
    //bit: 0,1을 저장할 수 있는 데이터 표현의 최소단위
    //1byte = 8bit
    //정수 = char(1byte), short(2), int(4), long(W:4, M:8), long long(8)
    //실수 = float, double, long double

    //1bit: 0 또는 1 두가지 데이터 표현 (2^1)
    //2bit: 00, 01, 10, 11 네가지 데이터 표현 (2^2)
    //8bit: 256가지 데이터 표현 (2^8)
    //n이라는 이름의 1byte(8bit, 256) 정수형 변수 출력
    char n; //-128~0~127까지 저장
    n = 127; //n이라는 변수에 정수 127 대입 -> 127 출력
    printf("%d\n", n);

    n = 128; //n이라는 변수에 정수 128 대입 -> 돌아가서 -128 출력
    printf("%d\n", n);

    //변수: 데이터를 일시적으로 저장하는 공간 -> RAM
    //컴퓨터 구성요소: CPU 중앙처리장치 / RAM 휘발저장장치 / Disk 영구저장장치

    return 0;
}