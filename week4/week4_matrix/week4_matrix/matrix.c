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
