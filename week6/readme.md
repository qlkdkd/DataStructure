[연습문제 보러가기](https://github.com/qlkdkd/DataStruct/blob/main/week6/practice.md)

### 수식의 계산
* 전위(prefix), 중위(infix), 후위(postfix)

|중위표기법|전위표기법|후위표기법|
|---|---|---|
|2+2*4|+2*34|234*+|
|a*b+5|+*ab5|ab*5+|
|(1+2)*7|*+127|12*7+|

* 컴퓨터에서의 수식 계산 순서
   * 중위표기식-> 후위표기식-> 계산
   * 2+3*4 -> 234*+ -> 13
   * 모두 스택을 사용
   * 먼저 후위표기식의 계산법을 알아보자

### 후위 표기식의 계산
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/693075fc-7d12-450d-ad54-9407b594929c)
* 수식을 왼쪽에서 오른쪽으로 스캔하여 피연산자이면 스택에 저장하고 연산자이면 필요한 수만큼의 피연산자를 스택에서 꺼내 연산을 실행하고 연산의 결과를 다시 스택에 저장
* (예) 82/3-32*+

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/df13dd8e-027a-431b-bee2-1a18c6fafbc6)

### 후위 표기식 계산 알고리즘

```
스택 s를 생성하고 초기화한다.
for 항목 in 후위표기식
  do if(항목이 피연산자이면)
    push(s, item)
  if(항목이 연산자 op이면)
    then second <- pop(s)
    result <- first op second //op는 +-*/ 중 하나
    push(s, result)
final_result <- pop(s);
```

### 후위표기식 계산
[후위표기식_계산.c](https://github.com/qlkdkd/DataStruct/blob/main/week6/%ED%9B%84%EC%9C%84%ED%91%9C%EA%B8%B0%EC%8B%9D_%EA%B3%84%EC%82%B0/%ED%9B%84%EC%9C%84%ED%91%9C%EA%B8%B0%EC%8B%9D_%EA%B3%84%EC%82%B0/FileName.c)
```c
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//차후에 스택이 필요하면 여기에 복사하여 붙인다.
//====스택 코드 시작====
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;


//스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}


//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}


//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}


//삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack Full Error\n");
		return;
	}
	else s->data[++(s->top)] = item;
}


//삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty Error\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}


//피크 함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty Error\n");
		exit(1);
	}
	else return s->data[s->top];
}

//====스택 코드의 끝====

int eval(char exp[]) {
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';//입력이 피연산자일때
			push(&s, value);
		}
		else { //연산자이면 피연산자를 스택에서 제거
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) { //연산을 수행하고 스택을 제거
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main() {
	int result;
	printf("후위 표기식은 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과값은 %d\n", result);
	return 0;
}
```

---

### 중위표기식 -> 후위표기식

* 중위표기와 후위표기
    * 중위표기법과 후위표기법의 공통점은 피연산자의 순서는 동일
    * 연산자들의 순서만 다름(우선순위순서)
  > 연산자만 스택에 저장했다가 출력하면 된다.
  > 2+3*4 -> 234*+

중위표기법|후위표기법
|---|---|
a+b|ab+
(a+b)*c|ab+c*
a+b*c|abc*

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/1d3a8698-f0fe-4ed1-bdf0-6f694591f2f6)

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/a839070e-f7ca-4af4-a503-61b1fbac9014)

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/a1f01621-03b5-491b-91f7-29b068660f17)

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/7e1d4b9f-b03f-4acd-a105-10638da04212)

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/defa80dc-4f4d-4203-a843-1c4cff3e029c)

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/b84ca241-6293-4a0b-9359-237db0942c56)

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/d28ea85c-d82b-4739-967a-5ccc001e5cbb)

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/7dbc645b-2694-427d-9163-45d071c57349)

### 중위표기 수식을 후위 표기 수식으로 변환하는 알고리즘
```
infix_to_postfix(exp):

스택 s를 생성하고 초기화
while(exp에 처리할 문자가 남아있으면)
  ch <- 다음에 처리할 문자
  switch(ch)
    case 연산자:
      while (peek(s)의 우선순위 >= ch의 우선순위)
        do(e_) <- pop(s)
          e를 출력
      push(s, ch)
      break;
    case 왼쪽 괄호:
      push(s, ch)
      break;
    case 오른쪽 괄호:
      e <- pop(s);
      while(e!=왼쪽 괄호)
        do e를 출력
          e <- pop(s)
      break;
    case 피연산자:
      ch를 출력
      break;
  while(not is_empty(s))
    do e <- pop(s)
      e를 출력
```
### 프로그램
[중위표기to후위표기.c](https://github.com/qlkdkd/DataStruct/blob/main/week6/%EC%A4%91%EC%9C%84%ED%91%9C%EA%B8%B0to%ED%9B%84%EC%9C%84%ED%91%9C%EA%B8%B0/%EC%A4%91%EC%9C%84%ED%91%9C%EA%B8%B0to%ED%9B%84%EC%9C%84%ED%91%9C%EA%B8%B0/FileName.c)
```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//====스택 코드 시작====
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;


//스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}


//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}


//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}


//삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack Full Error\n");
		return;
	}
	else s->data[++(s->top)] = item;
}


//삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty Error\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}


//피크 함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty Error\n");
		exit(1);
	}
	else return s->data[s->top];
}

//====스택 코드의 끝====


//연산자의 우선순위를 반환한다.
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}


//중위표기 수식 -> 후위표기 수식
void infix_to_postfix(char exp[]) {
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init_stack(&s);//스택 초기화
	for (i = 0; i < len; i++) {
		ch = exp[i];

		switch (ch) {
		case '+': case '-': case '*': case '/': //연산자
			//스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;

		case '(': //왼쪽 괄호
			push(&s, ch);
			break;

		case ')': //오른쪽 괄호
			top_op = pop(&s);
			//오른쪽 괄호를 만날 때까지 출력
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;

		default: //피연산자
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s)) //스택에 저장된 연산자들 출력
		printf("%c", pop(&s));
}

int main() {
	char* s = "(2+3)*4+9";
	printf("중위표시수식: %s\n", s);
	printf("후위표시수식: ");
	infix_to_postfix(s);
	printf("\n");

	return 0;
}
```

---

### 스택의 응용: 미로 탐색 문제
* 체계적인 방법 필요
* 현재의 위치에서 가능한 방향을 스택에 저장해놓았다가 막다른 길을 만나면 스택에서 마음 탐색 위치를 꺼낸다.

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/e4fa7660-d1e0-4f97-8a4c-e9218cbb0310)

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/d8d97f82-c165-4583-b77e-9eb18fec3f09)

### 미로 탐색 알고리즘
```
스택 s와 출구의 위치 x, 현재 생쥐의 위치를 초기화
while(현재의 위치가 출구가 아니면) do
  현재 위치를 방문한 것으로 표기
  if(현재 위치의 위, 아래, 왼쪽, 오른쪽 위치가 아직 방문되지 않았고 갈 수 있으면)
    then 그 위치들을 스택에 push
  if(is__empty(s))
    then 실패
  else 스택에서 하나의 위치를 꺼내어 현재 위치로 만든다.;
성공;
```

### 미로 탐색 프로그램
[미로찾기.c](https://github.com/qlkdkd/DataStruct/blob/main/week6/%EB%AF%B8%EB%A1%9C%EC%B0%BE%EA%B8%B0/%EB%AF%B8%EB%A1%9C%EC%B0%BE%EA%B8%B0/FileName.c)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {		// 교체!
	short r;
	short c;
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 


element here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
{ 'e', '0', '1', '0', '0', '1' },
{ '1', '0', '0', '0', '1', '1' },
{ '1', '0', '1', '0', '1', '1' },
{ '1', '0', '1', '0', '0', 'x' },
{ '1', '1', '1', '1', '1', '1' },
};
// 위치를 스택에 삽입
void push_loc(StackType* s, int r, int c)
{
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}
// 미로를 화면에 출력한다. 
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main(void)
{
	int r, c;
	StackType s;

	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(&s)) {
			printf("실패\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("성공\n");
	return 0;
}
```
