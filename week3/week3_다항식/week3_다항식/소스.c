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