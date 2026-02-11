#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* solution(int num_list[], size_t num_list_len)
{
    size_t bytes = sizeof(int) * num_list_len;
    int* answer = (int*)malloc(bytes);
    if (!answer)    
        return NULL;
    for (int i = 0; i < num_list_len; i++) {
        answer[i] = num_list[num_list_len-1-i];
    }
    return answer;
}

char* solution2(const char* my_string)
{
    size_t size = strlen(my_string);
    char* answer = (char*)malloc(size + 1);
    for (int i = 0; i < size; i++) {
        answer[size - 1 - i] = my_string[i];
    }
    answer[size] = 0;       // 문자열 마감 0 '\0'
    return answer;
}

void print_array(int arr[], size_t len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = { 1,2,3,4,5 };
    int* new_arr = solution(arr, 5);
    if (new_arr)
    {
        print_array(new_arr, 5);
        free(new_arr);
        new_arr = NULL;
    }
    return 0;
}

