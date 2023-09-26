#include<stdio.h>
#include<stdlib.h>
#define MAX_STACT_SIZE 100

typedef int element;
typedef struct {
	element* data; //data는 포인터로 정의된다.
	int capacity; //현재 크기
	int top;
}StackType;

//스택 생성 함수
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}


//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}


//포화상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

//스택 삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty Error\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main() {
	StackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	return 0;
}