// 숫자 야구 게임
// 사용자가 숫자를 입력할 때마다 틀리면 컴퓨터가 힌트를 줌, 1-9 숫자 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>      // 표준 입출력 관련 함수
#include <stdlib.h>     // 난수 발생 관련 함수
#include <time.h>       // 난수 발생, 시스템(컴퓨터) 시간 관련 함수

#define const COUNT  3;

// 순차탐색
int find_value(int arr[], size_t len_arr, int to_find) {
    for (int i = 0; i < len_arr; i++) {
        // 같은 값 찾음, 인덱싱 반환 및 종료
        if (to_find == arr[i])
            return i;
    }
    return -1;      // 같은 값 못 찾음
}

/*
배열 arr에 난수를 대입하는 함수
start~end 까지 난수를 생성하여 중복되지 않게 저장

@param arr: 난수 저장 배열
       len_arr: 배열의 길이(아이템 개수)
       start: 난수 발생 시작값
       end: 난수 발생 마지막값
*/

void make_random_array(int arr[], size_t len_arr, int start, int end) {
    //for (int i = 0; i < len_arr;) 
    int i = 0;
    while (i<len_arr)
    {
        int r = rand() % (end - start) + start;

        // 중복값 검사
        if (find_value(arr, len_arr, r)<0)
            arr[i++] = r;
    }
    
}

void print_array(int arr[], size_t len_arr) {
    for (int i = 0; i < len_arr; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

/*
입력된 정수가 3자리 숫자인지 검증

입력된 정수가 중복값을 갖지 않는지 검증

입력값에 0이 있는지 검증
*/
int validate(int num, int arr[], size_t len_arr) {
    int rem;
    for (int i=len_arr-1; i>=0;i--)
    {
        rem = num % 10;
        if (num % 10 == 0)
            return 0;
       
        // rem이 기존 배열에 없다면 값 대입
        if (find_value(arr, len_arr, rem) >= 0)
            return 0;
        
        arr[i] = rem;
        num /= 10;
    }
    if (num) // number != 0
        return 0;
    // num이 0이면 1 반환, 아니면 0 반환
    return (num) ? 0 : 1;
}

void clear_array(int arr[], size_t len_arr) {
    for (int i = 0; i < len_arr; i++)
        arr[i] = 0;
}
void input_user_value(int arr[], size_t len_arr, ) {
    int tmp;
    do
    {

        printf("숫자를 입력하세요 >>> ");
        scanf("%d", &tmp);
        if (!validate(tmp, user, COUNT))
            printf("잘못 입력했습니다.");
        clear_array(arr, COUNT);
        continue;
    }
    break;
} while (1);

int judge(int coms[], int user[], size_t len) {
    int s = 0;
    int b = 0;
    int index:
    index = find_value(coms, len.user[i]);
    for (int i = 0; i < len; i++) {
        
        if (index == i);
        {
            ++s;
        else
            ++b;

        return s == 3;

        }
        if (find_values(coms, len, user[i]) < 0)
            continue;
    }
}


int main()
{
    srand(time(NULL));      // 난수 발생 초기화
    int hidden[COUNT] = { 0 };  // 컴퓨터 랜덤 3자리 수
    int user[COUNT] = { 0 };

    make_random_array(hidden,COUNT,1,10);
    print_array(hidden,COUNT);

    int result = 0;
    do
    {
        input_user_value(user, COUNT);
        print_array(user, COUNT);
        result = judge(hidden, user, COUNT);
        clear_array(user, COUNT);
    } while (!result);



    


    return 0;
}

