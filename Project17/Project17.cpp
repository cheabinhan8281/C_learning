#include <stdio.h>
#include <iostream>

void display_var(int a, int b)
{
    printf("%d, %d\n", a, b);
}




int main()
{
    int n = 5;
    printf("n의 주소: %p\n", &n);

    int arr[100];
    printf("arr의 주소: %p\n", arr);               // arr의 주소 == arr[0]의 주소
    printf("arr[0]의 주소: %p\n", &arr[0]);
    printf("arr+1의 주소: %p\n", arr + 1);         // arr + 1의 주소 == arr[1]의 주소
    printf("arr[1]의 주소: %p\n", &arr[1]);
    printf("arr+2의 주소: %p\n", arr + 2);
    printf("arr[2]의 주소: %p\n", &arr[2]);

    int *p = arr;       // 포인터 변수: 8바이트
    char* sz;

    for (int i = 0; i < 100; i++)
    {
        arr[i] = i + 1;
    }

    printf("arr[5] = %d\n", arr[5]);
    printf("p[5] = %d\n", p[5]);



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
