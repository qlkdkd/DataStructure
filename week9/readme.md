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

* [리스트 연산 구현](https://github.com/qlkdkd/DataStruct/blob/main/week9/ArrayListType/ArrayListType/FileName.c)
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


//맨 끝에 항목 추가
void insert_last(ArrayListType *L, element item){
	if(L->size>=MAX_LIST_SIZE){
		error("리스트 오버플로우");
	}
	L->array[L->size++]=item;
}
```

### 항목 추가 연산

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/9815d7b0-e16d-4ab3-9720-8b00058ab317)

* insert_last() 함수에서는 리스트에 빈 공간이 없으면 오류를 발생시킴
* 리스트의 pos위치에 새로운 항목을 추가하려면 pos번째부터 마지막 항목까지 한 칸씩 오른쪽으로 이동하여 빈 자리를 만든 후에, 새로운 항목을 pos위치에 저장하여야 함

* 위 그림은 pos=1에 새로운 항목을 추가하는 것을 나타낸다.
* 빈자리를 만들기 위하여 array[1]부터 array[3]까지 한 칸씩 오른쪽으로 이동함
* 순서 중요!
* array[3]->array[4], array[2]->array[3], array[1]->array[2]
* 새로운 항목을 array[1]에 저장

* insert 함수 구현
```c
//pos위치에 항목 추가
void insert(ArrayListType *L, int pos, element item){
	if(!is_full(L) && (pos>=0) && (pos<=L->size)){
		for(int i=(L->size-1); i>=pos; i--)
			L->array[i+1]=L->array[i];
		L->array[pos]=item;
		L->size++;
	}
}
```

### 항목 삭제 연산
* 마찬가지로 삭제한 후에 array[pos+1]부터 array[size-1]까지 한 칸씩을 앞으로 이동해야 함

```c
//항목 삭제 연산
element delete(ArrayListType *L, int pos){
	element item;
	if(pos<0 || pos>=L->size)
		error("위치 오류");
	item=L->array[pos];
	for(int i=pos; i<(L->size-1); i++)
		L->array[i]=L->array[i+1];
	L->size--;
	return item;
}
```
### [예제 프로그램](https://github.com/qlkdkd/DataStruct/blob/main/week9/ArrayList/ArrayList/FileName.c)
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 	// 리스트의 최대크기

typedef int element;			// 항목의 정의
typedef struct {
	element array[MAX_LIST_SIZE];	  // 배열 정의
	int size;		  // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;
// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 리스트 초기화 함수
void init(ArrayListType* L)
{
	L->size = 0;
}
// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}
// 리스트가 가득 차 있으면 1을 반환
// 그렇지 많으면 1을 반환
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}
// 리스트 출력
void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}
void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}
void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}
element delete(ArrayListType* L, int pos)
{
	element item;

	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}
int main(void)
{
	// ArrayListType를 정적으로 생성하고 ArrayListType를 	
	// 가리키는 포인터를 함수의 매개변수로 전달한다.
	ArrayListType list;

	init(&list);
	insert(&list, 0, 10);	print_list(&list);	// 0번째 위치에 10 추가
	insert(&list, 0, 20);	print_list(&list);	// 0번째 위치에 20 추가
	insert(&list, 0, 30);	print_list(&list);	// 0번째 위치에 30 추가
	insert_last(&list, 40);	print_list(&list);	// 맨 끝에 40 추가
	delete(&list, 0);		print_list(&list);	// 0번째 항목 삭제
	return 0;
}
```

---

## 연결된 표현
* 연결된 표현: 동적으로 크기가 변할 수 있고 삭제나 삽입 시에 데이터를 이동할 필요가 없음
* 포인터를 사용하여 데이터들을 연결

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/eedfb1a0-8c06-4452-935c-4e17241753ca)

* 연결 리스트: 물리적으로 흩어져 있는 자료들을 서로 연결하여 하나로 묶는 방법
	* 상자 안에는 데이터가 들어가고 상자에 연결된 줄을 따라가면 다음 상자를 찾을 수 있음
	* 연결된 표현은 일단 데이터를 한 군데 모아두는 것을 포기하는 것: 데이터들은 메인 메모리 상의 어디에나 흩어져서 존재할 수 있음
* 상자를 연결하는 줄은 포인터로 구현
* 연결 리스트의 장점
	* 앞뒤에 있는 데이터들을 이동할 필요 없이 줄만 변경시켜주면 됨 -> **삽입, 삭제가 용이**
   	* 데이터를 저장할 공간이 필요할 때마다 동적으로 공간을 만들어서 쉽게 추가할 수 있음 -> **연속된 메모리 공간 필요 없음, 크기 제한 없음**
   	
* 연결 리스트의 단점
	* 배열에 비하여 상대적으로 구현이 어려워 오류가 나기 쉬움
 	* 데이터뿐만 아니라 포인터도 저장해야 하므로 메모리 공간을 많이 사용함
  	* i번째 데이터를 찾으려면 앞에서부터 순차적으로 접근해야 함

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/28527756-0591-43bf-8dcd-01228c56970a)

## 연결 리스트의 구조
* 데이터 상자를 컴퓨터 용어로 노드(node)라고 부름
* 연결 리스트는 노드들의 집합
* 노드들은 메모리의 어떤 위치에나 있을 수 있으며, 다른 노드로 가기 위해서는 현재 노드가 가지고 있는 포인터를 이용하면 됨
* 노드는 데이터 필드(data field)와 링크 필드(link field)로 구성

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/dd183705-9ea4-4cc1-a817-d1286be5b672)

* 데이터 삭제 시에도 위 그림과 같이 항목 c를 삭제하려고 하면 데이터들을 옮길 필요가 없이 그냥 데이터들을 연결시키는 줄만 수정하면 됨

* 하나의 프로그램 안에는 동시에 여러 개의 연결 리스트가 존재할 수 있음
	* 첫 번째 데이터로 리스트를 구별
 	* 첫 번째 데이터만 알 수 있다면 나머지 데이터들은 줄만 따라가면 얻을 수 있음
 
* 데이터 필드에는 우리가 저장하고 싶은 데이터가 들어감. 데이터는 정수가 될 수 있고 구조체와 같은 복잡한 데이터가 될 수도 있다.
* 링크 필드에는 다른 노드를 가리키는 포인터가 저장된다. 이 포인터를 이용하여 다음 노드로 건너갈 수 있다.
* 헤드 포인터: 연결 리스트의 첫 번째 노드: 첫 번째 노드를 알아야 전체 노드에 접근 가능
* 마지막 노드의 링크 필드는 NULL값으로 설정: 더이상 연결된 노드가 없다는 것을 의미
* 연결 리스트의 노드들은 필요할 때마다 malloc()을 이용하여 동적으로 생성됨

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/d0ba3e20-0174-4604-944b-ca59796dfb51)

## 연결 리스트의 종류
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/0816c9e1-48be-41ca-9546-9d07d732a9cb)
* 원형 연결 리스트(circular linked list): 마지막 노드의 링크가 첫 번째 노드를 가리킴
* 이중 연결 리스트(doubly linked list): 각 노드마다 2개의 링크가 존재, 하나의 링크는 앞에 있는 노드를 가리키고 또 하나의 링크는 뒤에 있는 노드를 가리킴
* 이번 장에서는 단순 연결 리스트만 다룸 나머지는 다음장에...
* **단순 연결 리스트(singly linked list)**: 한 방향으로만 연결
	* 단순 연결 리스트는 체인(chain)이라고도 함
  	* 이 링크 필드를 이용하여 모든 노드들이 연결됨
   	* 단순 연결 리스트의 마지막 노드의 링크는 NULL값을 가짐
 
  	![image](https://github.com/qlkdkd/DataStruct/assets/71871927/dcc76ff7-3585-4181-b5a8-50d5420764e2)

## 노드의 정의
* 노드는 자기 참조 구조체를 이용하여 정의됨
	* 자기 참조 구조체: 자기 자신을 참조하는 포인터를 포함하는 구조체
* 구조체 안에는 데이터를 저장하는 data필드와 포인터가 저장되어 있는 링크 필드가 존재
* 데이터 필드는 element타입의 데이터를 저장하고 있음
* link필드는 ListNode를 가리키는 포인터로 정의되며 다음 노드의 주소가 저장됨
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/046c84d6-e912-43e4-81b9-223f7c8963ce)

```c
typedef int element;

typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;
```

### 공백 리스트 생성
* 단순 연결 리스트는 헤드 포인터만 있으면 모든 노드를 찾을 수 있음
* 노드를 가리키는 포인터 head를 정의하면 하나의 단순 연결 리스트가 만들어졌다고 볼 수 있음
```c
ListNode *head=NULL;
```

### 노드의 생성
* 일반적으로 연결 리스트에서는 필요할 때마다 동적 메모리 할당을 이용하여 노드를 동적으로 생성
* 다음 코드에서는 malloc()함수를 이용하여 노드의 크기만큼 동적 메모리를 할당 받음
* 이 동적 메모리가 하나의 노드가 됨
* 동적 메모리의 주소를 헤드 포인터 head에 저장함
```c
head=(ListNode*)malloc(sizeof(ListNode));
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f2f06fe0-1865-470c-a469-aebb9a4bc9b0)

* 다음 절차는 새로 만들어진 노드에 데이터를 저장하고 링크필드를 NULL로 설정
```c
head->data=10;
head->link=NULL;
```

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/7bfcad34-6259-4ce6-838f-16d7433d269c)

### 노드의 생성
* 일반적으로 연결 리스트에는 여러 개의 노드가 서로 연결됨
* 동일한 방식으로 2번째 노드를 동적으로 생성하고 노드에 20 저장
```c
ListNode *p;
p=(ListNode*)malloc(sizeof(ListNode));
p->data=20;
p->link=NULL;
```

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/5ac96eb2-134a-4ec7-8be5-6956e6344b59)

## 노드의 연결
* 생성된 2개의 노드를 서로 연결
* head->link에 p를 저장하면, 첫 번째 노드의 링크가 2번째 노드를 가리키게 됨
```c
head->link=p;
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/9d3ac93d-2769-4df1-837f-afea915319ad)
