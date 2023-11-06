# 13. 동적 메모리

## 동적 메모리의 개념
* 프로그램이 메모리를 할당받는 방법
    * 정적(stacic)
    * 동적(dynamic)
 

## 정적 메모리 할당
* 프로그램이 시작되기 전에 미리 정해진 크기의 메모리를 할당받는 것
* 메모리의 크기는 프로그램이 시작하기 전에 결정되며 프로그램의 실행 도중에 그 크기가 변경될 수는 없다.
```c
int sarray[10];
```
* 정적 메모리는 간편하지만 경우에 따라 비효율적
    * 예) 프로그램이 처리해야하는 입력의 크기를 미리 알 수 없음
        * 처음에 결정된 크기보다 더 큰 입력이 들어온다면 처리하지 못하고, 더 작은 입력이 들어온다면 남은 메모리 공간은 낭비됨
     

## 동적 메모리 할당
* 프로그램이 실행 도중에 메모리를 할당받는 것
```c
int *darray=malloc(10*sizeof(int));
```
* 위의 문장에서는 10개의 정수를 저장할 수 있는 공간을 동적으로 할당받고 있음
* 동적 메모리 할당에서는 필요한 만큼의 메모리를 시스템으로부터 할당받아서 사용하고, 사용이 끝나면 시스템에 메모리를 반납함
* 필요한 만큼만 할당받고 또 필요한 때에 사용하고 반납하기 때문에 메모리를 매우 효율적으로 사용할 수 있음
* 동적 메모리는 malloc()계열의 라이브러리 함수를 사용하여 할당받을 수 있음
* 프로그램이 수행되다가 malloc()함수를 만나면 운영 체제가 호출되어서 필요한 만큼의 동적 메모리를 할당하게 됨

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/af84406d-2ab3-4fb2-a92d-fca58f77519a)

## 동적 메모리 할당 절차
* 먼저 얼마나 할당을 받을 것인지를 결정하고 라이브러리 함수를 호출하여 운영 체제에게 메모리를 요청하는 단계가 필요하다.
* 만약 충분한 메모리가 존재하면 그 요청은 승인되고 메모리가 할당된다.
* 프로그램은 할당된 메모리를 사용한다.
* 사용이 끝나면 메모리를 다시 운영체제에게 반납하는 단계가 필요하다.
    * 만약 메모리를 반납하지 않으면 다른 프로그램이 동적 메모리를 사용할 수 없게 된다. 따라서 반드시 동적 메모리는 명시적으로 반납을 해주어야 한다.


## malloc()
* 동적 메모리를 할당하는 가장 기본적인 함수인 malloc()은 헤더파일 <stdlib.h>에 원형이 정의되어 있으며 바이트 단위로 메모리를 할당한다.

```c
#include<stdio.h>
#include<stdlib.h>
//형식
void *malloc(size_t size);//size_t는 부호 없는 정수 타입이다.

//예시
char *p;
p=(char*)malloc(100);
```

* malloc()함수는 요청된 크기만큼의 메모리 공간을 찾아서 메모리의 주소를 반환한다. 단위는 바이트이다.
   * malloc(100)이라고 하면 100바이트의 공간을 요청하는 것이다.
* 만약 요청한  메모리 공간을 할당할 수 없는 경우에는 NULL값을 반환하다.
* 여기서 반환하는 것은 프로그래머가 메모리 공간을 어떤 자료형으로 사용할지 알 수 없기 때문이다.
* void 포인터는 다른 자료형의 포인터로 변경이 가능하다.
* 따라서 프로그래머는 자신이 사용하고자하는 자료형의 포인터로 형변환하여 사용해야 한다.

### 동적 메모리 사용
* 동적 메모리 공간은 이름이 없다.
   * 동적 메모리 공간은 오직 포인터를 사용하여 사용할 수 있따.
* 반환된 포인터를 통하여 메모리 블록에 데이터를 쓰고 읽을 수 있다.
```c
*p='a';
```
* 위 문장을 수행하면 동적으로 할당된 공간에 문자 'a'가 저장된다.


## free()
* free()는 동적으로 할당되었던 메모리 블록을 시스템에 반납한다.
* 다음과 같은 함수 원형을 가지며 여기서 ptr은 malloc()이나 calloc()을 이용하여 동적 할당된 메모리를 가리키는 포인터이다.
```c
//형식
void free(void *ptr)

//예
#include <stdio.h>
#include<stdlib.h>

char *p;
p=(char*)malloc(1000;
...
free(p);
```

* 컴퓨터 시스템에서 동적으로 할당 가능한 메모리는 제한되어 있다. 따라서 할당받은 메모리의 사용이 끝났을 경우에는 반드시 메모리를 다른 프로그램이 사용할 수 있도록 반납하여야 한다.
* free()를 호출할 때는 할당된 메모리를 가리키는 포인터를 인수로 하여 호출하여야 한다. 따라서 malloc()이 반환한 포인터는 절대 잊어버리면 안된다.

## 예제 1
```c
#include<stdio.h>
#include<stdlib.h>

int main() {
	char* pc;
	pc=(char*)malloc(1 * sizeof(char));

	if (pc == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}

	*pc = 'a';
	printf("%c\n", *pc);
	free(pc);

	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f132298a-29ed-4248-8a00-3eea0217cb4d)

## 예제2
5개의 정수를 저장할 수 있는 동적 메모리 공간을 할당받고 여기에 1, 2, 3, 4, 5까지의 정수를 저장해보자.
```c
#include<stdio.h>
#include<stdlib.h>

void printarray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

int main() {
	int* pi;
	pi = (int*)malloc(5 * sizeof(int));

	if (pi == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}

	*pi = 1;
	*(pi + 1) = 2;
	*(pi + 2) = 3;
	*(pi + 3) = 4;
	*(pi + 4) = 5;

	printarray(pi, 5);
	free(pi);
	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/3059560a-0103-4d9b-b6a6-9f74bd64aee9)

---

## lab: 사용자가 입력하는 크기의 배열 만들기
```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int* p;
	int i, items;

	printf("항목 개수 입력: ");
	scanf("%d", &items);
	p = (int*)malloc(sizeof(int) * items);

	for (i = 0; i < items; i++) {
		printf("항목 입력: ");
		scanf("%d", &p[i]);
	}

	printf("입력된 항목들\n");
	for (i = 0; i < items; i++)
		printf("%d ", p[i]);
	printf("\n");
	free(p);

	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/226e4810-204e-4b54-9f65-c1053952371c)

## 구조체 동적 생성
* 구조체를 저장할 수 있는 공간도 다음과 같이 할당받을 수 있음.
* 만약 구조체의 배열이 필요하면 구조체의 크기에다 필요한 개수를 곱해주면 됨.
```c
struct Book{
   int number;
   char title[100];
}Book;

Book *p;
p=(Book*)malloc(2*sizeof(Book));
```

### 예제
```c
#include<stdio.h>
#include<stdlib.h>

struct Book {
	int number;
	char title[100];
};

int main() {
	struct Book* p;
	p = (struct Book*)malloc(2 * sizeof(struct Book));

	if (p == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}

	p[0].number = 1;
	strcpy(p[0].title, "Data Structure");

	p[1].number = 2;
	strcpy(p[1].title, "C Programming");

	for (int i = 0; i < 2; i++) {
		printf("%d, %s\n", p[i].number, p[i].title);
	}

	free(p);
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/59c492d2-8cc3-46a9-a0fd-6908c90d3469)

---

## 예제: 동적 배열 난수로 채우기
```c
#include<stdio.h>
#include<stdlib.h>
#define size 100

int main() {
	int* p = NULL;
	int i = 0;

	p = (int*)malloc(sizeof(int) * size);

	if (p == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}

	for (i = 0; i < size; i++) {
		p[i] = rand();
	}

	int max = p[0];
	for (i = 0; i < size; i++) {
		if (p[i] > max)
			max = p[i];
	}

	printf("최댓값: %d\n", max);
	free(p);

	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/4f36667e-3fe1-4fc0-97f0-ad9bb0241f65)

## lab: 동적 구조체 배열
```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//영화를 구조체로 표현
struct movie {
	char title[100];//영화 제목
	double rating;//영화 평점
};

int main() {
	struct movie* ptr;
	int i, n;
	printf("영화의 개수: ");
	scanf("%d", &n);
	getchar();//줄바꿈 문자 제거

	ptr = (struct movie*)malloc(n * sizeof(struct movie));

	if (ptr == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}

	for (i = 0; i < n; i++) {
		printf("영화 제목: ");
		gets_s(ptr[i].title, 100);//중간에 공백이 있는 제목도 받을 수 있어야 한다.
		printf("영화 평점: ");
		scanf("%lf", &ptr[i].rating);
	}

	printf("======================\n");
	for (i = 0; i < n; i++) {
		printf("영화제목: %s\n", ptr[i].title);
		printf("영화 평점: %lf\n", ptr[i].rating);
	}
	printf("=====================\n");

	free(ptr);
	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/d076187a-2a83-4d1a-a19a-f4e145b80885)
