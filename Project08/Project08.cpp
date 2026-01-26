
#include <iostream>
#define COUNT   5       // 매크로 상수

int main()
{
    /*
    const int NUMBER = 5;   // 상수 정의
    */

    int i = 0;
    while (i < COUNT) {
        int j = 0;
        while (j < COUNT) {
            printf("*");
            j++;
        } 
        printf("\n");
        i++;
    }


    return 0;
}

