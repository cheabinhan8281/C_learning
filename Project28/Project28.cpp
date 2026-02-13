#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include "Project28.h"
#define MAX_NAME    20


int main()
{
    //PERSON hong;
    //hong.age = 30;
    //hong.height = 180.5F;
    //strcpy(hong.name, "홍길동");
    //print_person(&hong);

    //SCORE score;
    //strcpy(score.name, "홍길동");
    //score.kor = 100;
    //score.eng = 100;
    //score.math = 100;
    //score.total = score.kor + score.eng + score.math;
    //score.avg = score.total / 3.F;
    //print_score(&score);

    //printf("hong의 크기: %llu 바이트\n", sizeof(hong));
    //printf("score의 크기: %llu 바이트\n", sizeof(score));

    SCORE sc;
    //input_score(&sc);       // sc 입력
    //print_score(&sc);       // sc 출력
    save_text("text.txt");
    printf("%d\n", get_file_size("text.txt"));
    load_text("text.txt");



    return 0;
}

