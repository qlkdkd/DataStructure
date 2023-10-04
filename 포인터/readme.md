# 포인터
### 포인터란?
* 포인터(pointer): 주소를 가지고 있는 변수

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/4ac61cc3-bb07-450a-924b-9a6b75f135a0)


### 메모리의 구조
* 변수는 메모리에 저장된다.
* 메모리는 바이트 단위로 엑세스된다.
* 첫번째 바이트의 주소는 0, 두번째 바이트는 1...

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/8c327d08-bc90-40bf-a086-12478f23dbb9)

### 변수와 메모리
* 변수의 크기에 따라서 차지하는 메모리 공간이 달라진다.
* `char`형 변수: `1`바이트, `int`형 변수: `4`바이트,...

```c
int main(){
  int i=10;
  char c=69;
  float f=12.3;
  return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/e3d801ef-ffaf-4ac8-8540-b157c1dd6a54)

### 변수의 주소
* 변수의 주소를 계산하는 연산자: `&`
* 변수 i의 주소: &i

  ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f3e41be2-e699-4216-8e1c-bfbb6ca5e3f9)
[코드 보기](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%EB%B3%80%EC%88%98%EC%9D%98%20%EC%A3%BC%EC%86%8C/%EB%B3%80%EC%88%98%EC%9D%98%20%EC%A3%BC%EC%86%8C/FileName.c)

---

### 포인터의 선언
* 포인터: 변수의 주소를 가지고 있는 변수
  ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/120fef2a-ce6c-46a3-a90c-d283a1d9a707)

### 포인터와 변수의 연결
```c
int number=10; //정수형 변수 number 선언
int *p; //포인터 변수 p 선언
p=&number; //변수 number 의 주소가 포인터 p로 대
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/815b9900-941a-43ea-b988-38d003e389cf)

* 포인터 p가 변수 number를 가리킨다.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/13e0693a-648a-4164-b0b7-f30a555ba320)

### 간접 참조 연산자
* 간접 참조 연산자 *: 포인터가 가리키는 값을 가져오는 연산자
```c
int i=10;
int *p;
p=&i;
printf("%d", &p);
```

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/569ff796-a155-47f3-8130-8463f34f4a4e)

### 포인터 연산자
* 포인터에 관련된 연산자는 다음과 같은 2가지이다.
    #### 주소 연산자(&)
    #### 간접 참조 연산자(*)
* 예제1[example1.c](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/example1/example1/FileName.c)
> 결과
> 
> 변수 number의 주소: 261093460
>
> 포인터의 값: 261093460
>
> 변수 number의 값: 10
>
> 포인터가 가리키는 값: 10

* 예제2[example2.c](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/example2/example2/FileName.c)
> 결과
>
> 변수 number의 값: 10
>
> 변수 number의 값: 20

---

포인터 연산
* 가능한 연산: 증가, 감소, 덧셈, 뻴셈 연산
* 증가 연산의 경우 증가되는 값은 포인터가 가리키는 객체의 크기
> 포인터의 증가는 일반 변수와는 약간 다르다. 가리키는 객체의 크기만큼 증가한다.

포인터 타입|++연산 후 증가되는 값
---|---
char|1
short|2
int|4
float|4
double|8

* 증가 연산 예제: [증가연산예제.c](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%EC%A6%9D%EA%B0%80%EC%97%B0%EC%82%B0%EC%98%88%EC%A0%9C/%EC%A6%9D%EA%B0%80%EC%97%B0%EC%82%B0%EC%98%88%EC%A0%9C/FileName.c)
> 결과(코드는 링크 참조)
> 
> 증가 전 pc: 10000, pi: 10000, pd: 10000
> 
> 증가 후 pc: 10001, pi: 10004, pd: 10008

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
* 값에 의한 호출(call-by-value)[예](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%EA%B0%92%EC%97%90%20%EC%9D%98%ED%95%9C%20%ED%98%B8%EC%B6%9C/%EA%B0%92%EC%97%90%20%EC%9D%98%ED%95%9C%20%ED%98%B8%EC%B6%9C/FileName.c)
    *  c의 기본적인 방법
    *  인수의 값이 매개변수로 복사된다.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/89c70169-8416-4cc6-b7cb-7edd4aac95a2)


* 참조에 의한 호출(call-by-reference)[예](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/%EC%B0%B8%EC%A1%B0%EC%97%90%20%EC%9D%98%ED%95%9C%20%ED%98%B8%EC%B6%9C/%EC%B0%B8%EC%A1%B0%EC%97%90%20%EC%9D%98%ED%95%9C%20%ED%98%B8%EC%B6%9C/FileName.c)
    * c에서는 포인터를 이용하여 흉내낼 수 있다.
    * 인수의 주소가 매개변수로 복사된다.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/313d3ca3-6ce4-4c48-bd58-72431dbfc30c)

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
> swap() 호출 후: a=200, b=100

---

### 포인터 사용시 주의점
* 초기화가 안된 포인터를 사용하면 안된다.
```c
int main(){
    int *p;//포인터 p는 초기화가 안되어 있음
    *p=100;//위험한 코드!
    return 0;
}
```
* 포인터가 아무것도 가리키도 있지 않는 경우에는 NULL로 초기화
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
