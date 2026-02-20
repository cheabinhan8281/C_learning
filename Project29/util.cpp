#include "Project29.h"

void show_menu()
{
	system("cls");
	printf("1. 점수 입력\n");
	printf("2. 점수 출력\n");
	printf("3. 점수 수정\n");
	printf("4. 점수 삭제\n");
	printf("============\n");
	printf("x. 종료\n");
	printf("============\n");
}

char select_menu()
{
	int menu;
	do
	{
		printf("메뉴를 선택해주세요: ");
        menu = _getch();

		if (menu >= '1' && menu <= '4')
            return (char)menu;
		if (menu == 'x' || menu == 'X')
			exit(0);
		printf("잘못 입력했습니다. 다시 입력하세요.\n");
	} while (1);

	return 0;
}

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
// ppScores에 main 함수의 동적 메모리 배열의 주소가 저장됨
size_t input_score(SCORE** ppScores, size_t count)  // 2차원 포인터
{
    if (!ppScores)
    {
        printf("잘못된 호출입니다.\n");
        return count;
    }
    // printf("SCORE 구조체의 크기: %llu bytes\n", sizeof(SCORE));

    system("cls");

    SCORE sc;   // 입력을 받을 임시 구조체 변수

    printf("번호를 입력하세요: ");
    scanf("%d", &sc.number);


    printf("이름을 입력하세요: ");
    char tmp;
    scanf("%c", &tmp);


    fgets(sc.name, MAX_NAME, stdin);		// 문자열 입력 받기+공백
    sc.name[strlen(sc.name) - 1] = '\0';	// 입력된 엔터키 \n 제거

    printf("국어,영어,수학 점수를 차례로 입력하세요: ");
    scanf("%d %d %d", &sc.kor, &sc.eng, &sc.math);

    // total
    sc.total = sc.kor + sc.eng + sc.math;
    sc.avg = sc.total / 3.f;

    // grade
    sc.grade = get_grade(sc.avg);

    // 배열 생성하기
    size_t new_count = count + 1;   // 1개 입력 처리를 해야 하므로 기존 개수보다 +1
    size_t old_size = sizeof(SCORE) *count;
    size_t new_size = sizeof(SCORE) * new_count; // 새로운 배열의 크기

    // Heap 영역에 배열 새 생성
    SCORE* pNew = (SCORE*)malloc(new_size);
    if (!pNew)
    {
        printf("배열 생성 실패");
        return count;
    }

    // 기존 배열을 새배열에 모두 복사
    SCORE* pOldScore = *ppScores;
    if (pOldScore)
    {
        // 기존 데이터가 있다면
        memcpy(pNew, pOldScore, old_size);
        free(pOldScore);        // 기존 배열 삭제
    }
    // 지금 입력받은 데이터를 새로운 배열에 복사하기
    memcpy(pNew + count, &sc, sizeof(SCORE));

    // 배열의 주소를 새 배열 주소로 업데이트
    *ppScores = pNew;

    return new_count;
}


void print_scores(const SCORE* pScores, size_t count)
{
    if (!pScores)
    {
        printf("점수 데이터 출력 실패");
        return;
    }

    system("cls");
    printf("번호\t이름\t국어\t영어\t수학\t총점\t평균\t등급\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%.2f\t%c\n",
            pScores[i].number, pScores[i].name, pScores[i].kor, pScores[i].eng, 
            pScores[i].math, pScores[i].total, pScores[i].avg, pScores[i].grade);
    }
}

void wait()
{
    printf("\n계속하려면 아무키나 입력하세요...\n");
    _getch();
}

int find_score(SCORE* pScores, size_t count, uint number)
{
    for (int i = 0; i < count; i++)
    {
        if (pScores[i].number == number)
            return i;
    }
    return -1;
}

void select_update(SCORE* pScores, size_t count)
{
    print_scores(pScores, count);

    printf("=====================================\n");

    int idx = -1;
    do
    {
        uint number;
        printf("수정하고자 하는 학생의 번호를 입력하세요: ");
        scanf("%d", &number);
        idx = find_score(pScores, count, number);

    } while (idx == -1);

    char tmp;
    scanf("%d", &tmp);

    printf("번호: %d\n", pScores[idx].number);
    printf("이름: %s\n", pScores[idx].name);
    printf("점수(국영수): %3d %3d %3d\n", pScores[idx].kor, pScores[idx].eng, pScores[idx].math);
    printf("총점: %3d\n", pScores[idx].total);
    printf("평균: %.2f\n", pScores[idx].avg);

    printf("=====================================\n");


    printf("이름을 입력하세요: ");
    fgets(pScores[idx].name, MAX_NAME, stdin);		// 문자열 입력 받기+공백
    pScores[idx].name[strlen(pScores[idx].name) - 1] = '\0';	// 입력된 엔터키 \n 제거

    printf("국어,영어,수학 점수를 차례로 입력하세요: ");
    scanf("%d %d %d", &pScores[idx].kor, &pScores[idx].eng, &pScores[idx].math);

    // total
    pScores[idx].total = pScores[idx].kor + pScores[idx].eng + pScores[idx].math;
    pScores[idx].avg = pScores[idx].total / 3.f;

    // grade
    pScores[idx].grade = get_grade(pScores[idx].avg);




}