#define _CRT_SECURE_NO_WARNINGS
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
void upper_case(char sz[])              // char* arr == char arr[]
{
    int len = strlen(sz);
    for (int i = 0; i < len; i++)
    {
        if (sz[i] >= 'a' && sz[i] <= 'z')
            sz[i] = sz[i] - 32;
    }
}

// 문자열 내에 있는 숫자들을 모두 더해 반환하는 함수
int string_sum(const char* sz)
{
    int len = strlen(sz);
    int total = 0;
    for (int i = 0; i < len; i++)
    {
        if (sz[i] >= 48 && sz[i] <= 57)
            total += sz[i]-48;
        /* 아스키코드 48 == '0'
        if (sz[i]>= '0' && sz[i] <='9')
            tot += (sz[i]-'0');
        */
    }
    return total;
}

// 문자열을 전달받아 뒤에서부터 출력하는 함수
void print_reverse(const char* arr)
{
    int len = strlen(arr);
    for (int i=len; i>=0; i--)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}

// 문자열을 전달받아 특정 문자가 몇개 있는지 세서 반환하는 함수
int char_count(const char* arr, const char a)
{
    int len = strlen(arr);
    int count = 0;
    for (int i = 0; i <= len; i++)
    {
        if (a == arr[i])        // 함수 a: a 자리에 받는 변수 찾기, 'a': a만 찾기
            count++;
    }
    return count;
}

// 문자열에서 특정 문자를 찾아서 있다면 해당 문자의 인덱스 반환, 없다면 -1 반환 함수
int find_char(const char* arr, const char a)
{
    int len = strlen(arr);
    int index = -1;
    for (int i = 0; i <= len; i++)
    {
        if (a == arr[i])       
            index=i;
    }
    return index;
}

// 문자열을 받아서 자음만 출력하는 함수
void print_conson(const char* arr)
{
    int len = strlen(arr);
    for (int i = 0; i <= len; i++)
    {
        if (arr[i] != 'a' && 
            arr[i] != 'e' && 
            arr[i] != 'i' && 
            arr[i] != 'o' &&
            arr[i] != 'u')
            printf("%c",arr[i]);        // switch-case,find_char 이용
    }
}



int main()
{

    char sz1[] = "Hello World";

    //// 문자열의 길이: strlen
    //printf("문자열의 길이: %d\n", strlen(sz1));       // 마지막 0 배제
    //// 배열의 크기: sizeof
    //printf("배열의 크기: %d\n", sizeof(sz1));         // 마지막 0 포함

    upper_case(sz1);
    printf("%s\n",sz1);

    //

    char sz2[] = "abcd123";
    printf("%d\n", string_sum(sz2));

    //

    const char* psz = "Nice to meet you";       // char sz = 'Hello' 불가, char* sz = 'Hello' 가능 <- psz 주소 저장됨
    //psz = "Hello";

    strcpy(sz1, "Hello C");
    sz1[1] = 'E';           // 개별적 문자 수정 가능
    printf("%s\n", sz1);

    //strcpy(psz, "SBS");   // 개별적 문자 수정 불가, 포인터 값이 바뀌면서 가리키는 대상이 바뀌는 것 뿐.
    // psz[2] = 'E'         
    printf("%c\n", psz[2]);

    // 함수 별로 배열을 받을 때
    // 받은 배열 값을 바꿀 때 -> char arr[]
    // 받은 배열 값을 바꾸지 않을 때 -> const char* arr

    //
    printf("%s\n", psz);
    print_reverse(psz);

    //
    printf("개수: %d\n", char_count(psz, 'l'));
    //
    printf("인덱스: %d\n", find_char(psz, 'a'));
    //
    print_conson(psz);

    return 0;
}

