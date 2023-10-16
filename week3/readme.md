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
