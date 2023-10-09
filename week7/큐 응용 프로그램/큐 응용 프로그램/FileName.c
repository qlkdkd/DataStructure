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
