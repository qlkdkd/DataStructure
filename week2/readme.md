# 2. 순환
## 순환(recursion)이란?
* 알고리즘이나 함수가 수행 도중에 자기 자신을 다시 호출하여 문제를 해결하는 기법
* 정의 자체가 순환적으로 되어 있는 경우에 적합한 방법

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/bfdf5df2-e4a7-4a32-90e8-2e2f5d72f693)

---

## 팩토리얼 프로그래밍 #1
* 순환의 예: 팩토리얼
* 팩토리얼의 정의

$$n!=\left\{\begin{matrix}
1(n=0)\\
n*(n-1)! \\
\end{matrix}\right.$$

즉 위의 정의에서 팩토리얼 $n!$을 정의하는데 다시 팩토리얼$(n-1)!$이 사용되었다. 이러한 정의를 순환적이라 한다. 위의 정의에 따라 $n!$을 구하는 함수 `factorial(n)`을 제작하여 보자.

## 팩토리얼 프로그래밍 1
```c
int factorial1(int n)
{
	if (n <= 1) return 1;
	else return(n * factorial1(n - 1));
}
```
그런데 여기서 하나의 아이디어는 현재 우리가 제작하고 있는 함수가 n을 매개변수로 받아서 $n!$을 구하는 함수라는 점이다. 따라서 매개변수 (n-1)만 변경하여주면 $(n-1)!$값을 계산할 수 있으리라는 것이다. 위의 아이디어에 따라 팩토리얼을 구하는 함수를 다시 만들면 다음과 같다.

## 팩토리얼 프로그래밍2
```c
int factorial2(int n)
{
	if (n <= 1)return(1);
	else return (n * factorial2(n - 1));
}
```

## 순환 호출순서
만약 우리가 `factorial(3)`을 호출하였을 경우에 위의 프로그램에서 함수가 호출되는 순서를 자세히 살펴보자. 다음 코드에서 보듯이 `factorial(3)`을 수행하는 도중에 `factorial(2)`를 호출하게 된다.
```c
int factorial(3){
    if(3>=1)return 1;
    else return(3*factorial(3-1);
}
```

`factorial(3)`을 수행하는 도중에 `factorial(2)`를 호출하게 되고 `factorial(2)`는 다시 `factorial(1)`을 호출하게 된다.
```c
int factorial(2){
    if(2>=1) return 1;
    else return (2*factorial(2-1));
}
```

`factorial(1)`은 매개변수 n이 1이므로 첫 번째 if 문장이 참이 되고, 따라서 더 이상의 순환 호출 없이 1을 반환하게 된다.
```c
int factorial(1){
    if(1>=1)return 1;
    ...
}
```

이 반환값 1은 `factorial(2)`로 전달되고, `factorial(2)`는 여기에 2를 곱한 값인 2를 factorial(3)으로 전달한다. factorial(3)은 이 값에 3을 곱하여 6을 반환한다. 다시 이 과정을 한 번에 살펴보면 다음과 같다.
```
factorial(3)=3*factorial(2)
=3*2*factorial(1)
=3*2*1
=6
```

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/278cc050-c7b3-40f4-84e1-966540a97ab4)

순환 호출이 이루어지는 과정을 알기 위하여 다음과 같이 함수의 이름과 함수의 매개변수를 출력하는 factorial 함수의 처음에 넣어보자.

```c
int factorial(int n){
    printf("factorial(%d\n", n);
    if (n<=1) return 1;
    else return (n*factorial(n-1));
}
```
실행결과
```
factorial(3)
factorial(2)
factorial(1)
```
## 순환 알고리즘의 구조
순환을 이해하기 위하여 먼저 함수 호출의 과정을 살펴보자. 프로그래밍 언어에서 하나의 함수가 자기 자신을 다시 호출하는 것은 다른 함수를 호출하는 것과 동일하다. 즉 복귀주소가 시스템 스택에 저장되고 호출되는 함수를 위한 매개변수와 지역 변수를 스택으로부터 할당받는다. 이러한 함수를 위한 시스템 스택에서의 공간을 활성 레코드(activation record)라 한다. 이러한 준비가 끝나면 호출된 함수의 시작 위치로 점프하여 수행을 시작한다. 만약 호출된 함수가 자기 자신이라면 자기 자신의 시작 위치로 점프하게 되는 것이다. 호출된 함수가 끝나게 되면 시스템 스택에서 복귀 주소를 추출하여 호출한 함수로 되돌아가게 된다.

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/de67d02b-67dc-4888-bbae-b1393b0bb5c1)

순환 알고리즘은 위의 그림과 같이 자기 자신을 순환적으로 호출하는 부분과 순환 호출을 멈추는 부분으로 구성되어 있다. 만약 순환호출을 멈추는 부분이 없다면 시스템 스택을 다 사용할 때까지 순환적으로 호출되다가 결국 오류를 내면서 멈출 것이다.

## 순환<->반복
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/19d6a9c9-e908-4350-bcd3-84f91217972e)

반복이란 for이나 while 등 반복구조로 되풀이하는 방법이다. 반복을 제어하는 변수를 사용하여 일정 횟수동안 반복시킬 수도 있고 어떤 조건이 만족될 때까지 반복시킬수도 있다. 반복은 간명하고 효율적으로 되풀이를 구현하는 방법이다.

반면에 때로는 반복을 사용하게 되면 지나치게 복잡해지는 문제들도 존재한다. 이런 경우에는 순환이 좋은 해결책이 될 수 있다. 순환은 주어진 문제를 해결하기 위하여 자신을 다시 호출하여 작업을 수행하는 방식이다. 순환은 본질적으로 순환적인 문제나 그러한 자료구조를 다루는 프로그램에 적합하다.

## 팩토리얼의 반복적 구현
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/28161c88-2574-49b5-9f45-80a8eb9c8fc2)
```c
int factorial_iter(int n)
{
	int k, v = 1;
	for (k = n; k > 0; k--)
		v = v * k;
	return v;
}
```

---

## 거듭제곱값 프로그래밍
* 순환적인 방법이 더 효율적인 예제
* 숫자 x의 n제곱 값을 구하는 문제 $x^n$

## 반복적인 방법
```c
double slow_power(double x, int n)
{
	int i;
	double result = 1.0;
	for (i = 0; i < n; i++)
		result = result * x;
	return result;
```

## 순환적인 방법
```c
double power_iter(double x, int n)
{
	if (n == 0) return 1;
	else if (n % 2 == 0)
		return power_iter(x * x, n / 2);
	else return x * power_iter(x * x, (n - 1) / 2);
}
```

## 거듭제곱 값 프로그래밍 분석
$x^n=(x^2)^{n/2}$의 공식을 이용하여 n이 짝수인 경우에는 $x^2$를 먼저 계산한 후에 이 값을 $n/2$제곱하는 것이다. n이 홀수인 경우에는 $x^2$를 $(n-1)/2$제곱하고 여기에 $x$를 곱해주면 된다.
```
//x가 짝수일 때
if (n%2==0){
	power(x^2, n/2);
}
//x가 홀수일 때
else if(n%2!+0){
	x*power(x^2, (n-1)/2);
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/2ee2c71b-28eb-4dd0-aa78-2b01419eb4bd)

---

## 피보나치 수열의 계산

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/6d3722a1-64e8-40cf-b680-757b57d339bf)

```c
//피보나치 수열의 계산1(비효율적인 예)
int fib(int n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;
	return (fib(n - 1) + fib(n - 2));
}
```
위의 함수는 매우 단순하고 이해하기 쉽지만 매우 비효율적이다. 왜 그럴까? 예를 들어 아래 그림처럼 fib(6)으로 호출하였을 경우 fib(4)가 2번이나 계산되기 때문이다. fib(3)은 3번 계산되고 이런 현상은 순환호출이 깊어질수록 점점 심해진다. 따라서 상당히 비효율적임을 알 수 있다.

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/9b673d73-2a6b-45db-afa5-a1b6caf19b75)

## 피보나치 수열의 반복 구현
그렇다면 피보나치 수열을 계산하는데 다른 방법이 있을까? 이 경우에는 순환을 사용하지 않고 반복구조를 이용하여 프로그램하면 제일 좋은 결과를 얻을 수 있따. 아래 프로그램에서 반복을 사용한 피보나치 수열 계산 프로그램을 나타냈다.

```c
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
```

---

## 하노이 탑 문제
순환의 파워를 가장 극명하게 보여주는 예제가 바로 이 절에 다룰 하노이 탑 문제이다. 하노이 탑 문제는 다음과 같다.
* 문제는 막대 A에 쌓여있는 원판 n개를 막대 C로 옮기는 것이다.
	* 한 번에 하나의 원판만 이동할 수 있다.
	* 맨 위에 있는 원판만 이동할 수 있다.
   	* 크기가 작은 원판 위에는 큰 원판이 쌓알 수 없다.
   	* 중간의 막대를 임시적으로 이용할 수 있으나 앞의 조건들을 지켜야 한다.
 
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/39ccb6f2-fb68-4082-a7ea-808709634ba1)
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/0d536077-13f2-427a-a968-ed64a6b0d65e)
## 남아있는 문제는?
* 자, 그러면 어떻게 n-1개의 원판을 A에서 B로, B에서 C로 이동하는가?
* **(힌트) 우리의 원래 문제가 n개의 원판을 A에서 C로 옮기는 것임을 기억하라.**
* ->따라서 지금 작성하고 있는 함수의 매개변수를 n-1로 바꾸어 순환 호출하면 된다.

```
//막대 from에 쌓여있는 n개의 원판을 막대 tmp를 사용하여 막대 to로 옮긴다.
void hanoi_tower(int n, char from, char tmp, char to){
	if (n==1){
		from에서 to로 원판을 옮긴다.
	{
	else{
		hanoi_tower(n-1, from, to, tmp);
		from에 있는 한 개의 원판을 to로 옮긴다.
		hanoi_tower(n-1, tmp,from, to);
	}
}
```

## 하노이탑 최종 프로그램
```c
#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1)printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c로 옮긴다.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}

}

int main()
{
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}
```
## 실행 결과
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/3f6ab0d7-7fc3-4655-8f7c-e1f6b20b8ab9)
