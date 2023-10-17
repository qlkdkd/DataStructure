[실습: 스택](https://github.com/qlkdkd/DataStruct/blob/main/week7/%EC%8B%A4%EC%8A%B56_%EC%8A%A4%ED%83%9D.md)
# 5장. 큐(Queue)
## 큐
* 큐: 먼저 들어온 데이터가 먼저 나가는 자료구조
* **선입선출(FIFO: First In First Out)**
* (예) 매표소의 대기열
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/60814157-abcb-4ece-ba8d-49ae2fcefec9)

## 큐 ADT
```
* 객체 0개 이상의 요쇼들로 구성된 선형 리스트
* 연산
creare(max_size)::=
  최대 크기가 max_size인 공백큐를 생성한다.

init(q)::=
  큐를 초기화한다.

is_empty(q)::=
  if(size==0) return TRUE;
  else return FALSE;

is_full(q)::=
  if(size==max_size) return TRUE;
  else return FALSE;

enqueue(q, e)::=
  if(is_full(q) queue_fall 오류;
  else q의 끝에 e를 추가한다.

dequeue(q)::=
  if(is_empty(q)) queue_empty 오류;
  else q의 맨 앞에 e를 제거하여 반환한다.

peek(q)::=
  if(is_empty(q)) queue_empty 오류;
  else q의 맨 앞에 있는 e를 읽어서 반환한다.
```

## 큐의 삽입, 삭제 연산
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/5456d440-5439-4a9f-a067-2ed691106ef7)

## 큐의 응용
* 직접적인 응용
    * 시뮬레이션의 대기열(공항에서의 비행기들, 은행에서의 대기열)
    * 통신에서의 데이터 패킷들의 모델링에 이용
    * 프린터와 컴퓨터 사이의 버퍼링: 프린터가 cpu보다 느리기 때
* 간접적인 응용
    * 스택과 마찬가지로 프로그래머의 도구
    * 많은 알고리즘에서 사용됨

## 선형큐
* 배열을 선형으로 사용하여 큐를 구현
    * 삽입을 계속하기 위해서는 요소들을 이동시켜야 함.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f158eafb-2432-4f15-ab35-eea7be78e79b)
a. 초기상태: 삽입, 삭제를 위한 변수인 front(맨앞)와 rear(맨뒤)을 만든다.
b. enqueue(3): [0]번 배열에 3이 들어간다. rear은 [0]번 배열에 위치한다.
c. enqueue(7): rear에 7이 들어가고 front에 3이 들어간다.
d. enqueue(5): [2]번 배열에 5가 들어간다.
e. dequeue(): 배열에 3과 7이 나간다. front가 [0]번 배열로 이동한다.
f. dequeue(): front가 [1]번 배열로 이동한다.

[코드 보기](https://github.com/qlkdkd/DataStruct/blob/main/week7/%EC%84%A0%ED%98%95%ED%81%90/%EC%84%A0%ED%98%95%ED%81%90/FileName.c)
```
#include<stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {//큐타입
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q) {
	q->rear = -1;
	q->front = -1;
}

void queue_print(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf(" | ");
		else
			printf("%d |", q->data[i]);
	}
	printf("\n");
}

int is_full(QueueType* q) {
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else return 0;
}

int is_empty(QueueType* q) {
	if (q->front == q->rear)return 1;
	else return 0;
}

void enqueue(QueueType* q, int item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main() {
	int item = 0;
	QueueType q;

	init(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);

	return 0;
}
```

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/ded61e96-b207-4fbb-968c-29f5be1880d6)

## 선형 큐의 응용: 작업 스케줄링
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/bbddf2d6-1899-49d3-8f51-9a5bc6a90832)

---

## 원형큐
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/e9cedd41-d333-4490-af0b-b489765baffc)
* 기존 선형큐의 문제점: front와 rear의 값에 계속 증가만 하기 때문에 언젠가는 배열의 끝에 도달하게 되고 배열의 앞부분이 비어 있더라도 사용하지를 못한다. 따라서 주기적으로 모든 요소들을 왼쪽으로 이동시켜야 한다.
* 해결 방법: front와 rear의 값이 배열의 끝인 (MAX_QUEUE_SIZE-1)에 도달하면 다음에 증가하는 값은 0이 되도록 한다.
### 원형큐에서의 front와 rear의 개념
* 초기값: -1 -> 0
* front는 항상 큐의 첫번째 요소의 하나 앞을, rear는 마지막 요소를 가리킴
* 처음에 front, rear은 모두 0이고, 삽입 시 rear가 먼저 증가하고, 증가된 위치에 새로운 데이터가 삽입된다.
* 삭제 시에는 front가 먼저 증가된 다음, 증가된 위치에서 데이터를 삭제한다.

## 원형큐의 구조
* 큐의 전단과 후단을 관리하기 위한 2개의 변수 필요
    * front: 첫 번째 요소 하나 앞의 인덱스
    * rear: 마지막 요소의 인덱스
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/a602beae-130c-409a-a285-fa98997c0a0e)

## 원형큐의 동작
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/57776888-03d6-4e1d-b56e-71539b141536)
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/e7de7133-5d61-4af8-8123-1382f4e529bd)
* 공백 상태: `front==rear`
* 포화상태: `front%M==(rear+1)%M`
* 공백상태화 포화상태를 구별하기 위하여 하나의 공간은 항상 비워둔다.
    * 한 자리를 비워주지 않는다면 (c) 오류상태 처럼 되어 공백 상태와 포화 상태를 구별할 수가 없다.
* 만약 요소들의 개수를 저장하고 있는 추가적인 변수 `count` 변수를 사용할 수 있다면 한 자리를 비워두지 않아도 된다.
## [원형큐 코드](https://github.com/qlkdkd/DataStruct/blob/main/week7/%EC%9B%90%ED%98%95%ED%81%90/%EC%9B%90%ED%98%95%ED%81%90/FileName.c)
```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//원형큐 코드 시작
#define max_queue_size 5
typedef int element;
typedef struct {//큐타입
	element data[max_queue_size];
	int front, rear;
}QueueType;

//오류함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//공백 상태 검출 함수
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

//공백 상태 검출 함수(공백 상태: front==rear)
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//포화 상태 검출 함수(front%M==(rear+1)%M
int is_full(QueueType* q) {
	return((q->rear + 1) % max_queue_size == q->front);
}

//원형 큐 출력 함수
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d, rear=%d)=", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (max_queue_size);
			printf("%d| ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
}

//삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % max_queue_size;
	q->data[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % max_queue_size;
	return q->data[q->front];
}

//원형 큐 코드 종료

int main() {
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue)){
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("꺼내진 정수: %d\n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}
```

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/a2428527-a313-42ab-beae-bdfa8443e146)

## 큐의 응용: 버퍼
### 큐의 사용처
* 생산자-소비자 프로세스: 큐를 버퍼로 사용한다.
* 교통 관리 시스템: 컴퓨터로 제어되는 신호등에서는 신호등을 순차적으로 제어하는데 원형큐가 사용된다.
* CPU 스케줄링: 운영체제는 실행 가능한 프로세스들을 저장하거나 이벤트를 기다리는 프로세스들을 저장하기 위하여 몇 개의 큐를 사용한다.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/9418ceec-9da8-4353-8a00-4962fd70f44f)

## [큐 응용 프로그램](https://github.com/qlkdkd/DataStruct/blob/main/week7/%ED%81%90%20%EC%9D%91%EC%9A%A9%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%ED%81%90%20%EC%9D%91%EC%9A%A9%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/FileName.c)
```c
#include<stdio.h>
#include<stdlib.h>

//원형큐 코드 시작
#define max_queue_size 5
typedef int element;
typedef struct {//큐타입
	element data[max_queue_size];
	int front, rear;
}QueueType;

//오류함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//공백 상태 검출 함수
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

//공백 상태 검출 함수(공백 상태: front==rear)
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//포화 상태 검출 함수(front%M==(rear+1)%M
int is_full(QueueType* q) {
	return((q->rear + 1) % max_queue_size == q->front);
}

//원형 큐 출력 함수
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d, rear=%d)=", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (max_queue_size);
			printf("%d| ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

//삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % max_queue_size;
	q->data[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % max_queue_size;
	return q->data[q->front];
}
//원형큐 코드 종료

int main() {
	QueueType queue;
	int element;

	init_queue(&queue);
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0) {//5로 나누어 떨어지면 수 추가
			enqueue(&queue, rand() % 100);
		}
		queue_print(&queue);

		if (rand() % 10 == 0) {//10으로 나누어 떨어지면 수 제거
			int data = dequeue(&queue);
		}
		queue_print(&queue);
	}

	return 0;
}
```

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/9ebf47d0-c3b3-4616-979e-e8ef23cff550)

---

## 덱(deque)
* 덱(deque)은 **double-ended queue**의 줄임말로서 큐의 전단(front)와 후단(rear)에서 모두 삽입과 삭제가 가능한 큐를 의미한다.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/3404f92e-6ca6-4439-91a5-d0ffb3d0e0b8)

## 덱의 추상 자료형
> * 객체: n개의 element형으로 구성된 요소들의 순서있는 모임
> * 연산
> create()::= 덱을 생성한다.
> init(dq)::= 덱을 초기화한다.
> is_empty(dq)::= 덱이 공백상태인지를 검사한다.
> is_full(dq)::= 덱이 포화상태인지를 확인한다.
> add_front(dq, e)::= 덱의 앞에 요소를 추가한다.
> add)rear(dq, e)::= 덱의 뒤에 요소를 추가한다.
> delete_front(dq)::= 덱의 앞에 있는 요소를 반환한 다음 삭제한다.
> delete_rear(dq)::= 덱의 뒤에 있는 요소를 반환한 다음 삭제한다.
> get_front(q)::= 덱의 앞에서 삭제하지 않고 앞에 있는 요소를 반환한다.
> get_rear(q)::= 덱의 뒤에서 삭제하지 않고 뒤에 있는 요소를 반환한다.

## 덱의 연산
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/ce650467-253f-4ad6-ab0d-e2b99ead9af8)
* 덱은 스택과 큐의 연산들을 모두 가지고 있다.
deque|stack|queue
---|---|---
add_front, delete_front|push, pop|
add_rear, delete_rear||enqueue, dequeue

* 추가로 덱은 get_front, get_rear, delete_rear 연산을 갖는다.

## 배열을 이용한 덱의 구현
원형 큐를 확장하면 덱도 손쉽게 구현할 수 있음. 덱도 원형 큐와 같이 전단과 후단을 사용함. 따라서 큐에서 사용한 배열 data와 front, rear를 그대로 사용하면 되고, 추가적인 데이터는 필요 없음
```c
#define max_deque_size 5
typedef int element
typedef struct{//덱 타입
  element data[max_deque_size];
  int front, rear;
}DequeType;
```
* 덱의 연산에는 원형 큐에서 그대로 사용할 수 있는 많은 연산들이 있음
* 추가된 연산: delete_rear(), add_front(), get_rear()
    * get_rear(): 공백상태가 아닌 경우 rear가 가리키는 항목 반환
    * delete_rear(), add_front(): 덱은 원형 큐와 다르게 반대 방향의 회전이 필요하다. front와 rear를 감소시켜야 하는데, 만약 음수가 되면 max_queue_size를 더해주어야 한다. 따라서 front나 rear는 아래와 같이 변경된다.

```c
front <- (front-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
rear <- (rear-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/470f6526-d08c-4bf8-a43c-e4610e7f962a)

## [덱 프로그램](https://github.com/qlkdkd/DataStruct/blob/main/week7/%EB%8D%B1/%EB%8D%B1/FileName.c)
```c
#include<stdio.h>
#include<stdlib.h>

//덱 코드 시작
#define max_queue_size 5
typedef int element;
typedef struct {//큐 타입
	element data[max_queue_size];
	int front, rear;
}DequeType;

//오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화
void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(DequeType* q) {
	return ((q->rear + 1) % max_queue_size == q->front);
}

//원형큐 출력 함수
void deque_print(DequeType* q) {
	printf("Deque(front=%d, rear=%d)=", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (max_queue_size);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

//삽입 함수
void add_rear(DequeType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear=(q->rear + 1) % max_queue_size;
	q->data[q->rear] = item;
}

//삭제 함수
element delete_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % max_queue_size;
	return q->data[q->front];
}

//삭제 함수
element get_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % max_queue_size];
}

void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("큐가 포화상태 입니다.");
	q->data[q->front] = val;
	q ->front = (q->front - 1 + max_queue_size) % max_queue_size;
}

element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->rear = (q->rear - 1 + max_queue_size) % max_queue_size;
	return q->data[prev];
}

element get_rear(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->rear];
}

int main() {
	DequeType queue;

	init_deque(&queue);
	for (int i = 0; i < 3; i++) {
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i < 3; i++) {
		delete_rear(&queue);
		deque_print(&queue);
	}

	return 0;
}
```

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/554bc1cd-1ba8-4021-9109-5d503baccacf)


## 큐의 응용: 시뮬레이션
* 큐잉 모델은 고객에 대한 서비스를 수행하는 서버와 서비스를 받는 고객들로 이루어진다.
* 은행에서 고객이 들어와서 서비스를 받고 나가는 과정을 시뮬레이션
    * 고객들이 기다리는 평균 시간을 계산
* 시뮬레이션은 하나의 반복 루프로 이루어진다.
    1. 현재 시각을 나타내는 `clock`이라는 변수를 하나 증가
    2. `is_customer_arrived`함수 호출한다. `is_customer_arrived`함수는 랜덤 숫자를 생성하여 시뮬레이션 파라미터 변수인 `arrival_prov`와 비교하여 작으면 새로운 고객이 들어왔다고 판단
    3. 고객의 아이디, 도착시간, 서비스 시간 등의 정보를 만들어 구조체에 복사하고 이 구조체를 파라미터로 하여 큐의 삽입 함수 `enqueue()`를 호출한다.
* 고객이 필요로 하는 서비스 시간은 역시 랜덤 숫자를 이용하여 생성된다.
* 
4. 지금 서비스하고 있는 고객이 끝났는지를 검사: 만약 `service_time`이 0이 아니면 어떤 고객이 지금 서비스를 받고 있는 중임을 의미한다.
5.  `clock`이 하나 증가했으므로 'service_time`을 하나 감소시킨다.
6. 만약 `service_time`이 0이면 현재 서비스받는 고객이 없다는 것을 의미한다. 따라서 큐에서 고객 구조체를 하나 꺼내어 서비스를 시작한다.

## [은행 시뮬레이션 프로그램](https://github.com/qlkdkd/DataStruct/blob/main/week7/%EC%9D%80%ED%96%89%20%EC%8B%9C%EB%AE%AC%EB%A0%88%EC%9D%B4%EC%85%98%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%9D%80%ED%96%89%20%EC%8B%9C%EB%AE%AC%EB%A0%88%EC%9D%B4%EC%85%98%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/FileName.c)
```c
#include<stdio.h>
#include<stdlib.h>

//원형큐 코드 시작
#define max_queue_size 5
typedef struct {//요소 타입
	int id;
	int arrival_time;
	int service_time;
}element;
typedef struct {//큐타입
	element data[max_queue_size];
	int front, rear;
}QueueType;



//오류함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//공백 상태 검출 함수
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

//공백 상태 검출 함수(공백 상태: front==rear)
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//포화 상태 검출 함수(front%M==(rear+1)%M
int is_full(QueueType* q) {
	return((q->rear + 1) % max_queue_size == q->front);
}

//원형 큐 출력 함수
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d, rear=%d)=", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (max_queue_size);
			printf("%d| ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
}

//삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % max_queue_size;
	q->data[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % max_queue_size;
	return q->data[q->front];
}

//원형큐 코드 종료



int main() {
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	QueueType queue;
	init_queue(&queue);

	//랜덤
	srand(time(NULL));

	//고객이 들어오고 나가는 반복 루프
	for (int clock = 0; clock < minutes; clock++) {
		//고객 입장
		if (rand() % 10 < 3) {
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("고객%d이(가) %d분에 들어옵니다. 업무처리시간: %d분\n",
				customer.id, customer.arrival_time, customer.service_time);
		}

		//고객 업무처리
		if(service_time > 0) {
			printf("고객 %d이(가) 업무처리 중입니다.\n", service_customer);
			service_time--;
		}

		//고객 퇴장
		else {
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("고객 %d 이(가) %d분에 업무를 시작합니다. 대기사간은 %d분이였습니다.\n",
					customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("전체 대기 시간=%d분\n", total_wait);
	return 0;
}
```

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/9e8679a8-408a-4f96-96cd-f9987b158a63)
