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
  <img align="right", src="https://github.com/qlkdkd/DataStruct/assets/71871927/4d2c4911-61d8-4c8c-8108-28b781f92153">

