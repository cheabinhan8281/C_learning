#include <stdio.h>
#include <iostream>
// 함수: 특정 목적을 처리하기 위한 코드를 처리의 이름을 부여하여 정의
// 함수(매개변수; parameter, argument, 인수, 인자)

//void: 없다, *모르다
void print_int(int number)          // void 함수: 호출부에 결과를 반환하지 않는 함수
{
    printf("정수: %d\n", number);
}

int add(int a, int b)               // int 함수: 반환값의 데이터 타입 정의를 int형으로 했으므로 함수 내부에서 정수형 값 반환
{
    int c = a + b;
    return c;
}

void show_menu()        // 매개변수, 반환값 없는 함수
{
    printf("1. 새 파일\n");
    printf("2. 파일 저장\n");
    printf("3. 파일 열기\n");
    printf("x. 종료\n");
}

int main()
{
    // print_int() 함수의 호출
    // 함수 정의 -> 호출
    print_int(1);   
    print_int(2);
    print_int(3);
    int a = add(10, 5);
    printf("%d", a);

    return 0;
}

