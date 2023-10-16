## 희소행렬
* 배열을 이용하여 행렬(matrix)를 표현하는 2가지 방법
1. 2차원 배열을 이용하여 배열의 전체 요소를 저장하는 방법
2. 0이 아닌 요소들만 저장하는 방법
* 희소 행렬: 대부분의 항들이 0인 배열
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/4e19c489-f4d2-4ba7-ad2c-22bade58fa43)

## 행렬 표현 방법 1
* 2차원 배열을 이용하여 배열의 전체 요소를 저장하는 방벙
* 장점: 행렬의 연산을 간단하게 구현할 수 있다.
* 단점: 대부분의 항들이 0인 희소 행렬인 경우 많은 메모리 공간 낭비
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/b990f490-2700-47e5-996a-94e89e9ec3a0)
## 행렬 전치 1
행렬의 전치 행렬을 계산하려면 a[i][j]를 a[j][i]로 바꾸면 된다.

```c
#include<stdio.h>
#define rows 3
#define cols 3

//행렬 전치 함수
void matrix_transpose(int A[rows][cols], int B[rows][cols]) {
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
			B[c][r] = A[r][c];
}

void matrix_print(int A[rows][cols]) {
	printf("=============\n");
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++)
			printf("%d ", A[r][c]);
		printf("\n");
	}
	printf("==============\n");
}

int main()
{
	int array1[rows][cols] =
	{ {2, 3, 0},
	  {8, 9, 1},
	  {7, 0, 5}
	};
	int array2[rows][cols];
	matrix_transpose(array1, array2);
	matrix_print(array1);
	matrix_print(array2);

	return 0;
}

```
