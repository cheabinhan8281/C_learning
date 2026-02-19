#include "Project29.h"

long get_file_size(const char* filename)
{
	if (!filename)
	{
		printf("파일명은 주어져야합니다.\n");
		return -1;
	}

	FILE* fp = NULL;
	fp = fopen(FILENAME, "rb");
	if (!fp)
	{
		printf("파일을 열 수 없습니다.\n");
		return -1;
	}

	// 커서를 파일의 끝으로 이동
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);		// 현재 커서의 위치 --> 파일 끝 커서 위치 == 파일 크기
	if (size <= 0)
	{
		printf("저장된 데이터가 없습니다.\n");
		return 0;
	}


	if (fp) // fp가 NULL이 아니면
	{
		fclose(fp);
		fp = NULL;

	}

	return size;

}



void save_score(const SCORE* score)
{
	if (!score) // score == NULL
	{
		printf("score가 NULL입니다.\n");
		return;
	}
	// 파일 핸들 변수 초기화
	FILE* fp = NULL;

	fp = fopen(FILENAME, "wb");	// wb: binary 파일 write(저장)
	if (!fp)
	{
		printf("파일을 열 수 없습니다.\n");
		return; 
	}

	fwrite(score, sizeof(SCORE), 1, fp);	// 저장; 저장 대상, struct 크기, 개수, 파일

	if (fp) // fp가 NULL이 아니면
	{
		fclose(fp);
		fp = NULL;

	}
}

SCORE* load_score()		// 반환값 있음
{
	long size = get_file_size(FILENAME);

	// 파일 핸들 변수 초기화
	FILE* fp = NULL;

	fp = fopen(FILENAME, "rb");	// wb: binary 파일 read(읽기)
	if (!fp)
	{
		printf("파일을 열 수 없습니다.\n");
		return NULL;
	}

	// 동적 메모리 할당
	SCORE* score = (SCORE*)malloc(size);
	if (!score)
	{
		printf("메모리 할당 실패\n");
		if (fp)
		{
			fclose(fp);
			fp = NULL;

		}
		return NULL;
	}

	fread(score, size, 1, fp);

	if (fp) // fp가 NULL이 아니면
	{
		fclose(fp);
		fp = NULL;

	}
	return score;
}
