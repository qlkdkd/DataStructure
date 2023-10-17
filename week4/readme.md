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

## 희소 행렬 표현 방법2
* 0이 아닌 요소들만 저장하는 방법
* 장점: 희소 행렬의 경우 메모리 공간의 절약
* 단점: 각종 행렬 연산들의 구현이 복잡해짐

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/879c843b-da72-41f8-90fc-011babe18b19)

```c
//희소행렬 표현 방법2: 0이 아닌 요소들만 저장하는 방법
#include<stdio.h>
#include<stdlib.h>

#define MAX_TERMS 100

typedef struct {
	int row;
	int col;
	int value;
}element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows; //행의 개수
	int cols; //열의 개수
	int terms; //항의 개수
}SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a) {
	SparseMatrix b;

	int bindex;
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;

	if (a.terms > 0) {
		bindex = 0;
		for (int c = 0; c < a.cols; c++) {
			for (int i = 0; i < a.terms; i++) {
				if (a.data[i].col == c) {
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a)
{
	printf("==============================\n");
	for (int i = 0; i < a.terms; i++) {
		printf("(%d %d %d)\n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("==============================\n");
}

int main()
{
	SparseMatrix m = {
	{
		{0, 3, 7},
		{1, 0, 9},
		{1, 5, 8},q
		{3, 0, 6},
		{3, 1, 5},
		{4, 5, 1},
		{5, 2, 2}
	},
	6, 6, 7 };
	SparseMatrix result;

	result = matrix_transpose2(m);
	matrix_print(result);
	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/ec7117f3-240a-4c78-9f11-cd3810d5419f)

---

## 포인터
포인터: 다른 변수의 주소를 가지고 있는 변수. 모든 변수는 메모리 공간에 저장되고 메모리의 각 바이트에는 주소가 매겨져 있다. 이 주소가 포인터에 저장된다. 주소는 컴퓨터에 따라 다를 수 있으므로 포인터 변수는 대개 정확한 숫자보다는 그냥 화살표로 그려진다.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/5bf8b64b-54bd-4caa-8ac9-5239efd4a389)

위 그림에서는 p는 a라는 변수를 가리키는 포인터 변수이다. 위 그림에 해당하는 c언어 문장은 다음과 같다.
```c
char a='A';
char *p;
p=&a;
```

만약 포인터가 가리키는 내용을 변경하고 싶으면 '*' 연산자를 이용하면 된다.
```c
*p='B';
```

## 포인터 관련 연산자
* &: 변수의 주소를 추출
* *: 포인터가 가리키는 곳의 내용을 추출

## 다양한 포인터
* 포인터의 종류
```c
int *p;//p는 int형 변수를 가리키는 포인터
float *pf;//pf는 float형 변수를 가리키는 포인터
char *pc;//pc는 char형 변수를 가리키는 포인터
```
## 함수의 매개변수로 포인터 사용하기
* 함수 안에서 매개변수로 전달된 포인터를 이용하여 외부 변수의 값 변경 가능
```c
#include<stdio.h>
void swap(int* px, int* py)
{
	int tmp; 
	tmp = *px;
	*px = *py;
	*py = tmp;
}

int main()
{
	int a = 1, b = 2;
	printf("swap을 호출하기 전: a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("swap을 호출한 다음: a=%d, b=%d\n", a, b);
	return 0;
}
```

## 배열과 포인터
* 배열의 이름=배열의 시작부분을 가리키는 포인터

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/c257193d-b8fc-4847-a5ef-63804b117c47)

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 6

void get_integer(int list[])
{
	printf("6개의 정수를 입력하시오: ");
	for (int i = 0; i < SIZE; ++i) {
		scanf("%d", &list[i]);
	}
}

int cal_sum(int list[]) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += *(list + i);
	}
	return sum;
}

int main()
{
	int list[SIZE];
	get_integer(list);
	printf("합: %d\n", cal_sum(list));

	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/3d253769-48ab-48b3-9b1d-ee0c689f01f5)

---

## 동적 메모리 할당
기존 배열은 이 고정된 크디 때문에 많은 문제가 발생한다. 흔히 프로그램을 작성할 당시에는 얼마나 많은 입력이 있을지를 알 수 없기 때문이다. 만약 처음에 결정된 크기보다 더 큰 입력이 들어온다면 처리하지 못할 것이고, 더 작은 입력이 들어온다면 남은 메모리 공간은 낭비될 것이다.

따라서 이러한 문제들을 해결하기 위하여 c언어에서는 필요한 만큼의 메모리를 운영체제로부터 할당받아서 사용하고, 사용이 끝나면 시스템에 메모리를 반납하는 기능이 있다. 이를 동적 메모리 할당이라고 한다.

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/1893e053-159b-4d8b-ad84-409b72d9252b)

## 전형적인 동적 메모리 할당 코드
```
int main(){
	int *pi;
	pi=(int*)malloc(sizeof(int));//동적 메모리 할당
	...//동적 메모리 사용
	free(pi);//동적 메모리 반납
	return 0;
}
```

## 동적 메모리 할당 예제
```c
/*MALLOC.C: malloc을 이용하여 정수 10을 저장할 수 있는 동적 메모리를
할당하고 free를 이용하여 메모리를 반납한다.*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define SIZE 10

int main() {
	int* p;
	p = (int*)malloc(SIZE * sizeof(int));
	if (p == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)
		p[i] = i;
	for (int i = 0; i < SIZE; i++)
		printf("%d ", p[i]);

	free(p);
	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/a7ec49ed-14a1-467d-b53b-40df4887c36e)

## 구조체와 포인터
* (*ps).i 보다 ps->i

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
}student;

int main() {
	student* s;
	s = (student*)malloc(sizeof(student));
	if (s == NULL) {
		fprintf(stderr, "메모리 부족\n");
		exit(1);
	}
	strcpy(s->name, "Park");
	s->age = 20;
	s->gpa = 4.0;
	
	free(s);
	return 0;
}
```
