# 포인터
### 포인터란?
* 포인터(pointer): 주소를 가지고 있는 변수. 포인터는 변수가 저장되는 주소와 깊은 관계 있음

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/4ac61cc3-bb07-450a-924b-9a6b75f135a0)


### 메모리의 구조
* 변수는 메모리에 저장된다.
* 메모리는 바이트 단위로 엑세스되고 각 바이트마다 고유한 주소를 가지고 있다.
* 컴퓨터가 20바이트 크기의 메모리를 가지고 있다면, 첫번째 바이트의 주소는 0, 두번째 바이트는 1, ..., 마지막 바이트는 19

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/8c327d08-bc90-40bf-a086-12478f23dbb9)

### 변수와 메모리
* 프로그램에서 변수를 만들면 이들 변수는 컴파일러에 의하여 메모리 공간에 배치됨.
* 변수의 크기에 따라서 차지하는 메모리 공간이 달라진다.
* `char`형 변수: `1`바이트, `int`, `float`형 변수: `4`바이트,...

```c
int main(){
  int i=10;
  char c=69;
  float f=12.3;
  return 0;
}
```
* 위와 같이 변수들을 생성하면 메모리상에는 다음과 같이 변수들이 배치될 수 있음
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/e3d801ef-ffaf-4ac8-8540-b157c1dd6a54)

### 변수의 주소
* 변수의 주소를 계산하는 연산자: `&`
* 주소 연산자 &는 변수의 이름을 받아서 변수의 주소를 반환함.
* 예를 들어 int i;라고 변수를 정의했으면 변수 i의 주소는 &i하면 알 수 있
* 주소를 출력하는 형식 지정자는 "%p"로서 16진수로 주소를 출력한다.
  ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f3e41be2-e699-4216-8e1c-bfbb6ca5e3f9)
[코드 보기](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%EB%B3%80%EC%88%98%EC%9D%98%20%EC%A3%BC%EC%86%8C/%EB%B3%80%EC%88%98%EC%9D%98%20%EC%A3%BC%EC%86%8C/FileName.c)
```c
#include<stdio.h>

int main() {
	int i = 10;
	char c = 69;
	float f = 12.3;

	printf("i의 주소: %p\n", &i);
	printf("c의 주소: %p\n", &c);
	printf("f의 주소: %p\n", &f);
	return 0;
}
```

---

### 포인터의 선언
* 포인터: 변수의 주소를 가지고 있는 변수
* 포인터가 저장하고 있는것은 값이 아니라 변수의 주소이다.
* 정수를 가리키는 포인터: int *p;

* p는 정수를 가리키는 포인터임. 포인터도 변수
* 포인터도 사용하기 전에 선언되어야 함.
* 포인터를 선언하려면 포인터가 가리키는 자료형을 쓰고 *를 붙인 다음, 변수의 이름을 쓴다.

  ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/120fef2a-ce6c-46a3-a90c-d283a1d9a707)

### 포인터와 변수의 연결

* 포인터는 사용하기 전에 반드시 초기화하여야 한다. 포인터에는 변수의 주소가 저장되어야 하므로 &연산자를 이용하여 변수의 주소를 계산하여 포인터에 대입하여 주면 된다.
```c
int number=10; //정수형 변수 number 선언
int *p; //포인터 변수 p 선언
p=&number; //변수 number 의 주소가 포인터 p로 대입
```
* p: 포인터
* 변수 number의 주소를 4라고 가정하고 p=&number의 연산을 실행하면 변수 number의 주소인 4가 p에 저장된다. 이와 같은 상황을 보통 "포인터 p가 변수 number을 가리킨다." 라고 표현한다
* 보통 p에서 number를 가리키는 화살표로 나타낸다
* 포인터는 지정된 자료형의 변수만을 가리킬 수 있다.

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/815b9900-941a-43ea-b988-38d003e389cf)

* 포인터 p가 변수 number를 가리킨다.

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/13e0693a-648a-4164-b0b7-f30a555ba320)

### 간접 참조 연산자
* 포인터 p가 가리키는 위치에 저장된 내용을 가져오려면 p 앞에 *기호를 붙여서 *p하면 된다. 이것을 포인를 통하여 간접 참조(dereferencing, indirection)한다.
* 간접 참조 연산자 *: 포인터가 가리키는 값을 가져오는 연산자
* *는 단항 면산자로서 포인터가 가리키는 위치의 내용을 추출하는 간접 참조 연산자이다.
* *는 단항 연산자로서 괄호 다음으로 높은 우선 순위를 가진다.

```c
int i=10;
int *p;//p 간접 참조
p=&i;//p에 i의 주소 저장
printf("%d", *p);//p에 저장된 i의 주소를 참조하여 i에 저장된 값 출력
```

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/569ff796-a155-47f3-8130-8463f34f4a4e)

### 포인터 연산자
* 포인터에 관련된 연산자는 다음과 같은 2가지이다.
    #### 주소 연산자: &
    #### 간접 참조 연산자: *

## 예제 1
```c
#include<stdio.h>
int main() {
	int number = 10;
	int* p;
	p = &number;

	printf("변수 number의 주소: %u\n", &number);
	printf("포인터의 값: %u\n", p);
	printf("변수 number의 값: %d\n", number);
	printf("포인터가 가리키는 값: %d\n", *p);

	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/2b8eeac1-b532-437e-9ebe-4686d632deb5)

## 예제 2
```c
#include<stdio.h>

int main() {
	int number = 10;
	int* p;

	p = &number;
	printf("변수 number의 값: %d\n", number);

	*p = 20;
	printf("변수 number의 값: %d\n", number);
	
	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/886b3043-e8f1-4b8c-9d82-537b59901519)

---

## 포인터 연산
* 가능한 연산: 증가, 감소, 덧셈, 뻴셈 연산
* 증가 연산의 경우 증가되는 값은 포인터가 가리키는 객체의 크기
* 포인터의 증가는 일반 변수와는 약간 다르다. 가리키는 객체의 크기만큼 증가한다.
* 포인터에 증가 연산인 ++을 적용하였을 경우, 증가되는 값은 포인터가 가리키는 객체의 크기이다.char형에 ++을 적용하면 1바이트, int형에 ++을 적용하면 4바이트, double형에 ++을 적용하면 8바이트가 적용된다.

포인터 타입|++연산 후 증가되는 값
---|---
char|1
short|2
int|4
float|4
double|8

* 증가 연산 예제: [증가연산예제.c](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%EC%A6%9D%EA%B0%80%EC%97%B0%EC%82%B0%EC%98%88%EC%A0%9C/%EC%A6%9D%EA%B0%80%EC%97%B0%EC%82%B0%EC%98%88%EC%A0%9C/FileName.c)
```
#include<stdio.h>
int main() {
	char* pc;
	int* pi;
	double* pd;

	//절대주소 10000으로 설정
	pc = (char*)10000;
	pi = (int*)10000;
	pd = (double*)10000;
	printf("증가전 pc: %d, pi: %d, pd: %d\n", pc, pi, pd);

	//포인터 변수에 증감연산 적용용
	pc++;
	pi++;
	pd++;

	printf("증가 후 pc: %d, pi: %d, pd: %d\n", pc, pi, pd);

	return 0;
}
```

결과
```
증가전 pc: 10000, pi: 10000, pd: 10000
증가 후 pc: 10001, pi: 10004, pd: 10008 
```

---

### 포인터의 증감 연산
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f6fe9863-6785-4d7f-939b-f5f25b258968)

### 간접 참조 연산자와 증감 연산자
* *p++;
    * p가 가리키는 위치에서 값을 가져온 후에 p를 증가한다.
* (*p)++;
    * p가 가리키는 위치의 값을 증가한다.

 수식|의미
 ---|---
 v=*p++|p가 가리키는 값을 v에 대입한 후에 p를 증가한다.
 v=(*p)++|p가 가리키는 값을 v에 대입한 후에 가리키는 값을 증가한다.
 v=*++p|p를 증가시킨 후에 p가 가리키는 값을 v에 대입한다.
 v=++*p|p를 가리키는 값을 가져온 후에 그 값을 증가하여 v에 대입한다.

---

### 함수와 포인터
* 다른 사람에게 넘겨주어야 하는 정보가 상당히 방대하다고 하자. 이런 경우에는 전체를 복사해서 주는 것보다는 페이지 수만 알려주는 편이 간결할 수 있다.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/edea47bb-fa86-4e88-ad5b-e1dafbb1b6eb)

### 함수 호출 시 인수 전달 방법
* 값에 의한 호출(call-by-value): 함수가 호출될 때 복사본이 함수로 전달되는 호출이다. 함수 안에서 매개변수를 변경하여도 원본에는 영향을 받지 않는다.
* c의 기본적인 방법
[예](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%EA%B0%92%EC%97%90%20%EC%9D%98%ED%95%9C%20%ED%98%B8%EC%B6%9C/%EA%B0%92%EC%97%90%20%EC%9D%98%ED%95%9C%20%ED%98%B8%EC%B6%9C/FileName.c)
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/89c70169-8416-4cc6-b7cb-7edd4aac95a2)
```c
#include<stdio.h>

void modify(int value) {
	value = 99;
}

int main() {
	int number = 1;

	modify(number);
	printf("number=%d\n", number);
	return 0;
}
```

결과
```
number=1
```
* modify()에서 매개변수 value를 99로 변경하였다. main()에서 modify()를 호출할 때, 변수 number을 전달한다. 함수 호출 후에 변수 number의 값이 변경될까? c언어에서는 "값에 의한 호출"이 원칙이기 때문에 실행 결과에서 보듯이 number의 값은 변경되지 않았다.


* 참조에 의한 호출(call-by-reference): 만약 함수가 호출될 때 원본을 함수로 전달하는 방법, 함수 안에서 매개변수를 변경하면 원본 변수가 수정된다.
* c에서는 포인터를 이용하여 흉내낼 수 있다.
* [예](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%EC%B0%B8%EC%A1%B0%EC%97%90%20%EC%9D%98%ED%95%9C%20%ED%98%B8%EC%B6%9C/%EC%B0%B8%EC%A1%B0%EC%97%90%20%EC%9D%98%ED%95%9C%20%ED%98%B8%EC%B6%9C/FileName.c)
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/313d3ca3-6ce4-4c48-bd58-72431dbfc30c)

```c
#include<stdio.h>

void modify(int* ptr) {
	*ptr = 99;//매개변수를 통하여 원본을 변경한다.
}

int main() {
	int number = 1;

	modify(&number);//주소를 계산해서 보낸다.
	printf("number=%d\n", number);

	return 0;
}
```

결과
```
number=99
```

* modify()함수를 호출할 때 number의 변수의 주소를 계산하여 전달하였다.
* modify()함수에서는 이 주소를 포인터 ptr에 저장한다. ptr이 가라키는 위치를 99로 변경하고 있다.
* 변수에 주소를 전달하였기 때문에 modify()함수에서 주소를 이용하여 원본 변수의 값을 변경할 수 있었다.
* 우리가 집 주소를 택배 회사에 알려주면 택배가 집으로 올 수 있는 것과 마찬가지이다.

---

### swap()함수 1
* 변수 2개의 값을 바꾸는 작업을 함수로 작성
```c
void swap(int x, int y){
    int tmp;
    tmp=x;
    x=y;
    y=tmp;
}

int main(){
    int a=10, b=20;
    printf("swap()호출 전: a=%d, b=%d\n", a, b);
    swap(a, b);
    printf("swap()호출 후: a=%d, b=%d\n", a, b);
    return 0;
}
```
> swap() 호출 전: a=10, b=20
>
> swap() 호출 후: a=20, b=10

* **포인터를 이용**
```c
void swap(int *px, int *py){
    int tmp;
    tmp=*px;
    *px=*py;
    *py=tmp;
}

int main(){
    int a=100, b=200;
    printf("swap()호출 전: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("swap()호출 후: a=%d, b=%d\n", a, b);
    return 0;
}
```
> swap() 호출 전: a=100, b=200
> 
> swap() 호출 후: a=200, b=100

---

### 포인터 사용시 주의점
* 초기화가 안된 포인터를 사용하면 안된다.
* 만약 포인터가 선언만 되고 초기화되지 않았다면 포인터는 임의의 주소를 가리키게 되는데, 이런 상태에서 포인터를 이용하여 메모리의 내용을 변경한다면 문제가 발생할 수 있다.
* 예를 들어 포인터 p를 초기화시키지 않고 포인터 p가 가리키는 곳에 값 100을 대입하고 있어 위험한 코드다.
* 만약 우연히 p가 중요한 영역을 가리키고 있었다면 중요한 정보를 덮어 쓸 수도 있으며, 따라서 전체 시스템을 다운시킬 수 있다.
```c
int main(){
    int *p;//포인터 p는 초기화가 안되어 있음
    *p=100;//위험한 코드!
    return 0;
}
```

### 널 포인터의 사용
* 포인터가 아무것도 가리키도 있지 않는 경우에는 NULL로 초기화
* NULL은 stdio.h에 정수 0으로 정의됨됨
* 포인터의 유효성 여부 판단이 쉽다.

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/6a7571e5-09d3-4535-9131-412c1a8c7e9b)

* 포인터의 타입과 변수의 타입은 일치하여야 한다.
```c
#include<stdio.h>

int main(){
    int i;
    double *pd;

    pd=&i;//오류! double형 포인터에 int형 변수의 주소를 대입
    *pd=36.5;

    return 0;
}
```
### 포인터 자료형과 변수의 자료형이 다른 경우
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/8871b28a-84c9-46d8-9826-6df17170e12c)

* 포인터는 메모리의 어디든지 가리킬 수 있지만 포인터에 의하여 참조되는 객체가 얼마만큼의 크기이고 무엇이 어떤 형식으로 저장되어 있는 지를 결정하는 것은 포인터의 자료형이다.

```c
#include<stdio.h>

int main(){
    int i;
    double *pd;
    
    pd=&i;
    *pd=36.5;//오류! double형 포인터에 int형 변수의 주소를 대입
    
    return 0;
}
```

---

### 배열과 포인터
* 배열과 포인터는 아주 밀접한 관계를 가지고 있다.
* 배열 이름이 바로 포인터다.
* 포인터는 배열처럼 사용이 가능하다.

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/80cd70fd-4d11-434c-afef-a9c6bf13339a)

[예제](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EB%B0%B0%EC%97%B4/%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EB%B0%B0%EC%97%B4/FileName.c)
```c
#include<stdio.h>

int main() {
	int a[] = { 10, 20, 30, 40, 50 };

	printf("배열의 이름: %u\n", a);
	printf("첫 번째 원소의 주소: %u\n", a[0]);

	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/73d6492f-678d-4801-a7d9-22959f3fcc56)

### 포인터를 배열처럼 사용
* 포인터도 배열 이름처럼 간주될 수 있고 배열과 똑같이 사용할 수 있다.

[코드 직접 보기](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EB%B0%B0%EC%97%B4_2/%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EB%B0%B0%EC%97%B4_2/FileName.c)
```c
#include<stdio.h>

int main() {
	int a[] = { 10, 20, 30, 40, 50 };
	int* p;

	p = a;
	printf("배열의 값: \n");
	for (int i = 0; i < 5; i++) {
		printf("a[%d]=%d ", i, a[i]);
	}
	printf("\n");

	printf("배열의 주소: \n");
	for (int i = 0; i < 5; i++) {
		printf("p[%d]=%d ", i, p[i]);
	}
	printf("\n");

	return 0;
}
```
>결과
> 배열의 값:
>
> a[0]=10 a[1]=20 a[2]=30 a[3]=40 a[4]=50
>
> 배열의 주소:
>
> p[0]=10 p[1]=20 p[2]=30 p[3]=40 p[4]=50

---

### 어디에 사용될까?
* 대용량의 데이터가 필요한 함수가 있을 때, 데이터가 있는 위치를 알려주고 필요한 부분만을 사용하도록 하면 좋다.
[직접 보기](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%ED%8F%AC%EC%9D%B8%ED%84%B0%20%EC%82%AC%EC%9A%A9%EC%B2%98/%ED%8F%AC%EC%9D%B8%ED%84%B0%20%EC%82%AC%EC%9A%A9%EC%B2%98/FileName.c)
```c
#include<stdio.h>

void sub(int* ptr) {
	printf("%d\n", ptr[10]);
}

int main() {
	int large_data[20];
	for (int i = 0; i < 20; i++)
		large_data[i] = i + 1;
	sub(large_data);
	return 0;
}
```
>결과
>
> 11

---

### Lab: 유용한 배열 함수 작성
* 정수 배열에 대하여 평균을 계산하고 배열을 출력하는 함수를 작성하고 사용해보자.
    * double get_array_avg(int values[], int n); 정수 배열을 받앗 배열 요소의 평균값을 계산하여 반환한다.
    * void print_array(int values[], int n); 정수 배열을 받아서 배열 요소들을 출력한다.

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/63d9db82-598e-463a-a4d9-cde0f5629570)

### Sol
[코드 보기](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%ED%8F%AC%EC%9D%B8%ED%84%B0%20%EC%82%AC%EC%9A%A9%EC%B2%98/%ED%8F%AC%EC%9D%B8%ED%84%B0%20%EC%82%AC%EC%9A%A9%EC%B2%98/FileName.c)
```c
#include<stdio.h>
#define size 5

double getArrayAvg(int *values, int n){
    int i;
    double sum=0.0;
    for(i=0; i<n; i++){
        sum+=*(values+i);
    }
    return sum/n;
}

void printArray(int *values, int n){
    int i;
    printf("[ ");
    for(i=0; i<n; i++)
        printf("%d ", *(values+i));
    printf("]\n");
}
int main(){
    int i; 
    int data[size]={10, 20, 30,40,50};
    double result;
    
    printArray(&data, size);
    printf("get_ArrayAvg()함수 호출\n");
    result=getArrayAvg(&data, size);
    printf("배열 원소들의 평균: %lf", result);
    return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/c424f80f-618b-4532-b463-06e9946bc0d7)

---

## mini project: 어드벤쳐 게임 만들기
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/33be686d-4070-45ca-8c94-635c38b785a0)
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
 
int main(void)
{
    char board[10][10];
    int xpos = 1, ypos = 1;
    int k, i;
 
    // 보드를 초기화한다. 
    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++) board[y][x] = '.';
    board[ypos][xpos] = '#';
    board[9][9] = 'G';
    board[5][5] = 'M';
    board[6][7] = 'M';
 
    printf("왼쪽이동:a, 오른쪽 이동:d 위쪽 이동:w, 아래쪽 이동:s\n");
    // 사용자로부터 위치를 받아서 보드에 표시한다. 
    while (1) {
        system("cls");
        printf("왼쪽이동:a, 오른쪽 이동:d 위쪽 이동:w, 아래쪽 이동:s\n");
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) printf("%c", board[y][x]);
            printf("\n");
        }
        board[ypos][xpos] = '.';
        int ch = _getch();
        if (ch == 'a') xpos--;
        else if (ch == 's') ypos++;
        else if (ch == 'w') ypos--;
        else if (ch == 'd') xpos++;
        board[ypos][xpos] = '#';
    }
    return 0;
}

```
