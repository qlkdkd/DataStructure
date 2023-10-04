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
