# 연결 리스트로 구현한 스택
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/e64291ad-078b-45cb-bc62-83399b95b2e9)
* 연결된 스택(linked stack): 연결리스트를 이용하여 구현한 스택
* 장점: 크기가 제한되지 않음, 동적 메모리 할당만 할 수 있다면 스택에 새로운 요소를 삽입할 수 있게함
* 단점: 동적 메모리 할당이나 해제를 해야하므로 삽입/삭제 연산 시간은 조금 더 걸림

* 연결된 스택은 기본적으로 연결 리스트
* 노드는 우리가 저장하고 싶은 데이터 필드와 다음 노드를 가리키기 위한 포인터가 들어있는 링크 필드로 구성
* top은 더이상 정수가 아닌 노드를 가리키는 포인터로 선언
    * 연결된 스택에 관련된 데이터는 top포인터 뿐이지만 일관성을 위하여 LinkedStackType이라는 구조체 타입으로 정의
        * 모든 함수들은 이 구조체의 포인터를 매개변수로 받아 사용

## 연결된 스택 구조체 선언
```c
typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
}StackNode;

typedef struct {
	StackNode* top;
}LinkedStackType;
```

## 삽입 연산
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/173bc2e5-86b9-4cc1-ada7-e7995467a1c8)
* 연결된 스택은 단순 연결 리스트에서 맨 앞에 데이터를 삽입하는 것과 동일
* 먼저 동적 메모리 할당으로 노드를 만들고 이 노드를 첫 번째 노드로 삽입
* 위 그림과 같이 top의 값을 temp-->link에 복사
```c
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}
```

## 삭제 연산
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/5a2e5b20-65c0-4036-a24a-ad34d677b3fb)
* top의 값을 top->link로 바꾸고
* 기존의 top이 가리키는 노드를 동적 메모리 해제하면 됨
```c
element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
```

## 테스트 프로그램
```c
#include<stdio.h>
#include<malloc.h>

typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
}StackNode;

typedef struct {
	StackNode* top;
}LinkedStackType;

//초기화 함수
void init(LinkedStackType* s) {
	s->top = NULL;
}

//공백 상태 검출 함수
int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}

//포화 상태 검출 함수
int is_full(LinkedStackType* s) {
	return 0;
}

//삽입 함수
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

//삭제함수
element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

//피크 함수
element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else return s->top->data;
}

//출력함수
void print_stack(LinkedStackType* s) {
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d-> ", p->data);
	printf("NULL\n");
}

//메인함수
int main() {
	LinkedStackType s;
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);

	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	return 0;
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/8413f589-2f97-47ff-bdd7-c2dc351e9f08)

---

# 연결 리스트로 구현한 큐
* 연결된 큐(linked queue): 연결 리스트로 구현된 큐
* 장점: 배열로 구현된 큐에 비해 크기가 제한되지 않음
* 단점: 배열로 구현된 큐에 비해 코드가 약간 더 복잡해지고 링크필드 때문에 메모리 공간을 더 많이 사용함

* 기본적인 구조: 단순 연결 리스트에다가 2개의 포인터를 추가함
    * front포인터는 맨 앞에 있는 요소를 가리키며 삭제와 관련, rear포인터는 맨 뒤에 있는 요소를 가리키며 삽입과 관련
* 큐에 요소가 없을 경우 front와 rear는 NULL값이 됨
* 큐의 요소들은 구조체로 정의
    * 데이터를 저장하는 data필드와 다음 노드를 가리키기 위한 포인터가 들어있는 link필드로 구성
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/e04bb61d-97c2-4806-86ca-918837c3da9a)

## 연결된 큐의 정의
```c
typedef int element;//요소의 타입
typedef struct QueueNode {
	element data;
	struct QueueNode* link
}QueueNode;
typedef struct {
	QueueNode* front, * rear;
}LinkedQueueType;
```

## 삽입 연산
* 동적 메모리 할당을 통하여 새로운 노드 생성
* 데이터를 저장하고 연결 리스트의 끝에 새로운 노드를 추가
* 만약 큐가 공백상태이면(즉 front와 rear가 모두 NULL이면): front와 rear 모두 새로운 노드를 가리키도록 함
* 만약 큐가 공백상태가 아니고 기존 노드가 있는 경우: rear가 가리키고 있는 노드의 링크필드와 rear를 새로운 노드를 가리키도록 변경
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/88386d31-6f68-4815-b0c8-a4c100126ff8)
```c
void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;//데이터 저장
	temp->link = NULL;//링크 필드 NULL을 가리키도록 함
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}
```

## 삭제 연산
* 삭제 연산은 연결리스트의 처음에서 노드를 꺼내오면 됨
* 먼저 큐가 공백상태인지를 검사
    * 공백상태이면 오류 발생
* 큐가 공백상태가 아니면
    * front가 가리키는 노드를 temp가 가리키도록 하고
    * front는 front의 링크값으로 대입
    * front는 현재 가리키는 노드의 다음 노드를 가리킴
    * temp가 가리키는 노드로부터 데이터를 꺼내오고 동적 메모리 해제를 통하여 이 노드를 삭제
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/77de97f8-aea5-4b0d-8d36-21b6a7997b8b)
```c
#include<stdio.h>
#include<stdlib.h>

typedef int element;//요소의 타입
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}QueueNode;
typedef struct {
	QueueNode* front, * rear;
}LinkedQueueType;

//큐 초기화 함수
void init(LinkedQueueType* q) {
	q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(LinkedQueueType* q) {
	return (q->front == NULL);
}

//포화 상태 검출 함수
int is_full(LinkedQueueType* q) {
	return 0;
}

//삽입함수
void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;//데이터 저장
	temp->link = NULL;//링크 필드 NULL을 가리키도록 함
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}

//삭제함수
element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		data = temp->data;//데이터 꺼내기
		q->front = q->front->link;//front로 다음 노드
		if (q->front == NULL)//공백상태
			q->rear = NULL;
		free(temp);//동적 메모리 해제
		return data;//데이터 반환
	}
}

//출력함수
void print_queue(LinkedQueueType* q) {
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link) {
		printf("%d-> ", p->data);
	}
	printf("NULL\n");
}


int main() {
	LinkedQueueType queue;

	init(&queue);

	enqueue(&queue, 1); print_queue(&queue);
	enqueue(&queue, 2); print_queue(&queue);
	enqueue(&queue, 3); print_queue(&queue);

	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);

	return 0;
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/151059b2-028a-42e7-8e9e-1da19e1c0b43)
