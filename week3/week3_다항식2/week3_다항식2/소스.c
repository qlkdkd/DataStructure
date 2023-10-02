/*
다항식 표현방법 2
	- 다항식에서 0이 아닌 항만을 배열에 저장
	- (계수, 차수)형식으로 배열에 저장
		- 예: 10x^5+6x+3=((10, 5), (5,1), (3,0))
	- a = 8x^3 + 7x + 1, b = 10x^3 + 3x^2 + 1
*/

#define _CRT_NO_WARINIGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_TERMS 101

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