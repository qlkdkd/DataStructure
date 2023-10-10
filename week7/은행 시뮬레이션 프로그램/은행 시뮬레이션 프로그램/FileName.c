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