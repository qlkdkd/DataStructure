# Week5_Stack

## 스택이란?
* 스택(stack)이란 쌓아놓은 더미를 의미한다.

* 특징_**후입선출(LIFO: Last-in-First-Out)**: 가장 최근에 들어온 데이터가 가장 먼저 나감.

* 스택의 구조
![5_1](https://github.com/qlkdkd/DataStruct/assets/71871927/ed86df2a-d794-4ab3-9776-2b228f47bf70)

### 예제: 시스템 스택을 이용한 함수 호출

```c
void func2(){
  return;
}

void func1(){
  func2()
}

int main(){
  func1()
  return 0;
}
```

![5_2](https://github.com/qlkdkd/DataStruct/assets/71871927/b7a78a71-77d9-4a04-821d-e72451cae4f1)

---

### 스택 추상 데이터 타입(ADT)
* 객체: 0개 이상의 원소를 가지는 유한 선형 리스트
* 연산:
  * `create(size)`::= 최대 크기가 size인 공백 스택을 생성한다.
    
  * `is_full(s)`::=
    ```c
    if(스택의 원소 수==size) return TRUE;
    else return FALSE;
    ```
  * `is_empty(s)`::=
    ```c
    if(스택의 원소 수==0) return TRUE;
    else return FALSE;
    ```
  * `push(s, item)`::=
    ```c
    if(is_full(s))return ERROR_STACKFULL;
    else 스택의 맨 위의 원소를 제거해서 반환한다.
    ```

  * `pop(s)`::=
    ```c
    if(is_empty(s)) return ERROR_STACKEMPTY;
    else 스택의 맨 위의 원소를 제거해서 반환한다.
    ```

  * `peek(s)`::=
    ```c
    if(is_empty(s)) return ERROR_STACKEMPTY;
    else 스택의 맨 위의 원소를 제거하지 않고 반환한다.
    ```

### 스택의 연산
* `push()`: 스택에 데이터를 추가
* `pop()`: 스택에 데이터를 삭제
  ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/40964819-dad9-46f2-a905-fd75aa38d4e4)

* is_empty(s): 스택이 공백상태인지 검사
* is_full(s): 스택이 포화상태인지 검사
* create(): 스택을 생성
* peek(s): 요소를 스택에서 삭제하지 않고 보기만 하는 연산
  <<<* 참고: pop연산은 요소를 스택에서 완전히 삭제하면서 가져온다.

  ---

### 배열을 이용한 스택의 구현

  * 1차원 배열 `stack[]`
  * 스택에서 가장 최근에 입력되었던 자료를 가리기는 `top` 변수
  * 가장 먼저 들어온 요소는 `stack[0]`에, 가장 최근에 들어온 요소는 `stack[top]`에 저장
  * 스택이 공백 상태이면 `top`=$-1$
  ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/0bdd6e64-ba78-4015-b256-214468e04f46)

### is_empty, is_full, push, pop 연산의 구현

```
//is_empty의 계산
is_empty(s):

if top==-1
  then return TURE
else return FALSE
```

```
//is_full의 계산
is_full(s):

if top==(MAX_STACK_SIZE-1)
  then return TRUE
else return FALSE
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/2e280427-68bd-4f92-b1ba-43d62fab8262)

```
//push의 연산
push(s, x):

if is_full(s):
  then error "overflow"
else:
  top+=1
  stack[top]=x
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/4f8686c2-8015-4184-9867-337809117918)

```
//pop의 연산
pop(s, x):

if is_empty(s):
  then error "underflow"
else:
  e=stack[top]
  top-=1
  return e
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/7717b913-80a8-4b06-9e71-60983ba7ad52)

---

### 전역 변수로 구하는 방법

[stack.c](https://github.com/qlkdkd/DataStruct/blob/main/week5/week5_stack/week5_stack/stack.c)

### 구조체 배열 사용하기
[stack_struck.c](https://github.com/qlkdkd/DataStruct/blob/main/week5/stack_struckArray/Project1/stack_struck.c)

### 일반적인 배열 스택 프로그램
[stack_array.c](https://github.com/qlkdkd/DataStruct/blob/main/week5/stack_array/stack_array/stack_array.c)

### 동적 스택
[stack_Malloc.c](https://github.com/qlkdkd/DataStruct/blob/main/week5/Stack_malloc/Stack_malloc/stackMalloc.c)

### 동적 배열 스택
* malloc()을 호출하여 실행 시간에 메모리를 할당 받아서 스택을 생성한다.
```c
typedef int element;
typedef struct{
  element *data; //data는 포인터로 정의된다.
  int capacity; //현재 크기
  int top;
}StackType;
```

* 스택이 만들어질 때 1개의 요소를 저장할 수 있는 공간을 일단 확보한다.
```c
//스택 생성 함수
void init_stack(StackType *s){
  s->top=-1;
  s->capacity=1;
  s->data=(element *)malloc(s->capacity*sizeof(element));
}

//스택 삭제 함수
void delete(StackType *s){
  free(s);
}
```

* 가장 큰 변화가 있는 함수는 `push()`이다. 공간이 부족하면 메모리를 2배로 더 확보한다.
```c
void push(StackType *s, element item){
  if(is_full(s)){
    s->capacity*=2;
    s->data=(element *)realloc(s->data, s->capacity * sizeof(element))
  }
  s->data[++(s->top)]=item;
}
``` 
