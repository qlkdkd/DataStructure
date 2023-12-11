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