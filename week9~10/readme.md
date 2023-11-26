# 연결 리스트1

# 리스트 추상 데이터 타입
## 리스트의 소개
* 리스트: 우리들이 자료를 정리하는 방법 중의 하나
* 일상생활에서의 리스트
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/f4a48a5c-643a-41c2-8ac3-850b89731f68)

## 리스트의 기본 연산
$$L=(item_0, item_1, item_2,...,item_{n-1}$$

### 연산 목록
* 리스트에 새로운 항목을 추가(삽입 연산)
* 리스트에 항목을 삭제(삭제 연산)
* 리스트에서 특정한 항목 찾기(탐색 연산)

## 리스트의 ADT
```
객체: n개의 element형으로 구성된 순서 있는 모임
연산:
    insert(list, pos, item)::=pos위치에 요소를 추가
    insert_last(list, item)::=맨 끝에 요소를 추가
    insert_first(list, item)::=맨 처음에 요소를 추가
    delete(list, pos)::=pos위치에 요소를 제거한다.
    clear(list)::=리스트의 모든 요소를 제거
    get_entry(list, pos)::=pos위치의 요소를 반환
    get_length(list)::=리스트의 길이를 구한다.
    is_empty(list)::=리스트 공백 검사
    is_full(list)::=리스트 포화 검사
    print_list(list)::리스트 요소 출력
```
## 리스트의 구현
* 배열과 연결 리스트를 이용하여 구현
* 배열
    * 장점: 리스트 ADT를 가장 간단하게 구현할 수 있음
    * 단점: 크기가 고정됨
    * 메모리 공간이 부족하면 더 큰 배열을 만들어 기존 배열의 데이터를 복사하면 되지만 cpu 시간을 낭비함
    * 리스트에 새로운 데이터를 삽입하거나 삭제하기 위해서는 기존의 데이터들을 이동하여야 함
* 연결 리스트: 포인터를 이용하여 만듬. 필요할 때마다 중간에 속지를 추가해서 사용할 수 있는 바인더 공책과 비슷
    * 장점: 중간에 쉽게 삽입하거나 삭제할 수 있는 유연한 리스트를 구현할 수 있음
    * 단점: 구현이 복잡하고, 임의의 항목(i번째 항목)을 추출하려고 할 때는 배열을 사용하는 방법보다 시간이 많이 걸
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/3730b95f-79a7-4a00-9c49-250aa8c3b2c2)

## 배열로 구현된 리스트
* 배열을 이용하여 리스트를 구현하면 순차적인 메모리 공간이 할당되므로, 이것을 리스트의 순차적 표현(sequential representation)이라고도 한다.
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/16484550-f7b9-441f-9df6-da998c2d497e)

## 리스트의 정의(ArrayListType의 구현)
배열로 리스트를 구현하기 위하여 배열과 항목의 개수를 구조체로 묶어서 ArrayListType이라는 새로운 타입을 정의하도록 하자
```c
#define MAX_LIST_SIZE 100//리스트의 최대 크기
typedef int element;//항목의 정의
typedef struct{
    element array[MAX_LIST_SIZE];//배열의 정의
    int size;//현재 리스트에 저장된 항목들의 개수
}ArrayListType;
```

## 기초 연산
```c
#include<stdio.h>
#include<stdlib.h>

#define MAX_LIST_SIZE 100//리스트의 최대 크기
typedef int element;//항목의 정의
typedef struct {
    element array[MAX_LIST_SIZE];//배열의 정의
    int size;//현재 리스트에 저장된 항목들의 개수
}ArrayListType;

//오류처리 함수
void error(char* message) {
    fprintf(stderr, " %s\n", message);
}

//리스트 초기화 함수
void init(ArrayListType* L) {
    L->size = 0;
}

//리스트 공백 검사 함수
//리스트가 비어있으면 1을 반환
//그렇지 않으면 0을 반환
int is_empty(ArrayListType* L) {
    return L->size == 0;
}

//리스트 포화 검사 함수
//리스트가 가득 차있으면 1을 반환
//그렇지 않으면 0을 반환
int is_full(ArrayListType* L) {
    return L->size == MAX_LIST_SIZE;
}

//리스트 위치 반환 함수
element get_entry(ArrayListType* L, int pos) {
    if(pos < 0 || pos >= L->size)
        error("위치 오류");
    printf("\n");
}

//리스트 출력
void print_list(ArrayListType* L) {
    int i;
    for (i = 0; i < L->size; i++)
        printf("%d-> ", L->array[i]);
    printf("\n");
}
```

## 항목 추가 연산
### insert_last(): 리스트의 맨 끝에 항목을 추가
```c
//항목 추가 연산
void insert_last(ArrayListType* L, element item) {
    if (L->size >= MAX_LIST_SIZE)
        error("리스트 오버플로우");
    L->array[L->size++] = item;
}
```
* insert_last()함수에서는 리스트에 빈 공간이 없으면 오류를 발생시킴

### insert(): 리스트의 특정 위치에 항목을 추가
* 리스트의 pos위치에 새로운 항목 추가하는 방법: pos번째부터 마지막 항목까지 한 칸씩 오른쪽으로 이동하여 빈 자리를 만든 후에, 새로운 항목을 pos위치에 저장
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/22030b10-8f0b-4db0-a58a-36d410fd02e8)

```c
//특정(pos)위치에 항목 추가 연산
void insert(ArrayListType* L, int pos, element item) {
    //pos번째부터 마지막 항목까지 한칸씩 오른쪽으로 이동
    if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
        for (int i = (L->size - 1); i >= pos; i--)
            L->array[i + 1] = L->array[i];
        //pos번째 위치에 항목 삽입
        L->array[pos] = item;
        L->size++;
    }
}
```

## 항목 삭제 연산
### delete(list, pos): pos위치에 있는 항목 삭제
* insert()함수처럼 삭제한 후에 array[pos+1]부터 array[size-1]까지를 한칸씩 앞으로 이동
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/5787c3eb-372b-438a-a2a8-fdac38b15af9)
```c
//항목 삭제 연산
//특정(pos)위치에 항목 삭제 연산
element delete(ArrayListType* L, int pos) {
    element item;
    //위치 오류
    if (pos < 0 || pos >= L->size)
        error("위치 오류");
    item = L->array[pos];
    for (int i = pos; i < (L->size - 1); i++)
        L->array[i] = L->array[i + 1];
    L->size--;
    return item;
}
```

## [테스트 프로그램]()
``` c
//테스트 프로그램
int main() {
    //ArrayListType를 정적으로 생성하고 ArrayListType를
    //가리키는 포인터를 함수의 매개변수로 전달한다.

    ArrayListType list;

    init(&list);
    insert(&list, 0, 10); print_list(&list);//0번째 위치에 10 추가
    insert(&list, 0, 20); print_list(&list);//0번째 위치에 20 추가
    insert(&list, 0, 30); print_list(&list);//0번째 위치에 30 추가
    insert_last(&list, 40); print_list(&list);//맨 끝에 40 추가
    delete(&list, 0); print_list(&list);//0번째 항목 삭제

    return 0;
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/5e14b167-e3ce-4e35-b6f3-10ff94207382)

---

# 연결 리스트
* 연결된 표현: 포인터를 사용하여 데이터들을 연결
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/1ff410c4-82f2-49b9-8e2e-8eaa38f28fe6)

* 데이터들은 메인 메모리상의 어디에나 흩어져서 존재할 수 있음
    * 이런 식으로 물리적으로 흩어져 있는 자료들을 서로 연결하여 하나로 묶는 방법을 연결 리스트(linked list)라고 함
    * 상자를 연결하는 줄은 포인터로 구현
* 연결 리스트의 장점
    * 중간에 항목을 삽입할 때 앞뒤에 있는 데이터들을 이동할 필요가 없이 줄만 변경시켜주면 됨
    * 삭제 시에도 데이터를 연결하는 줄만 수정해주면 됨
    * 데이터를 저장할 공간이 필요할 때마다 동적으로 공간을 만들어서 쉽게 추가할 수 있음
* 연결 리스트의 단점
    * 구현이 어렵고 오류가 발생하기 쉬움
    * 데이터뿐만 아니라 포인터도 저장하여야 하므로 메모리 공간을 많이 사용
    * i번째 데이터를 찾으려면 앞에서부터 순차적으로 접근해야 함

![image](https://github.com/qlkdkd/DataStructure/assets/71871927/29c6c085-51bf-4de3-b6d4-dd6cc789f267)
* 하나의 프로그램 안에는 동시에 여러 개의 연결 리스트가 존재할 수 있음
* 연결 리스트들을 구별하는 것은 첫 번째 데이터: 첫 번째 데이터만 알 수 있으면 연결 리스트의 나머지 데이터들은 줄만 따라가면 얻을 수 있다.

## 연결 리스트의 구조
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/49eff8b0-996c-4e3c-9297-0e30b43a7509)
* 링크 필드에는 다른 노드를 가리키는 포인터가 저장됨: 데이터는 정수가 될 수 있고 구조체와 같은 복잡한 데이터가 될 수도 있다.
* 이 포인터를 이용하여 다음 노드로 건너갈 수 있음.
* 연결 리스트에서는 연결 리스트의 첫 번째 노드를 알아야 만이 전체의 노드에 접근할 수 있다.
    * 헤드 포인터(head pointer): 첫번째 노드를 가리키고 있는 변수
* 마지막 노드의 링크필드는 NULL으로 설정: 더 이상 연결된 노드가 없다는 것을 의미
* 연결 리스트의 노드들은 필요할 때마다 malloc()을 이용하여 동적으로 생성됨.
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/7dc8f49e-fa1b-4934-b357-5f4954235b11)

## 연결 리스트의 종류
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/dac5c1ee-57b1-4445-bd0b-f646a06e6bb7)
* 단순 연결 리스트(singly linked list): 하나의 방향으로만 연결되어 있는 연결 리스트. 체인(chain)이라고도 함
    * 마지막 노드의 링크는 NULL값으로 설정
* 원형 연결 리스트(circular linked list): 마지막 노드의 링크가 첫 번째 노드를 가리킴
* 이중 연결 리스트(doubly linked list): 각 노드마다 2개의 링크가 존재
    * 하나의 링크는 앞에 있는 노드를 가리키고 또 하나의 링크는 뒤에 있는 노드를 가리킴
 
---

# 단순 연결 리스트
* 노드들이 하나의 링크 필드를 가짐
    * 이 링크 필드를 이용하여 모든 노드들이 연결되어 있음
    * 마지막 노드의 링크 필드 값은 NULL이 됨
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/51b5f293-1def-414a-b212-d0b120ee6188)


## 노드의 정의
> * 노드는 어떻게 정의할 것인가?: 자기 참조 구조체를 이용한다.
> * 노드는 어떻게 생성할 것인가?: malloc()을 호출하여 동적 메모리로 생성한다.
> * 노드는 어떻게 삭제할 것인가?: free()를 호출하여 동적 메모리를 제거한다.

* 노드는 자기 참조 구조체를 이용하여 정의됨
    * 자기 참조 구조체: 자기 자식을 참조하는 포인터를 포함하는 구조체
* 구조체 안에는 데이터를 저장하는 data 필드와 포인터가 저장되어 있느 link필드가 존재
* data 필드는 element 타입의 데이터를 저장하고 있음
* link필드는 ListNode를 가리키는 포인터로 정의됨
```c
typedef int element;

//자기참조 구조체
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;
```

## 노드의 생성
* 일반적으로 연결 리스트에서는 필요할 때마다 동적 메모리 할당을 이용하여 노드를동적으로 생성
```c
head=(ListNode *)malloc(sizeof(ListNode));
```
* 위의 코드까지 실행되면 아래 그림처럼 노드가 하나 생성됨. 아직 노드에는 아무것도 채워지지 않음
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/9cddfef6-5966-4c30-91cc-49a9a329b502)

* 새로 만들어진 노드에 데이터를 저장하고 링크필드를 NULL로 설정하기
```c
head->data=10;
head->link=NULL;
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/a3ef9825-ce3f-4aef-a0a0-d86fde5c0b0c)

## 노드의 연결
* 일반적으로 연결 리스트에는 여러 개의 노드가 서로 연결됨

* 2번째 노드 생성
```c
ListNode *p;
p=(ListNode *)malloc(sizeof(ListNode));
p->data=20;
p->link=NULL;
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/58e841d3-cb17-4b75-b66b-af1b5d3f9831)

* 생성된 2개의 노드 생성
```c
head->link=p;//첫 번째 노드: head, 두 번째 노드: p
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/a5466126-05e4-44dc-a026-c301b6be73bf)

---

# 단순 연결 리스트의 연산 구현
> * insert_first(): 리스트의 시작 부분에 항목을 삽입하는 함수
> * insert(): 리스트의 중간 부분에 항목을 삽입하는 함수
> * delete_first(): 리스트의 첫 번째 항목을 삭제하는 함수
> * delete(): 리스트의 중간 항목을 삭제하는 함수
> * print_list(): 리스트를 방문하여 모든 항목을 출력하는 함수

## 단순연결 리스트의 정의
```c
ListNode *head;
```

## 삽입 연산
### insert_first: 리스트의 시작 부분에 항목을 삽입하는 함수
```c
ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
	p->data = value;//(2)

	p->link = head;//(3)
	head = p;//(4)
	return head;
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/0f493a3a-071a-4e96-ba99-1aa2e494a858)
1. 동적 메모리 할당을 통하여 새로운 노드 p 생성
2. p->data에 value를 저장
3. p->link를 현재의 head값으로 변경한다.
4. head를 p값으로 변경
5. 변경된 헤드포인터 반환

### insert(): 리스트의 중간 부분에 항목을 삽입하는 함수
```c
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
	p->data = value;//(2)
	p->link = pre->link;//(3)
	pre->link = p;//(4)
	return head;//(5)
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/1107185f-715c-4f5e-b43d-5189243b0b77)
1. 새로운 노드를 생성하여 변수 p에 저장
2. p의 데이터 필드에 value 저장
3. p의 링크필드가 노드 pre를 가리키도록 변경
4. pre의 링크필드가 p를 가리키도록 하기
5. 변경된 헤드포인터 저장

## 삭제 연산
### delete_first(): 리스트의 첫 번째 항목을 삭제하는 함수
```c
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;//1
	head = removed->link;//2
	free(removed);//3
	return head;//4
}
```

![image](https://github.com/qlkdkd/DataStructure/assets/71871927/ed3a1a77-88e1-4f03-b455-ddeaa17abfff)

1. 헤드 포인터의 값을 removed에 복사
2. 헤드 포인터의 값을 head->link로 변경
3. removed가 가리키는 동적 메모리를 반환
4. 변경된 헤드포인터를 반환
### delete():  리스트의 중간 부분의 항목을 삭제하는 함수
```c
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;//2
	free(removed);//3
	return head;//4
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/5d7f6341-c07f-4d3d-a26d-d8183a2b49c1)
1. 삭제할 노드 찾기
2. 헤드노드의 링크 필드가 pre노드를 가리키게 하기
3. 삭제할 노드의 동적 메모리 반납
4. 변경된 헤드포인터 반환

## print_list()리스트를 출력하는 함수
* 노드의 링크값이 NULL이 아니면 계속 링크를 따라 가면서 노드를 방문함
```c
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d-> ", p->data);
	printf("NULL\n");
}

```

## [테스트 프로그램]()
```c
int main() {
	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/77e16b2c-b388-4942-8171-42d353fce1e0)

---

# Lab: 단어들을 저장하고 있는 연결 리스트
```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//이번에는 element 를 배열을 포함하고 있는 구조체로 정의
typedef struct {
	char name[100];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

//오류처리 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//삽입
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

//출력
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%s-> ", p->data.name);
	}
	printf("NULL\n");
}

int main() {
	ListNode* head = NULL;
	element data;

	strcpy(data.name, "apple");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "kiwi");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "banana");
	head = insert_first(head, data);
	print_list(head);

	return 0;
}
```

![image](https://github.com/qlkdkd/DataStructure/assets/71871927/69100b69-db34-427f-8bb3-c0bdaf5f86c1)
