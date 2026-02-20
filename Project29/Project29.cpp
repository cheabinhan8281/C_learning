#include "Project29.h"



int main()
{
    // 메인 데이터들이 저장될 배열 -> 동적 배열 // arr[20] 같이 한정된 공간X
    SCORE* scores=NULL;     // 동적인 배열
    size_t count = 0;       // 배열의 현재 아이템 개수

    count = load_score(&scores);

    char menu;
    do {
        show_menu();
        menu = select_menu();
        switch (menu)
        {
        case '1':       // 점수 입력
            count = input_score(&scores, count);
            save_score(scores, count);
            print_scores(scores, count);
            break;
        case '2':       // 점수 출력
            print_scores(scores, count);
            break;
        case '3':       // 점수 수정
            select_update(scores, count);
            save_score(scores, count);
            print_scores(scores, count);

            break;
        case 'x':
            if (scores)
            {
                free(scores);
                scores = NULL;
            }
        }

        // 일시 정지 화면전환
        if (menu != 'x') wait();


    } while (menu != 'x');

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
