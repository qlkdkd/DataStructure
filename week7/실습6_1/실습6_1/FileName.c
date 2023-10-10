#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

#define n_students 4

typedef struct student_info {
	char name[10];
	int height;
	float weight;
}element;

typedef struct {
	element* data;//data은 포인터로 정의
	int capacity;
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
	return(s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

//삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
		//realloc: 메모리 재할당. size를 저장할 메모리가 커졌기 때문
	}
	s->data[++(s->top)] = item;
}

//삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main() {
	int i;
	element e;
	StackType s;
	init_stack(&s);

	for (i = 0; i < n_students; i++) {
		printf("이름: ");
		scanf("%s", e.name);
		printf("키: ");
		scanf("%d", &e.height);
		printf("몸무게: ");
		scanf("%f", &e.weight);

		push(&s, e);
	}
	for (i = 0; i < n_students; i++) {
		e = pop(&s);
		printf("%s, %d, %f \n", e.name, e.height, e.weight);
	}
	return 0;
}