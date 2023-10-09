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

[코드 보기]()
