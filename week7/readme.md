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
* 공백 상태: `front==rear``
* 포화상태: `front%M==(rear+1)%M`
* 공백상태화 포화상태를 구별하기 위하여 하나의 공간은 항상 비워둔다.
    * 한 자리를 비워주지 않는다면 (c) 오류상태 처럼 되어 공백 상태와 포화 상태를 구별할 수가 없다.
