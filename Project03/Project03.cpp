#define _CRT_SECURE_NO_WARNINGS //가장 위에! _s 시리즈 함수 에러 발생 안함
#include<stdio.h>

int main()
{
	//기본 입력문 c-compiler: msvc(표준+a), ... clang, gcc, g++
	short n;
	char ch;
	printf("정수를 입력하세요: ");
	scanf("%hd", &n);	//표준 입력 장치로부터 입력을 받아 변수 n에 저장, 자료 크기에 맞게 d, hd, hhd,ld, lld 조정
	//scanf("%hhd", &ch); //& 엠퍼센드, | 파이프라인

	printf("%s\n", n % 2 ? "홀수" : "짝수");
	//error 종류: 컴파일에러(문법 에러), 런타임 에러, 논리적인 에러
	scanf("%c", &ch);		// scanf를 여러번 쓸 때, enter 등 계산값 난입 방지를 위해 입력버퍼 낭비시키기, 잔여값 처리

	printf("문자를 입력하세요: \n");
	scanf("%c", &ch);
	printf("입력된 문자: %c\n", ch);
	printf("ch에 저장된 값: %hhd\n", ch);


	//scanf("%hd", &n);


	return 0;
}

