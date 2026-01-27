#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define COUNT   5       // 매크로 상수

int main()
{
    /*
    const int NUMBER = 5;   // 상수 정의
    */

    /*
    int i = 0;
    while (i < COUNT) {
        int j = 0;
        while (j < COUNT) {
            printf("*");
            j++;
        } 
        printf("\n");
        i++;
     
    }*/

    //do while();       # 반복문 안의 명령문을 적어도 한번 실행
                       // while() 뒤에 반드시 ; 붙여줌
    char ch, tmp;
    do
    {
        printf("1. 새파일\n");
        printf("2. 저장\n");
        printf("3. 열기\n");
        printf("=============\n");
        printf("x. 종료\n");

        printf("\n메뉴를 선택해주세요: ");
        scanf("%c", &ch);           // %c -> 문자 1 ('1')로 인식
        scanf("%c", &tmp);          // 입력버퍼 초기화
        
        switch (ch)
        {
        case '1':
            printf("\n새 파일이 선택되었습니다.\n");
            break;
        case '2':
            printf("\n저장이 선택되었습니다.");
            break;
        case '3':
            printf("\n열기가 선택되었습니다.");
            break;
        case 'x':break;
        default:
            printf("\n잘못입력했습니다. 다시 입력해주세요.");
            break;

        }

         /* switch 대용 if문
         if (ch == '1') printf("~~")
         else if (ch == '2')
         */

    } while (ch!='x');



    return 0;
}

