// 포인터

#include <stdio.h>
#include <iostream>

void pfunc(int* p)
{
    * p += 100;
}

void exchange(int* p1, int* p2)
{
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}



int main()
{

    /* 새로 입력받을테니 초기화해서 계산 낭비할 이유X
    int n = 0;
    scanf("%d", &n);
    */

    int n,k;
    n = 5;
    printf("n의 주소: %p\n", &n);      // %p: 주소 매핑 문자 ; 변수 앞에 단독으로 & 있을 때, 주소연산자로 사용
    // *: 아스테리크
    // *이 붙은 변수: 포인터(변수)
    // 포인터는 주소(Address)만 저장 가능
    int* p;
    p = &n;
    printf("p의 값: %p\n", p);
    
    k = 10;
    p = &k;
    // *p: p가 가리키는 값 *p==k, p==&k
    printf("p가 가리키는 값: %d\n", *p);

    p = &n;
    printf("p가 가리키는 값: %d\n", *p);

    *p = 20;
    printf("n: %d\t*p: %d\n", n, *p);

    // p를 이용하여 k의 값을 100으로 변경하기
    p = &k;
    *p = 100;
    printf("k: %d\t*p: %d\n", k,*p);
    pfunc(&n);
    pfunc(&k);
    printf("n: %d\tk: %d\n",n,k);
    
    exchange(&n, &k);
    printf("n: %d\tk: %d", n,k);
    return 0;
}

