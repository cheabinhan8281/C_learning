#include "Project29.h"

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

// 한 명의 성적데이터를 입력받아 반환하는 함수
void input_score(SCORE* score)
{
    if (!score)
    {
        printf("잘못된 호출입니다.\n");
        return;
    }
    // printf("SCORE 구조체의 크기: %llu bytes\n", sizeof(SCORE));

    printf("번호를 입력하세요: ");
    scanf("%d", &score->number);

    //char tmp;
    //scanf("%c", &tmp);

    printf("이름을 입력하세요: ");
    fgets(score->name, MAX_NAME, stdin);		// 문자열 입력 받기+공백
    score->name[strlen(score->name) - 1] = '\0';	// 입력된 엔터키 \n 제거

    printf("국어,영어,수학 점수를 차례로 입력하세요: ");
    scanf("%d %d %d", &score->kor, &score->eng, &score->math);

    // total
    score->total = score->kor + score->eng + score->math;
       score->avg = score->total / 3.F;
       
    // grade
    score->grade = get_grade(score->avg);


}


int main()
{
    char menu;
    do {
        show_menu();
        menu = select_menu();
    } while (1);

    /*
    SCORE sc;
    input_score(&sc);
    //save_score(&sc);

    SCORE* score = load_score();
    if (!score)
    {
        printf("데이터 읽기 실패\n");
        return 0;
    }

    printf("번호: %u\n", score->number);
    printf("이름: %s\n", score->name);
    printf("국어: %u\n", score->kor);
    printf("영어: %u\n", score->eng);
    printf("수학: %u\n", score->math);
    printf("총합: %u\n", score->total);
    printf("평균: %.2f\n", score->avg);
    printf("등급: %c\n", score->grade);

    if (score)
    {
        free(score);
        score = NULL;
    }

    */

	return 0;
}
