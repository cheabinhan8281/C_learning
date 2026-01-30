#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>		// Standard Input/Output 표준 입출력 관련 함수
#include <string.h>		// 문자열 처리에 관련된 함수
int main()
{
	//char sz[] = { 65,66,67,68,69,70,0 };
	//int len = sizeof(sz) / sizeof(char);		// 배열의 길이

	//for (int i = 0; i < len; i++)
	//{
	//	printf("%c", sz[i]);
	//}

	// 배열로 문자열 만들기: 배열 끝에 0 추가.
	// 문자열 == 배열 
	// 0 == '\0'	null terminated character(문자열 마감)
	// char sz[] = {'A','B','C','D','E','F','\0'};			// 작은 따옴표'' 안에 한 문자만 가능!
	//char sz[] = { 'H', 'e','l','l','o' ,'\0'};
	char sz[] = "Hello";		// 문자열 (string)
	//int len = sizeof(sz);
	//printf("sz배열의 크기: %d\n", len);			// 6
	//printf("%s\n", sz);
	//sz[1] = sz[1] - 32;
	//printf("%s\n", sz);

	// 배열의 크기와 문자열의 길이
	// 문자열의 길이
	int slen = strlen(sz);
	printf("sz문자열의 길이: %d\n", slen);		// 5

	char sz2[] = "Hello";
	// 문자열 비교
	//if (sz == sz2)			// 잘못된 비교
	if(strcmp(sz, sz2) == 0)	// 옳은 비교
		printf("%s와 %s는 서로 같음\n", sz, sz2);
	else
		printf("%s와 %s는 서로 다름\n", sz, sz2);
	printf("%d \n%d\n", &sz, &sz2);

	// 문자열의 입력
	//입력 데이터: "Tom Cruze\n"
	//scanf: "Tom"
	//fgets: "Tom Cruze\n"

	char name[20];			// 알파벳 9글자 + \0  입력가능
	printf("이름을 입력하세요: ");
	//scanf("%s", name);		// 문자열 입력 %s, 배열의 경우: &(주소연산자) 사용X, 공백 기준으로 입력 끊김
	//printf("%s\n", name);

	//fgets(받을 배열, 최대길이, stdin)			// 공백 있어도 입력 끊기지 않음
	//표준입력장치로부터 문자열을 입력받아 name에 대입
	fgets(name, 20, stdin);
	int len = strlen(name);
	name[len - 1] = 0;					// \n 제거
	printf("name: %s\n", name);

	// 문자열 길이: strlen
	// 문자열 비교: strcmp
	
	// 배열 문자열 대입: 

	printf("sz: %s\n", sz);
	strcpy(sz, "ABCDE");				// sz에 "ABCDE" 대입
	printf("%s\n", sz);
	//sz 공간이 6byte인데 7byte 넣어서 터짐
	//strcpy(sz, "ABCDEF");				// sz에 "ABCDEF" 대입 -> Overflow Runtime Error
	//printf("%s\n", sz);

	//syntax error(compile error)
	//runtime error <- debugging
	//logical error

	// 문자열 추가
	// in Python
	// s = 'abc'
	// s = s + 'def'
	// s = 'abcdef'
	// in C
	// name[20]: 알파벳 19글자까지 저장 가능
	strcat(name, "plus string"); // name = name + "plus string"
	printf("name: %s\n", name);




	return 0;
}
