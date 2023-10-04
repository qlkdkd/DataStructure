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
> 변수 number의 주소: 261093460
> 포인터의 값: 261093460
> 변수 number의 값: 10
> 포인터가 가리키는 값: 10

* 예제2[example2.c](https://github.com/qlkdkd/DataStruct/blob/main/%ED%8F%AC%EC%9D%B8%ED%84%B0/example2/example2/FileName.c)
> 결과
> 변수 number의 값: 10
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
> 증가 전 pc: 10000, pi: 10000, pd: 10000
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
