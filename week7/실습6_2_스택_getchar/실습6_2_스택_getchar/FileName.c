#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<malloc.h>

typedef char element;
typedef struct {
	element* data;//data는 포인터
	int capacity;
	int top;
}StackType;

//스택 생성 함수
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = -1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

//삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity * 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

//삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main() {
	int i, j;
	element e;
	StackType s;
	init_stack(&s);

	for (i = 0; ; i++) {
		e = getchar();
		if (e == '\n') break;
		push(&s, e);
	}
	printf("-----------------\n");
	for (j = 0; j < i; j++) {
		e = pop(&s);
		putchar(e);
	}
	return 0;
}