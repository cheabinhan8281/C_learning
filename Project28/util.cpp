#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include "Project28.h"
#define MAX_NAME    20

// 함수 원형 정의; 함수를 호출하는 쪽에 정보 제공
char get_grade(float);
void input_score(SCORE* psc);
long get_file_size(const char* filename);




char get_grade(float avg)
{
    int tmp = (int)avg / 10;
    switch (tmp)
    {
    case 10:
    case 9:
        return 'A';
    case 8:
        return 'B';
    case 7:
        return 'C';
    case 6:
        return 'D';
    }
    return 'F';
}

//void print_person(PERSON *p)         // PERSON p: 28bytes -> PERSON* p: 8bytes
//{
//    printf("이름: %s\n", p->name);
//    printf("나이: %d\n", p->age);
//    printf("키: %.2f\n", p->height);
//}
//
//void print_score(SCORE *s)
//{
//    printf("이름: %s\n", s->name);
//    printf("국어: %d\n", s->kor);
//    printf("영어: %d\n", s->eng);
//    printf("수학: %d\n", s->math);
//    printf("총합: %d\n", s->total);
//    printf("평균: %.2f\n", s->avg);
//    printf("등급: %c\n", s->grade);
//}

void input_score(SCORE* psc)
{
    if (!psc)
        return;

    // 문자열 입력 쉽게 받기 위해 모든 자리 0으로 채움
    memset(psc, 0, sizeof(SCORE));

    // 공백 입력 가능 함수
    printf("이름을 입력하세요: ");
    fgets(psc->name, MAX_NAME, stdin);
    int len = strlen(psc->name);
    psc->name[len - 1] = '\0';          // enter key code가 입력된 자리에서 null terminated

    printf("국어점수를 입력하세요: ");
    scanf("%d", &(psc->kor));
    printf("영어점수를 입력하세요: ");
    scanf("%d", &(psc->eng));
    printf("수학점수를 입력하세요: ");
    scanf("%d", &(psc->math));

    // 총점 구하기
    psc->total = psc->kor + psc->eng + psc->math;
    psc->avg = psc->total / 3.f;
    psc->grade = get_grade(psc->avg);
}

void print_score(SCORE* psc)
{
    if (!psc)       // NULL일 때 빠져나가게
        return;
    printf("이름: %s\n", psc->name);
    printf("점수: 국어(%d), 영어(%d), 수학(%d)\n", psc->kor, psc->eng, psc->math);
    printf("총점: %d\n", psc->total);
    printf("평균: %.2f\n", psc->avg);
    printf("등급: %c\n", psc->grade);
}

void save_text(const char* filename)
{
    if (!filename)
        return;

    // open mode
    // "r": read mode, 파일을 읽기 위해 오픈. 파일 없으면 에러
    // "w": write mode, 파일을 저장하기 위해 오픈. 항상 새 파일 생성
    // "a": append mode, 파일을 저장하기 위해 오픈, 기존 데이터에 추가로 저장
                          //파일이 없으면 "w" 동작
    // "b": binary file을 읽고 쓰기 위함
    // "t": text file을 읽고 쓰기 위함

    FILE* fp = NULL;        // 파일 핸들
    fp = fopen(filename, "wt");

    const char* sz1 = "Hello World\n";
    const char* sz2 = "Welcome to my house\n";
    const char* sz3 = "Good bye, see you\n";

    /*EX
    int arr[10];
    fwrite(sz1, sizeof(int), 10, fp);
    */
    
    fwrite(sz1, sizeof(char), strlen(sz1), fp);      // buffer, elem_size, elem_count: 저장하려는 데이터 단위 크기, 개수
    fwrite(sz2, sizeof(char), strlen(sz2), fp);
    fwrite(sz3, sizeof(char), strlen(sz3), fp);

    fclose(fp);
}

long get_file_size(const char* filename)
{
    if (!filename)
        return 0;

    // cursor를 파일의 끝지점(EOF)으로 이동 및 위치 확인 -> 파일 크기
    FILE* fp = NULL;        // 파일 핸들
    fp = fopen(filename, "r");
    if (!fp)
    {
        printf("파일을 열 수 없습니다.");
        return 0;
    }
    // offset: 이동시킬 거리
    // origin: 기준점, 여기서부터 offset 만큼 이동
    // SEEK_SET: BOF, Begin Of File, 파일 시작점
    // SEEK_CUR: 현재 커서 위치
    // SEEK_END: EOF, End Of File, 파일 마치막 위치
    // fseek(fp, offset, origin);
    fseek(fp, 0, SEEK_END); // 파일의 마지막 지점부터 0만큼 이동

    long loc = ftell(fp);   // 커서 위치 받음

    fclose(fp);
    return loc;
}

void load_text(const char* filename)
{
    if (!filename)
        return;

    long size = get_file_size(filename);
    if (!size)
        return;


    FILE* fp = NULL;        // 파일 핸들
    fp = fopen(filename, "rt");
    if (!fp)
    {
        printf("파일을 열 수 없습니다.");
        return;
    }

    // 크기 할당
    char* buf = (char*)malloc(size);
    if (!buf)
    {
        fclose(fp);
        return;
    }

    // 문자열 처리를 안정적으로 하기위해 읽을 버퍼를 모두 0으로 채워줌 -> 문자열 끝은 0 필수
    memset(buf, 0, size);

    fread(buf, sizeof(char), size, fp);
    printf("%s\n", buf);


    fclose(fp);
    fp = NULL;
    if (buf)
    {
        free(buf);
        buf = NULL;
    }
}