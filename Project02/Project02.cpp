#include <iostream>
//Data Type
//정수: 음수, 0, 양수
// char(1byte), short(2), int(4), long(W:4, M:8), long long(8)

//실수: 소수점을 포함하는 숫자
//float(4byte), double(8), long double

int main()
{
    //정수형
    char n; //2^8개의 서로 다른 데이터 표현
    short num; //2^16개의 서로 다른 데이터 표현
    int score; //2^32개의 서로 다른 데이터 표현
    long money; //2^32개의 서로 다른 데이터 표현
    long long big_number; //2^64개의 서로 다른 데이터 표현

    //sizeof 연산자(operator): 타입 또는 변수의 크기를 바이트 단위로 알려줌
    printf("n의 크기: %d\n", sizeof(char));
    printf("num 타입의 크기: %d\n", sizeof(short));
    printf("score의 크기: %d\n", sizeof(int));
    printf("money의 크기: %d\n", sizeof(long));
    printf("big_number의 크기: %d\n", sizeof(long long));

    printf("double의 크기: %d\n", sizeof(double));

    n = 127;
    printf("n의 값: %d\n", n);
    n = 128;    //char 형식으로 128 저장 불가
    printf("n의 값: %d\n", n);
    n = 100;
    printf("n의 값: %x\n", n);
    printf("n의 값: %o\n", n);
    printf("n을 문자로 표현: %c\n", n);

    double d = 100.0;
    printf("d의 값: %f\n", d);
    printf("d의 값: %e\n", d);

    n = 65;
    printf("n을 문자로 표현: %c\n", n);
    n = 'A';    //아스키코드에 따라 'A'=65
    printf("n을 문자로 표현: %c\n", n);

    printf("숫자 출력: %d\n", 10);
    printf("오른쪽 숫자 출력: %5d\n", 10);  //정수를 출력할 때 자릿수 5칸을 확보하여 오른쪽 정렬 후 출력
    printf("왼쪽 숫자 출력: %-5d\n", 10);  //정수를 출력할 때 자릿수 5칸을 확보하여 왼쪽 정렬 후 출력
    printf("%6.2f\n", 180.78); //소수점 포함 6자리 확보한 뒤, 소수점 이하 두자리까지만 표현
    printf("%.2f\n", 33234.7899999); //정수 전부, 소수점 이하 두자리까지만 표현


    n = 10;
    big_number = 123456789;
    score = 12345;

    //기본: %d는 int 크기에 맞춤
    printf("%d\n", score);        //int
    printf("%hd\n", num);         //short
    printf("%hhd\n", n);          //char
    printf("%ld\n", money);       //long
    printf("%lld\n", big_number); //long long

    unsigned char age;      //0~225까지 표현
    age = 80;
    printf("%hhu\n", age);  //unsigned char


    //형식 문자(Formatted Strings)
    //%d: 정수형으로 표현 hhd/hd/d/ld/lld
    //%u: 양의 정수형으로 표현 (unsigned) hhu/hu/u/lu/llu
    //%f: 실수형으로 표현
    //%x: 16진수로 표현
    //%o: 8진수로 표현
    //%e: 지수형으로 표현
    //%c: 문자로 표현
    //%s: 문자로 표현
    return 0;
}


//OS(Operating System)
//운영체제 - Windows 10,11 mac, linux

//Unix: 조상 (유료)
//linux: Unix 오픈 소스 버전 (무료)
//CentOS, RED-Hat, Debian, Ubuntu, Amazon-Linux...
//MacOS, iOS
//Android

//Windows - 아예 다른 구성

//Hardware: CPU, RAM, Disk
//+Software: -> computer system
//
//그룹핑: 단순 묶기
//폴더링: 상위하위 경로 탐색, 폴더=디렉토리
// 파일이 위치하는 곳: 절대경로, 상대경로, path

//명령 프롬프트
//Windows PowerShell: 프롬프트+ 확장 버전

//dir: directory 목록
//cd N: change directory N 폴더 이동
//.: 현재 위치
//..: 상위 위치
// cd ..: 상위 위치 이동
//cd \: 최상위 위치 이동
//md N: make directory N 폴더 추가
//notepad
//notepad test.txt
//type test.txt
//copy test.txt copy_test.txt #1개 파일이 복사되었습니다.
//copy copy_test.txt c : \ #1개 파일이 복사되었습니다.