#include <stdio.h>      //표준입출력 함수
#include <string.h>     //문자열 처리 함수

void string_info(char sz[])       // 포인터 변수의 크기: 8바이트, 배열과 다르게 문자열은 0으로 끝을 알 수 있기에 개수 안넣어줘도 됨
{
    int len = strlen(sz);   
    // 문자열의 길이: strlen
    printf("문자열의 길이: %d\n", len);       
    // 배열의 크기
    printf("배열의 크기: %d\n", len+1);         
}

// 문자열 전달받아 대문자로 바꾸는 함수
void upper_case(char sz[])
{
    int len = strlen(sz);
    for (int i = 0; i < len; i++)
    {
        if (sz[i] >= 'a' && sz[i] <= 'z')
            sz[i] = sz[i] - 32;
    }
}

// 문자열 내에 있는 숫자들을 모두 더해 반환하는 함수
int string_sum(char sz[])
{
    int len = strlen(sz);
    int total = 0;
    for (int i = 0; i < len; i++)
    {
        if (sz[i] >= 48 && sz[i] <= 57)
            total += sz[i]-48;
    }
    return total;
}


int main()
{

    char sz1[] = "Hello World";
    char sz2[] = "abcd12345";

    //// 문자열의 길이: strlen
    //printf("문자열의 길이: %d\n", strlen(sz1));       // 마지막 0 배제
    //// 배열의 크기: sizeof
    //printf("배열의 크기: %d\n", sizeof(sz1));         // 마지막 0 포함

    upper_case(sz1);
    printf("%s\n",sz1);

    printf("%s", string_sum(sz2));

    return 0;
}

