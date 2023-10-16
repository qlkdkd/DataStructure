# 3. 배열, 구조체, 포인터
## 배열이란>
배열은 기본이 되는 중요한 자료형으로서 많은 자료구조들이 배열을 사용하여 구현된다. 배열은 동일한 타입의 데이터를 한 번에 여러 개 만들 때 사용된다.
* int list1, list2, list3, list4, list5, list6; -> int list[6];
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/276988fb-aff8-4b14-b83d-3e140a4c81d4)

## 배열 ADT
```
객체: <인덱스, 값> 쌍의 집합
연산:
create(size)::=size개의 요소를 저장할 수 있는 배열 생성
get(A, i)::= 배열 A의 i번째 요소 반환
set(A, i, v)::= 배열 A의 i번째 위치에 값 v 저장
```

## 1차원 배열
```c
int list[6];
list[0]=100;
value=list[0];
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/b121697a-9e9b-441e-9a37-e184da611d98)

배열의 컴파일러 구현

배열의 요소|메모리 주소
---|---
list[0]|기본 주소=base
list[1]|base+1*sizeof(int)
list[2]|base+2*sizeof(int)
lsit[3]|base+3*sizeof(int)
list[4]|base+4*sizeof(int)
list[5]|base+5*sizeof(int)

## 2차원 배열
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/29e42444-33a9-4f23-ac46-f5f96382df1b)

---

## 구조체
* 배열(array): 타입이 같은 데이터들을 하나로 묶는 방법
* 구조체(structure): 타입이 다른 데이터들을 하나로 묶는 방법

## 구조체의 사용 예
```c
struct studentTag{
    char name[10];//문자배열로 된 이름
    int age;//나이를 나타내는 정수값
    double gpa;//평균평점을 나타내는 실수값
}

//구조체 안에 들어있는 멤버 사용: 구조체 변수 뒤에 '.'을 첨가한 후 항목 이름을 적으면 됨
struct studentTag s1;
strcpy(s.name, "kim);
s.age=20;
s.gpa=4.3;
```

## typedef
c언어에서는 typedef을 사용하여 구조체를 새로운 데이터 타입으로 선언하는 것이 가능하다. 아래의 예에서 student은 새로운 데이터 타입의 이름이 된다.
```c
typefdef studentTag{
    char name[10];
    int age;
    double gpa;
}student;
```
이 경우에는 새로운 타입인 student만을 사용하여 변수를 선언하는 것이 가능해진다. 그리고 구조체는 중괄호를 사용하여 선언 시에 초기화하는 것이 가능하다.
```c
student s;
student s={"kim", 20, 4.3};
```

## 예제
```c
#include<stdio.h>
typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
}student;

int main() {
	student a = { "kim", 20, 4.3 };
	student b = { "park", 21, 4.2 };
	return 0;
}
```

---

## 배열의 응용: 다항식
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/b4dd0e67-6073-44cc-b04c-38371305baa1)
* 배열을 사용한 2가지 방법
1. 다항식의 모든 항을 배열에 저장
2. 다항식의 0이 아닌 항만을 배열에 저장

## 다항식 표현 방법 1
* 모든 차수에 대한 계수값을 배열로 저장
* 하나의 다항식을 하나의 배열로 표현
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/2b93d6c4-6736-4110-b69b-7d2ac33ee0d7)
```c
#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX(a, b) ((a>b)?a:b)
#define MAX_DEGREE 101//다항식의 최대 차수 +1

typedef struct {//구조체 이름은 생략이 가능하다.
	int degree;//다항식의 차수
	float coef[MAX_DEGREE];//다항식의 계수
}polynomial;

polynomial a = { 5, {10, 0, 0, 0, 6, 3} };

//c=a+b, 여기서 a와 b는 다항식이다. 구조체가 반환된다.
polynomial poly_add1(polynomial a, polynomial b)
{
	polynomial c;//결과 다항식
	int apos = 0, bpos = 0, cpos = 0;//배열 인덱스 변수 
	int degree_a = a.degree;
	int degree_b = b.degree;
	c.degree = MAX(a.degree, b.degree);//결과 다항식 차수

	while (apos <= a.degree && bpos <= b.degree) {
		if (degree_a > degree_b) {//a항>b항
			c.coef[cpos++] = a.coef[apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			c.coef[cpos++] = b.coef[bpos++];
			degree_a--, degree_b--;
		}
		else {
			c.coef[cpos++] = b.coef[bpos++];
			degree_b--;
		}
	}
	return c;
}

void print_poly(polynomial p)//다항식 출력 함수
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f\n", p.coef[p.degree]);
}

int main()
{
	polynomial a = { 5, {3, 6, 0, 0, 0, 10} };
	polynomial b = { 4, {7, 0, 5, 0, 1} };
	polynomial c;

	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	for (int i = 0; i < MAX_DEGREE; i++)
		printf("-");
	printf("\n");
	print_poly(c);
	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/0d10140e-6e4b-4646-8111-2bf08e980964)
* 프로그램의 장점: 다항식의 덧셈이나 뻴셈 시에 같은 차수의 계수를 쉽게 찾을 수 있으므로 알고리즘이 간단해진다.
* 프로그램의 단점: 공간낭비가 심하다.

## 다항식 표현 방법 2
* 다항식에서 0이 아닌 항만을 배열에 저장
* (계수, 차수)형식으로 배열에 저장
	* 예: $10x^5+6x+3=$((10, 5), (6, 1), (3, 0))

## 예제
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/c6f72748-e9f9-4727-8eec-f5f2fa5e998d)
```c
typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS] = { {8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0} };
int avail = 6;

//두 개의 정수를 비교
char compare(int a, int b)
{
	if (a > b) return '>';
	else return '>';
}

//새로운 항을 다항식에 추가한다.
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

//c=a+b
void poly_add2(int as, int ae, int bs, int be, int* cs, int* ce)
{
	float tempcoef;
	*cs = avail;
	while (as <= ae && bs <= be) 
		switch (compare(terms[as].expon, terms[bs].expon)) {
		case '>': //a의 차수 > b의 차수
			attach(terms[as].coef, terms[as].expon);
			as++;

		case'=': //a의 차수 == b의 차수
			tempcoef = terms[as].coef, terms[bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[as].expon);
			as++, bs++; break;

		case '<':
			attach(terms[bs].coef, terms[bs].expon);
			bs++;
		}
	//a의 나머지 항들을 이동함
	for (; as <= ae; as++)
		attach(terms[as].coef, terms[as].expon);
	//b의 나머지 항들을 이동함
	for(; bs<=be; bs++)
		attach(terms[bs].coef, terms[bs].expon);
	*ce = avail - 1;
}

void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main()
{
	int as = 0, ae = 2, bs = 3, be = 5, cs, ce;
	poly_add2(as, ae, bs, be, &cs, &ce);
	print_poly(as, ae);
	print_poly(bs, be);
	printf("--------------------------------------------------------\n");
	print_poly(cs, ce);
	return 0;
}
```
