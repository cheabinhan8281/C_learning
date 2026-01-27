#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    // 사칙연산을 수행하는 계산기 프로그램 작성
    // 두개의 정수와 연산자를 입력받아 연산 수행 및 결과 출력
    
    int num1, num2, res;
    char mark, ch, tmp;
    do
    {
        printf("\n사칙연산 프로그램  ");
        

        printf("\n첫번째 정수를 입력하세요: ");
        scanf("%d", &num1);
        scanf("%c", &tmp);

        printf("\n다음 연산자 중 하나를 입력하세요 (+, -, *, /) (x 입력시 종료): ");
        scanf("%c", &mark);
        scanf("%c", &tmp);
        if (mark == 'x') break;

        printf("\n두번째 정수를 입력하세요: ");
        scanf("%d", &num2);

        switch (mark)
        {
        case '+':
            printf("%d + %d = %d", num1, num2, num1+num2);
            break;
        case '-':
            printf("%d - %d = %d", num1,num2, num1-num2);
            break;
        case '*':
            printf("%d * %d = %d", num1, num2, num1*num2);
            break;
        case '/':
            printf("%d / %d = %d", num1, num2, num1/num2);
            break;
        case 'x': 
            printf("x 입력시 종료");
            break;
        default:
            break;
        }

        
    } while (mark != 'x'); 


    return 0;
}

