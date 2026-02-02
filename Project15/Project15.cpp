#include <stdio.h>
#include <iostream>

// 함수 호출 시 먼저 정의되어야 함!
// 반환값이 없거나 1개
// 매개변수는 없거나, 여러개 
// 호출 시 매개변수가 선언된 위치와 개수가 일치하게 전달해야함

//아메리카노 함수
int americano(int money)
{
    int cup = money / 1500;
    return cup;
}

int totaler(int until)
{
    int total = 0;
    for (int i = 0; i <= until; i++)
    {
        total += i;
    }
    return total;
}

// 사칙연산 함수 (+-/*, 그 외 지원X)
int calculator(int num1, char op, int num2)
{
    int res = 0;
    switch (op)
    {
    case '+':
    {
        res = num1 + num2;
        break;
    }
    case '-':
    {
        res = num1 - num2;
        break;
    }
    case '*':
    {
        res = num1 * num2;
        break;
    }
    case '/':
        if (!num2)          // num2 == 0, !num2 ; 0이냐 아니냐 판단
        {
            res = printf("0으로 나눌 수 없습니다.\n");
            break;
        }
        res = num1 / num2;
        break;
    default:
        res = printf("지원하지 않는 연산자입니다.");
        break;
    } return res;

}

int birth_year(int age)
{
    int byear = 2026 - age +1;          // 상수화: const int cur_year = 2026, #define CUR_YEAR  2026
    return byear;
}

int calc_price(int price)
{
    int fprice = price * 1.1;
    return fprice;
}

void odd_or_even(int num1, int num2)
{
    int total = num1 + num2;
    printf("%s\n", total % 2 == 0 ? "홀수" : "짝수");       // 파이썬: 참 if 조건 else 거짓, C언어: 조건 ? 참 : 거짓
}

char change(char alpha)
{
    if (alpha > 95)     // alpha > 'a' && alpha <= 'z'
        return alpha - 32;
    return alpha + 32;
}


int main()
{
    int money = 5000;
    int cup = americano(money);
    printf("%d원으로 아메리카노 %d잔 구매 가능\n", money, cup);

    int sum = totaler(10);
    printf("1부터 10까지 합: %d\n", sum);
    sum = totaler(100);
    printf("1부터 100까지 합: %d\n", sum);

    sum = calculator(5, '/', 0);
    printf("%d\n", sum);

    int byear = birth_year(23);
    printf("%d년도\n", byear);

    int fprice = calc_price(25000);
    printf("%d원\n", fprice);

    odd_or_even(13, 34);

    printf("%c\n", change('F'));

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
