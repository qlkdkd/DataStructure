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

## 단순 연결 리스트의 연산

우리는 앞 절에서 노드를 하나씩 만들어서 서로 연결하였다. 작은 리스트이면 이렇게 만들어도 되지만 리스트가 커지면 추상 데이터 타입에 정의된 전용 함수들을 통하여 노드를 추가하는 것이 편하다.

* insert_first(): 리스트의 시작 부분에 항목을 삽입하는 함수
* insert(): 리스트의 중간 부분에 항목을 삽입하는 함수
* delete_first(): 리스트의 중간 항목을 삭제하는 함수
* delete(): 리스트의 중간 항목을 삭제하는 함수(도전 문제)
* print_list(): 리스트를 방문하여 모든 항목을 출력하는 함수

## 단순 연결 리스트_삽입연산(insert_first())
 단순 연결 리스트의 경우, 리스트의 처음이나 끝에 새로운 노드를 추가하는 경우가 많다. 여기서는 리스트의 첫 부분에 새로운 노드를 추가하는 함수 insert_first()를 작성해 보자.
 여기서 매개변수head는 헤드 포인터이고 value는 새롭게 추가되는 데이터이다.

 head가 첫 번째 노드를 가리키디 때문에 리스트의 시작 부분에 노드를 추가하는 것은 비교적 쉽다. 새로운 노드를 하나 생성하고 새로운 노드의 link에 현재의 head값을 저장한 후에,
 head를 변경하여 새로 만든 노드를 가리키도록 하면 된다. insert_first()은 변경된 헤드포인터를 반환한다. 따라서 반환된 값을 헤드포인트에 저장하여야 한다.

 ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/608c93b3-9d0f-442e-a19c-1e03972a9406)

```c
ListNode *insert_first(ListNode *head, int value){
    ListNode *p=(ListNode*)malloc(sizeof(ListNode));//(1)
    p->data=value;//(2)
    p->link=head;//(3)
    head=p;//(4)
    return head;//(5)
}
```

### 알고리즘 설명

1. 동적 메모리 할당을 통하여 새로운 노드 p를 생성한다.
2. p->data에 value를 저장한다.
3. p->link를 현재의 head값으로 변경한다.
4. head를 p값으로 변경한다.
5. 변경된 헤드 포인터 반환

---

## 삽입 연산(insert())
insert()는 가장 일반적인 경우로서 연결 리스트의 중간에 새로운 노드를 추가한다. 이때는 반드시 삽입되는 위치의 선행 노드를 알아야 삽입이 가능한다.
선행 노드를 pre가 가리키고 있다고 가정하자.
예를 들어서 아래 그림에서 20과 40 사이에 30을 삽입하여 보자. 다음과 같은 절차가 필요하다.

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/3bb69379-d11c-4d95-ac31-80ae3c023790)

```c
ListNode *insert(ListNode *head, ListNode *pre, element value){
    ListNode *p=(ListNode*)malloc(sizeof(ListNode));//(1)
    p->data=value;//(2)
    p->link=pre->link;//(3)
    p->link=p;//(4)
    return head;//(5)
}
```

### 알고리즘 설명
1. 새로운 노드를 생성하여 변수 p로 가리킨다.
2. p의 데이터 필드에 20을 저장한다.
3. p의 링크 필드가 노드 30을 가리키게 변경한다.
4. 10의 링크 필드가 20을 가리키도록 한다.
5. 변경된 헤드포인터 반환

---

## 단순 연결 리스트_삭제연산(delete_first())
첫 번째 노드를 삭제하는 함수 delete_first는 다음과 같은 원형을 가진다.
```c
ListNode *delete_first(ListNode *head)
```

시작부분 노드 삭제 절차
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/dd97e054-2769-4337-94b1-1866a63b0e0f)

```c
ListNode *delete_first(ListNode *head){
    ListNode *removed;
    if(head==NULL) return NULL;
    removed=head;//(1)
    head=removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}
```

### 알고리즘 설명
1. 헤드포인터의 값을 removed에 복사한다.
2. 헤트포인터 값을 head->link로 변경한다.
3. removed가 가리키는 동적 메모리를 반환한다.
4. 변경된 헤드포인터를 반환한다.

---

## 삭제 연산(delete())
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/04e0ee24-932a-46c0-a5c8-29f353819d68)
```c
ListNode *delete(ListNode *head, ListNode *pre){
    ListNode *removed;
    removed=pre->link;//(1)
    pre->link=removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}
```

### 알고리즘 설명
1. 삭제할 노드를 찾는다.
2. 노드 10의 링크필드가 노드 30을 가리키게 한다.
3. 삭제할 노드의 동적 메모리를 반납한다.
4. 변경된 헤드포인터를 반환한다.

---

## 방문 연산 코드(print_list())
우리는 연결 리스트의 노드를 방문하면서 노드를 대상으로 다양한 작업을 할 수 있다. 예를 들면 노드를 방문하면서 노드의 데이터를 화면에 출력할 수 있다. 연결 리스트 안의 모든 노드 데이터를 출력하는 함수 print_list를 작성해보자.
노드의 링크 값이 NULL이 아니면 계속 링크를 따라 가면서 노드를 방문한다. 링크값이 NULL이면 연결 리스트의 끝에 도달한 것이므로 반복을 중단한다. 방문 연산 연결 리스트에서 가장 기본이 되는 연산이므로 그 개념을 확시히 이해해야 한다.

```c
void print_list(ListNode *head){
    for(ListNode *p=head; p!=NULL; p=p->Link)
        printf("%d->", p->data);
    printf("NULL\n");
}
```

---

## [테스트 프로그램](https://github.com/qlkdkd/DataStruct/blob/main/week10/ListTest/ListTest/FileName.c)

```c
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {//노드 타입
	element data;
	struct ListNode* link;
}ListNode;

//오류 처리 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//첫 노드 삽입 연산
ListNode* insert_first(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//
    p->link = head;//(3)
    head = p;//(4)
    return head;//(5)
}

//노드 pre뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//(2)
    p->link = pre->link;//(3)
    p->link = p;//(4)
    return head;//(5)
}

//첫 노드 삭제
ListNode* delete_first(ListNode* head) {
    ListNode* removed;
    if (head == NULL) return NULL;
    removed = head;//(1)
    head = removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}

//pre가 가리키는 노드의 다음 노드 삭제
ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre->link;//(1)
    pre->link = removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}

//연결 리스트 출력
void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}



//테스트 프로그램
int main() {
    ListNode* head = NULL;
    
    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i);//insert_first()가 반환된 헤드 포인터를 head에 대입
        print_list(head);
    }
    for (int i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }

    return 0;
}
```

---

## [Lab: 단어들을 저장하고 있는 연결 리스트](https://github.com/qlkdkd/DataStructure/blob/main/week10/wordList/wordList/FileName.c)

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[100];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

//오류 처리 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//첫 노드 삽입 연산
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
	p->data = value;//
	p->link = head;//(3)
	head = p;//(4)
	return head;//(5)
}

//연결 리스트 출력
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data);//단어를 출력하므로 %d에서 %s로 바꿔줌
	printf("NULL\n");
}

int main() {
	ListNode* head = NULL;
	element data;

	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);

	return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/09ae9650-8b8d-4079-9fe2-e561232fe8de)

---

## [Lab: 특정한 값을 탐색하는 함수 작성](https://github.com/qlkdkd/DataStructure/blob/main/week10/fineSpecificValue/fineSpecificValue/FileName.c)

```c
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {//노드 타입
    element data;
    struct ListNode* link;
}ListNode;


//첫 노드 삽입 연산
ListNode* insert_first(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//
    p->link = head;//(3)
    head = p;//(4)
    return head;//(5)
}
//연결 리스트 출력
void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

//탐색 함수
ListNode* search_list(ListNode* head, element x) {
    ListNode* p = head;

    while (p != NULL) {
        if (p->data == x)return p;
        p = p->link;
    }
    return NULL;//탐색 실패
}


//테스트 프로그램
int main() {
    ListNode* head = NULL;

    head = insert_first(head, 10);
    print_list(head);

    head = insert_first(head, 20);
    print_list(head);

    head = insert_first(head, 30);
    print_list(head);

    if (search_list(head, 30) != NULL)
        printf("리스트에서 30을 찾았습니다.\n");
    else
        printf("리스트에서 30을 찾지 못했습니다.\n");
    
    return 0;
}
```

---

## [Lab: 2개의 리스트를 합하는 함수](https://github.com/qlkdkd/DataStructure/blob/main/week10/TwoList/TwoList/FileName.c)
2개의리스트를 합치려면 먼저 첫 번째 리스트를 맨 끝으로 간 다음, 마지막 노드의 링크가 두 번째 리스트의 첫 번째 노드를 가리키도록 변경하면 된다. 주의할 점은 list1이나 list2가 NULL인 경우를 반드시 처리해주어야 한다.
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/b780afa4-599e-4be3-8ede-ee300707e2a3)


```c
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {//노드 타입
    element data;
    struct ListNode* link;
}ListNode;

//오류 처리 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//첫 노드 삽입 연산
ListNode* insert_first(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//
    p->link = head;//(3)
    head = p;//(4)
    return head;//(5)
}

//노드 pre뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//(2)
    p->link = pre->link;//(3)
    p->link = p;//(4)
    return head;//(5)
}

//첫 노드 삭제
ListNode* delete_first(ListNode* head) {
    ListNode* removed;
    if (head == NULL) return NULL;
    removed = head;//(1)
    head = removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}

//pre가 가리키는 노드의 다음 노드 삭제
ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre->link;//(1)
    pre->link = removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}

//연결 리스트 출력
void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

ListNode* contact_list(ListNode* head1, ListNode* head2) {
    if (head1 == NULL)return head2;
    else if (head2 == NULL)return head2;
    else {
        ListNode* p;
        p = head1;
        while (p->link != NULL)
            p = p->link;
        p->link = head2;
        return head1;
    }
}
int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    //head1에 값 삽입
    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    //head2에 값 삽입
    head2 = insert_first(head2, 40);
    head2 = insert_first(head2, 50);
    print_list(head2);
    
    //두 노드 합치기
    ListNode* total = contact_list(head1, head2);
    print_list(total);

    return 0;
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/1fd95249-5035-4c68-b4f2-6b794753216d)

---

## [Lab: 리스트를 역순으로 만드는 연산](https://github.com/qlkdkd/DataStructure/blob/main/week10/ReverceList/ReverceList/FileName.c)
* 리스트를 역순으로 만드는 함수에서는 3개의 포인터 p, q, r 포인터를 사용하여 연결 리스트를 순회하면서 링크의 방향을 역순으로 바꾸면 된다.
* p는 역순으로 만들 리스트이고, q는 현재 역순으로 만들 노드를 가리키며, r은 이미 역순으로 변경된 리스트를 가리킨다. r은 q, q는 p를 차례로 따른다.
* 주의할 점은 링크의 방향을 역순으로 바꾸기 전에 미리 뒤의 노드를 알아놓아야 한다.

```c
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {//노드 타입
    element data;
    struct ListNode* link;
}ListNode;

//오류 처리 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//첫 노드 삽입 연산
ListNode* insert_first(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//
    p->link = head;//(3)
    head = p;//(4)
    return head;//(5)
}

//노드 pre뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//(2)
    p->link = pre->link;//(3)
    p->link = p;//(4)
    return head;//(5)
}

//첫 노드 삭제
ListNode* delete_first(ListNode* head) {
    ListNode* removed;
    if (head == NULL) return NULL;
    removed = head;//(1)
    head = removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}

//pre가 가리키는 노드의 다음 노드 삭제
ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre->link;//(1)
    pre->link = removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}

//연결 리스트 출력
void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

//리스트를 역순으로 만드는 함수
ListNode* reverse(ListNode* head) {
    //순회 포인터로 p, q, r을 사용
    ListNode* p, * q, * r;

    p = head;//p는 역순으로 만들 리스트
    q = NULL;//q는 역순으로 만들 노드

    while (p != NULL) {
        r = q;//r은 역순으로 된 리스트
        q = p;
        p = p->link;
        q->link = r;//q의 링크 방향을 바꾼다.
    }
    return q;
}

//테스트 프로그램
int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    printf("기존 리스트\n");
    print_list(head1);

    head2 = reverse(head1);
    printf("역순 리스트\n");
    print_list(head2);

    return 0;
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/f2a106f7-af22-47a7-8cfc-f8fe15178d96)

---

## [연결 리스트의 응용: 다항식](https://github.com/qlkdkd/DataStructure/blob/main/week10/PolynomialProgram/PolynomialProgram/FileName.c)
* 다항식을 단순 연결 리스트로 표현 가능한데, 각 항을 하나의 노드로 표현하면 다음과 같다.
	* 계수: coef
 	* 지수: expon
    	* 다음 항: link
       
```c
typedef struct ListNode{
	int coef;
	int expon;
	struct ListNode *link;
}ListNode;
```

* 각 다항식은 다항식의 첫 번째 항을 가리키는 포인터로 표현된다.
```c
ListNode *A, *B;
```

예를 들어 다항식 $A(x)=3x^{12}+2x^8+1$과 $B(x)=8x^{12}-3x^{10}+10x^6$은 다음과 같이 표현된다.
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/1456b2b6-d94d-4344-b72e-9aeb5ea9d80f)

* 2개의 다항식을 더하는 덧셈 연산 $C(x)=A(x)+B(x)$를 구현해 보자. 참고로 앞의 다항식A(x)와 B(x)를 더하면 다음과 같다.
$$(3x^{12}+2x^8+1)+(8x^{12}-3x^{10}+10x^6)=11x^{12}-3x^{10}+2x^8+10x^6+1$$

* 다항식이 연결 리스트로 표현되어 있기 때문에 포인터 변수 p와 q를 이용하여 다항식 A와 B의 항들을 따라 순회하면서 각 항들을 더하면 된다. p와 q가 가리키는 항의 지수에 따라 3가지 경우로 나누어 처리할 수 있다.
1. p.expon==q.expon: 두 계수를 더해서 0이 아니면 새로운 항을 만들어 결과 다항식 C에 추가한다. 그리고 p와q는 모두 다음 항으로 이동한다.
2. p.expon<q.expon: q가 지시하는 항을 새로운 항으로 복사하여 결과 다항식 C에 추가한다. 그리고 q만 다음 항으로 이동한다.
3. p.expon>q.expon: p가 지시하는 항을 새로운 항으로 복사하여 결과 다항식 C에 추가한다. 그리고 p만 다음 항으로 이동한다.
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/64a0347d-2c35-437e-9664-d6c15221cb84)
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/20a2646b-f90b-4084-b4e1-89c281272978)
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/c048430e-b1d4-4ea0-828d-d1230b48dd84)

* 위의 과정들을 q나 q 둘 중에서 어느 하나가 NULL 이 될 때 까지 되풀이한다. p나 q 중에서 어느 하나가 NULL이 되면 아직 남아 있는 항들을 전부 C로 가져오면 된다.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { // 노드 타입
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;

// 연결 리스트 헤더
typedef struct ListType { // 리스트 헤더 타입
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//  리스트 헤더 생성 함수
ListType* create()
{
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, 
// expon는 지수
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp =
		(ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

// list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {   // a의 차수 > b의 차수
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {  // a의 차수 == b의 차수 
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {					// a의 차수 < b의 차수
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	// a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 
	// 결과 다항식으로 복사
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

//
//
void poly_print(ListType* plist)
{
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%d^%d + ", p->coef, p->expon);
	}
	printf("\n");
}

//
int main(void)
{
	ListType* list1, * list2, * list3;

	// 연결 리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();

	// 다항식 1을 생성 
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	// 다항식 2를 생성 
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	// 다항식 3 = 다항식 1 + 다항식 2
	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1); free(list2); free(list3);
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/ef5875a8-2149-47ec-943c-531aec6474c1)
