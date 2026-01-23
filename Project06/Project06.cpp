#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	//조건식
	//비교연산자 또는 논리연산자가 사용된 식
	//0: 거짓, 1: 참
	
	/*
	if 조건식1 {
		조건식1이 참일 때 실행될 명령문
	} else if 조건식2 {
		조건식2가 참일 때 실행될 명령문
	} else {
		위 모든 조건식이 거짓일 때 실행될 명령문
	}
	*/

	/*int num;
	printf("정수를 입력하세요 >>> ");
	scanf("%d", &num);
	if (num % 2) {
		printf("홀수");
	}
	else {
		printf("짝수");
	}*/

	/* 두 수 입력받아서 더 큰 수 출력
	int num1, num2;
	printf("정수 2개를 입력하세요 >>>");
	scanf("%d %d", &num1, &num2);
	if (num1 < num2) {
		printf("%d\n", num2);
	}
	else {
		printf("%d\n", num1);
	}
	
	
	*/	//상수와 변수의 값이 같은지 비교할때 상수를 앞에 배치하여, 숨겨진 에러 발생 예방 (2 == n1)

	/*int x, y;
	scanf("%d %d", &x, &y);
	if (x > 0 && y > 0) {
		printf("제 1사분면");
	}
	else if (x < 0 && y > 0) {
		printf("제 2사분면");
	}
	else if (x < 0 && y < 0) {
		printf("제 3사분면");
	}
	else if (x > 0 && y < 0) {
		printf("제 4사분면");
	}
	else {
		printf("축 위에 존재");
	}*/

	//초(sec)를 입력하고 계산해서 출력
	// 3650초는 hh 시간 mm분 ss초입니다.

	int input, sec, min, hour;
	printf("초(second)를 입력하세요 >>> ");
	scanf("%d", &input);
	hour = input / 3600;
	min = (input%3600) / 60;
	sec = input % 60;
	printf("%d시간 %d분 %d초", hour, min, sec);

	//programmers Lv.0




	return 0;

}

