#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//팩토리얼 프로그래밍1
int factorial1(int n)
{
	if (n <= 1) return 1;
	else return(n * factorial1(n - 1));
}


//팩토리얼 프로그래밍2
int factorial2(int n)
{
	if (n <= 1)return(1);
	else return (n * factorial2(n - 1));
}


//팩토리얼의 반복적 구현
int factorial_iter(int n)
{
	int k, v = 1;
	for (k = n; k > 0; k--)
		v = v * k;
	return v;
}


//거듭제곱값 프로그래밍(x^n)
double slow_power(double x, int n)
{
	int i;
	double result = 1.0;
	for (i = 0; i < n; i++)
		result = result * x;
	return result;
}

//거듭제곱값 순환
double power_iter(double x, int n)
{
	if (n == 0) return 1;
	else if (n % 2 == 0)
		return power_iter(x * x, n / 2);
	else return x * power_iter(x * x, (n - 1) / 2);
}


//피보나치 수열의 계산1(비효율적인 예)
int fib(int n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;
	return (fib(n - 1) + fib(n - 2));
}


//피보나치 수열의 계산(반복구현)
int fib_iter(int n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;

	int pp = 0;//이전의 이전거
	int p = 1;//이전거
	int result = 0;

	for (int i = 2; i <= n; i++)
	{
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}


int main()
{
	int num, num3;
	double num2;
	printf("숫자1 입력: ");
	scanf("%d", &num);
	printf("숫자 2 입력: ");
	scanf("%lf", &num2);
	printf("숫자3 입력: ");
	scanf("%d", &num3);

	printf("팩토리얼1: %d\n", factorial1(num));
	printf("팩토리얼2: %d\n", factorial2(num));
	printf("팩토리얼_iter: %d\n", factorial_iter(num));
	printf("%lf의 %d제곱(slow_power): %lf\n", num2, num3, slow_power(num2, num3));
	printf("%lf의 %d제곱(power_iter): %lf\n", num2, num3, power_iter(num2, num3));
	printf("%d의 피보나치 수열: %d\n", num, fib(num));
	printf("%d의 피보나치 수열(반복구현): %d\n", num, fib_iter(num));
	return 0;
}