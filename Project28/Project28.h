#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include "Project28.h"
#define MAX_NAME    20

// typedef: 형(Data type) 재정의
typedef unsigned int UINT;
typedef unsigned short JUMSU;
typedef unsigned long long TIME;

// 구조체(Structure)
typedef struct
{
    char name[20];
    int age;
    float height;

}PERSON;

typedef struct {
    char name[20];
    short kor;
    short eng;
    short math;
    short total;
    float avg;
    char grade;
}SCORE;

// 함수 원형 정의; 함수를 호출하는 쪽에 정보 제공
char get_grade(float);
void input_score(SCORE* psc);
void print_score(SCORE* psc);
void save_text(const char* filename);
void load_text(const char* filename);
long get_file_size(const char* filename);



