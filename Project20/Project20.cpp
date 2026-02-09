# include <stdio.h>

int main()
{
	/*다차원 배열
	2차원 이상의 배열을 의미하며 1차원 배열의 형태가 선형적이라고 할 때 2차원 배열은 평면, 3차원 배열은 직육면체 구조.그 이상 차원의 배열도 가능
	배열 선언
	자료형 배열명[길이]: 1차원
	자료형 배열명[행>][열V]: 2차원
	*/ 

	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	// 배열 요소 출력
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	// 배열 요소 변경
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++) {
			arr[i][j] = 10;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}

