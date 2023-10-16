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
