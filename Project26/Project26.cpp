#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution4(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t size = strlen(my_string) + 1;
    char* answer = (char*)malloc(size);
    if (!answer) return NULL;
    memset(answer, 0, size);        // 문자열의 자연스러운 완성을 위해 내용을 모두 0으로 초기화
    const char* vow = "aeiou";
    for (int i = 0,j=0 ; i < size - 1; i++)
    {
        if (!strchr(vow, my_string[i]))
            answer[j++] = my_string[i];

    }

    return answer;
}

//정수 배열 numbers와 정수 num1, num2가 매개변수로 주어질 때, 
//numbers의 num1번 째 인덱스부터 num2번째 인덱스까지 자른 정수 배열을 return 하도록 solution 함수를 완성해보세요.

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len, int num1, int num2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t size = sizeof(int) * numbers_len;
    int* answer = (int*)malloc(size);
    for (int i = num1; i < num2+1; i++)
        answer[num1-i] = numbers[i];
    return answer;
}

void print_array(int arr[], size_t len_arr)
{
    for (int i = 0; i < len_arr; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    char* sz = solution4("I need you");
    printf("%s", sz);
    if (sz) {
        free(sz);
        sz = NULL;
    }

    return 0;
}
