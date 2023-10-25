# 연결 리스트1

## 리스트
* 리스트(list)는 우리들이 자료를 정리하는 방법 중 하나
* 일상생활 속 리스트
    * 오늘 해야 할 일
    * 버킷 리스트
    * 요일들
    * 카드 한 벌의 값
 
## 리스트의 기본 연산
$$L=(item_0, item_1, item_2, ..., item_n)$$
* 리스트는 집합하고 다름: 집합은 각 함목 간에 순서의 개념이 없다.
* 스택과 큐도 리스트의 일종

* 리스트 연산 목록
    * 리스트에 새로운 항목을 추가(삽입 연산)
    * 리스트에 항목을 삭제(삭제 연산)
    * 특정한 항목 검색(탐색 연산)
 
## 리스트 ADT
```
객체: n개의 element형으로 구성된 순서 있는 모임
//연산
insert(list, pos, item)::=pos위치에 요소를 추가
insert_last(list, item)::=맨 끝에 요소를 추가
insert_first(list, item)::=맨 처음에 요소를 추가
delete_list(list, pos)::=pos위치에 요소를 제거
clear(list)::=리스트의 모든 요소를 제거
get_entry(list, pos)::=pos위치의 요소를 반환
is_empty(list)::=리스트가 비었는지 검사
is_full(list)::=리스트가 꽉 찼는지 검사
print_list(list)::=리스트의 모든 요소를 검사
```

## 리스트의 구현 방법
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/d847b449-9670-47d0-a783-41c3b593aa4a)
* 리스트는 배열과 연결 리스트를 이용하여 구현할 수 있음
* 배열 사용
    * 리스트 ADT를 가장 간단하게 구현할 수 있음
    * 크기가 고정되는 단점이 있음->배열의 특성상 동적으로 크기를 늘리거나 줄이는 것이 힘듬
* 포인터를 이용하여 연결 리스트 만들기
    * 연결 리스트는 필요할 때마다 중간에 속지를 추가해서 사용할 수 있는 바인더 공책과 비슷
    * 구현이 복잡하다는 단점이 존재
 
## 배열로 구현된 리스트
* 배열을 이용하면 리스트를 구현하면 순차적인 메모리 공간이 할당되므로, 이것을 리스트의 순차적인 표현(sequential representation)라고도 한다.
* 배열을 사용하면 리스트의 항목을 아주 자연스럽게저장할 수 있음
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/bb04e7db-f160-417f-8339-f853a0b002dc)

## ArryayListType의 구현
```c
define MAX_LIST_SIZE 100

typedef int element;//항목의 정의

typedef struct{
  element array[MAX_LIST_SIZE];//배열의 정의
  int size;//현재 리스트에 저장된 항목들의 개수
}ArrayListType;
```

* 리스트 연산 구현
```c
#define MAX_LIST_SIZE 100
#include<stdio.h>

typedef int element;//항목의 정의

typedef struct {
	element array[MAX_LIST_SIZE];//배열의 정의
	int size;//현재 리스트에 저장된 항목들의 개수
}ArrayListType;


//오류처리 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


//리스트 초기화 함수
void init(ArrayListType* L) {
	return L->size == 0;
}

//리스트가 비어있으면 1을 반환
//그렇지 않으면 0을 반환
int is_empty(ArrayListType* L) {
	return L->size == 0;
}


//리스트가 가득 차 있으면 1을 반환
//그렇지 않으면 0을 반환
int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}


//리스트 출력
void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}
	printf("\n");
}
```
