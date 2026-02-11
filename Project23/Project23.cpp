// 숫자 야구 게임
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 3

// 순차 탐색
int find_value(int arr[], size_t len, int value) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// 중복 없는 난수 배열 생성
void make_random_array(int arr[], size_t len, int start, int end) {
    int i = 0;
    while (i < len) {
        int r = rand() % (end - start) + start;
        if (find_value(arr, len, r) < 0)
            arr[i++] = r;
    }
}

void print_array(int arr[], size_t len) {
    for (int i = 0; i < len; i++)
        printf("%d", arr[i]);
    printf("\n");
}

// 입력값 검증 + 배열로 분해
int validate(int num, int arr[], size_t len) {
    for (int i = len - 1; i >= 0; i--) {
        int rem = num % 10;

        if (rem == 0) return 0;
        if (find_value(arr, len, rem) >= 0) return 0;

        arr[i] = rem;
        num /= 10;
    }
    return num == 0;
}

void clear_array(int arr[], size_t len) {
    for (int i = 0; i < len; i++)
        arr[i] = 0;
}

// 사용자 입력
void input_user_value(int user[], size_t len) {
    int tmp;
    while (1) {
        printf("숫자를 입력하세요 >>> ");
        scanf("%d", &tmp);

        if (validate(tmp, user, len))
            break;

        printf("잘못 입력했습니다.\n");
        clear_array(user, len);
    }
}

// 스트라이크 / 볼 판정
int judge(int com[], int user[], size_t len) {
    int strike = 0;
    int ball = 0;

    for (int i = 0; i < len; i++) {
        int idx = find_value(com, len, user[i]);
        if (idx == i)
            strike++;
        else if (idx >= 0)
            ball++;
    }

    printf("%d Strike %d Ball\n", strike, ball);
    return strike == len;
}

int main() {
    srand(time(NULL));

    int hidden[COUNT] = { 0 };
    int user[COUNT] = { 0 };

    make_random_array(hidden, COUNT, 1, 10);
    // print_array(hidden, COUNT); // 디버그용

    int win = 0;
    while (!win) {
        input_user_value(user, COUNT);
        win = judge(hidden, user, COUNT);
        clear_array(user, COUNT);
    }

    printf("정답입니다!\n");
    return 0;
}
