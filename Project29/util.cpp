#include "Project29.h"

void show_menu()
{
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
	char menu;
	do
	{
		printf("메뉴를 선택해주세요: ");
		scanf("%c", &menu);

		char tmp;
		scanf("%c", &tmp);

		if (menu >= '1' && menu <= '4')
			return menu;
		if (menu == 'x' || menu == 'X')
			exit(0);
		printf("잘못 입력했습니다. 다시 입력하세요.\n");
	} while (1);

	return 0;
}