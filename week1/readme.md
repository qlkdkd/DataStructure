# 1. 자료구조와 알고리즘

## 일상생활에서의 사물의 조직화
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/39c0eb66-ad6e-44a3-8e8e-6ab3233f4bea)
## 일상생활과 자료구조의 비교
(표 1-1) 일상생활과 자료구조의 유사성
**일상생활에서의 예**|**해당하는 자료구조**
---|---
그릇을 쌓아서 보관하는 것|스택
마트 계산대의 줄|큐
버킷 리스트|리스트
영어사전|사전
지도|그래프
컴퓨터의 디렉토리 구조|트리

* 사람들이 사물을 정리하여 저장하는 것과 마찬가지로 프로그램에서도 자료들을 정리하여 보관하는 여러가지 구조들이 있다. 이를 **자료구조**라 부른다.
## 자료구조와 알고리즘
### 프로그램: 자료구조 + 알고리즘
* 대부분 프로그램에서 자료(data)를 처리하고 있고, 이들은 자료구조(data structure)를 사용하여 저장된다.
* 알고리즘: 주어진 문제를 처리하는 절차
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/951a1f76-1798-4bd8-8402-94553a1e31f1)
```c
#define MAX_ELEMENTS 100
int score[MAX_ELEMENTS];//자료구조
int get_max_score(int n){//학생의 숫자는 n
  int i, largest;
  largest=scores[0];
  for(i=1; i<n; i++){
    if(scores[i]>largest){
      largest=scores[i];
    }
  }
  return largest;
}
```

## 알고리즘의 조건
* 입력: 0개 이상의 입력이 존재하여야 한다.
* 출력: 1개 이상의 출력이 존재하여야 한다.
    * 입력은 없어도 출력이 없으면 알고리즘이라고 할 수 없다.
* 명백성: 각 명령어의 의미는 모호하지 않고 명확해야 한다.
    * 모호한 방법으로 기술된 명령어들의 집합은 알고리즘이라 할 수 없다. 또한 실행할 수 없는 명령어(예: 1/0) 또한 알고리즘이 아님.
* 유한성: 한정된 수의 단계 후에는 반드시 종료되어야 한다.
* 유효성: 각 명령어들은 실행 가능한 연산이여야 한다.
## 알고리즘
* **알고리즘(algorithm)**: 컴퓨터로 문제를 풀기 위한 단계적인 절차
#### 알고리즘 해결 방법
1. 문제를 해결할 수 있는 방법을 고안
2. 이들 방법에 따라 컴퓨터가 수행하여할 단계적인 절차를 자세히 기술

## 알고리즘의 기술 방법
* 영어나 한국어와 같은 자연어
* 흐름도(flow chart)
* 의사코드(pseudo-code)
* 프로그래밍 언어

## 자연어로 표기된 알고리즘
* 인간이 읽기 쉬움
* 그러나 자연어의 단어들을 정확하게 정의하지 않으면 의미 전달이 모호해질 우려가 있다.
* (예) 배열에서 최대값 찾기 알고리즘
```
ArrayMax(list, n)
1. 배열 list의 첫 번째 요소를 변수 tmp에 복사
2. 배열 list의 다음 요소들을 차례대로 변수 tmp에 복사
3. 배열 list의 모든 요소를 비교했으면 tmp를 변환
```
## 흐름도로 표기된 알고리즘
* 직관적이고 이해하기 쉬운 알고리즘 기술 방법
* 그러나 복잡한 알고리즘의 경우, 상당히 복잡해짐
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/4fa353ff-c2b7-4830-adcb-d03385cbef93)

## 유사코드로 표현된 알고리즘
* 알고리즘 기술에 가장 많이 사용
* 프로그램을 구현할 때의 여러 가지 문제들을 감출 수 있다. 즉 알고리즘의 핵심적인 내용에만 집중할 수 있다.
```
ArrayMax(list, n):
  largest<-list[0]
  fori<-1 to n-1 do
    if list[i]>largest
      then largest<-list[i]
  return largest
```

## c로 표현된 알고리즘
* 알고리즘의 가장 정확한 기술이 가능
* 반면 실제 구현 시, 많은 구체적인 사항들이 알고리즘의 핵심적인 내용에 대한 이해를 방해할 수 있음
```c
# define MAX_ELEMENTS 100
int score[MAX_ELEMENTS];
int find_max_score(int n){
    int i, tmp;
    tmp=score[0];
    for(i=1; i<n; i++){
        if(score[i]>tmp)
            tmp=score[i];
    }
    return tmp;
}
```

---

## 자료형
* 자료형(data type): 데이터의 종류
* 정수, 실수, 문자열 등이 기초적인 자료형의 예
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/a2ce8d49-f9b2-4427-a503-984bb3cf890d)
### 자료형(data type)
* 데이터의 집합과 연산의 집합
* 자료형을 작성할 때에는 실행 가능한 연산에 대해서도 신경 써야함. 데이터의 종류가 달라지면 그 데이터와 관련된 연산도 달라진다.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/06377378-aa50-4c6a-bcd1-46e627c0f0b5)

## 추상 데이터 타입
### 추상 데이터 타입(ADT: Abstract Data Type)
* ADT: 데이터 타입을 추상적(수학적)으로 정의한 것
* 데이터나 연산이 **무엇(what)** 인가는 정의되지만 데이터나 연산을 **어떻게(how)** 컴퓨터 상에서 구현할 것인지는 정의되지 않는다.

## 추상 데이터타입의 유래
* 추상화(abstraction): 어떤 시스템의 전략화된 기술 또는 명세로서 시스템의 정말 핵심적인 구조나 동작에만 집중하는 것이다.
* 좋은 추상화는 사용자에게 중요한 정보는 강조되고 반면 중요하지 않은 구현 세부 사항은 제거되는 것
* 추상화->정보 은닉법(information hiding)->추상 자료형(ADT)
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/33b41602-cdfb-449a-b23f-6783d0bfac64)

## 추상 데이터 타입의 정의
* **객체**: 추상 데이터 타입에 속하는 객체가 정의된다.
* **연산**(함수): 이들 객체 사이의 연산이 정의된다. 이 연산은 추상 데이터 타입과 외부를 연결하는 인터페이스의 역할을 한다.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/46224728-ff56-4eee-b223-20f2559d4f43)

## 추상 데이터 타입의 예: 자연수
```
Nat_No
* 객체: 0에서 시작하여 INT_MAX까지의 순서화된 정수의 부분범위
* 함수:
Nat_Number zero()::=0
Nat_Number successor(x)::=
  if(x==INT_MAX) return x
  else return x+1

Boolean is_zero(x)::=
  if (x) return Flase
  else return True

Boolean equal(x, y)::=
  if(x==y) return Ture
  else return False

Nat_Number add(x, y)::=
  if((x+y)<=INT_MAX) return x+y
  else return INT_MAX

Nat_Number sub(x, y)::=
  if(x<y) return 0
  else return x-y
```

## 추상 데이터 타입과 TV
ADT 는 TV와 같은 가전제품과 비슷하다. TV는 사용자 인터페이스를 가지고 있다. 예를 들면 채널 버튼을 누르면 채널을 변경할 수 있다. ADT도 연산이라고 하는 인터페이스를 통하여 ADT를 사용할 수 있다. ADT와 TV가 비슷한 점을 나열해보자
### TV
* TV의 인터페이스가 제공하는 특정한 작업만을 할 수 있다.
* 사용자는 TV의 내부를 볼 수 없다.
* TV의내부에서 무엇이 일어나고 있는지를 몰라도 이용할 수가 있다.
### ADT
* 사용자들은 ADT가 제공하는 연산만을 사용할 수 있다.
* 사용자들은 ADT 내부의 데이터를 접근할 수 없다.
* 사용자들은 ADT가 어떻게 구현되는지 모르더라도 ADT를 사용할 수 있다.

---

## 알고리즘의 성능 분석

### 알고리즘의 성능 분석 기번
#### 수행 시간 측정
* 두 개의 알고리즘의 실제 수행 시간을 측정하는 것
* 실제로 구현하는 것이 필요
* 동일한 하드웨어를 사용해야 함

#### 알고리즘의 복잡도 분석
* 직접 구현하지 않고서도 수행 시간을 분석하는 것
* 알고리즘이 수행하는 연산의 횟수를 측정하여 비교
* 일반적으로 연산의 횟수는 n의 함수

## 프로그램 효율성의 중요성
1. 최근 상용 프로그램의 규모가 이전에 비해서 엄청나게 커지고 있기 때문. 즉 처리해야할 자료의 양이 많기 때문에 알고리즘의 효율성이 더욱 중요하게 된다.
2. 사용자들은 여전히 빠른 프로그램을 선호함. 따라서 경쟁사의 프로그램보다 수행속도가 느리다면 경쟁에서 밀릴 수 밖에 없음
* 따라서 프로그래머는 소프트웨어적으로 최선의 효율성을 갖는 프로그램을 제작하도록 노력해야함.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/ca6aba71-d0bf-45ca-82e2-bd05caac0bfc)
->프로그램 A가 B보다 좋은 알고리즘으로 짜여져 있음

## 수행시간 측정
* 알고리즘을 프로그래밍 언어로 작성하여 실제 컴퓨터상에서 실행시킨 다음, 그 수행시간을 측정
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/4a20efa8-f34c-4c3a-b75b-995d42aec1e9)

방법#1
```
#include<time.h>
start=clock();
...
stop=clock();
double duration=(double)(stop-start).CLOCK_PER_SEC;
```
방벙#2
```
#include<time.h>
start=time(NULL);
...
stop=time(NULL);
double duration=(double)difftime(stop, start);
```
[첫번째 방법 코드 보기](https://github.com/qlkdkd/DataStruct/blob/main/week1/call_time/call_time/FileName.c)

## 복잡도 분석
* 시간 복잡도는 알고리즘을 이루고 있는 연산들이 몇 번이나 수행되는지를 숫자로 표시
```
largest<=scores[0]
for i<-1 to N<-1 do
  if scores[i]>largest
    then largest<-scores[i]
return largest
```

## 복잡도 분석의 종류
* 시간 복잡도: 알고리즘의 절대적인 수행 시간을 나타내는 것이 아니라 알고리즘을 이루고 있는 연산들이 몇 번이나 수행되는지를 숫자로 표기
* 공간 복잡도
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/cb4663a9-d4cb-4d86-b246-ba0a34842835)

## 입력의 개수 고려
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/94ea2e91-45f1-4460-a931-9552154018e6)
## 복잡도 분석의 예
* 양의 정수 n을 n번 더하는 문제를 생각하여 보자
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f4342f47-44f8-4b73-8e01-3ee267c5bf33)

## 알고리즘의 비교
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/40bef0a9-3a0a-48af-9410-1cc87a305bed)
## 연산의 횟수를 그래프로 표현
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/0bd77f83-ede3-41c3-a3db-bdadb55ddfb5)
* 결론: 알고리즘 A가 가장 효율적
## 빅 오 표기법
* 일반적으로 입력의 개수와 시간 복잡도 함수의 관계는 상당히 복잡해질 수 있음
* 자료의 개수가 많은 경우에는 차수가 가장 큰 항이 가장 영향을 크게 미치고 다른 항들은 상대적으로 무시될 수 있음.
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/62e8e461-bacb-4ba6-ad0c-47823d7f297a)

* **빅 오 표기법**: 연산의 횟수를 대략적(점근적)으로 표기한 것
* 정의: 두 개의 함수 $f(n)$과 $g(n)$이 주어졌을 때, 모든 $n>=n_0$에 대하여 $|f(n)|<=c|g(n)|$을 만족하는 두개의 상수 $c$와 $n_0$가 존재하면 $f(n)=O(g(n))$이다.
* 빅 오는 **함수의 상한** 을 표시한다.
    * 예: $n>=5$이면 $2n+1<10n$이므로 $2n+1=O(n)$
 ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f5753f89-bb72-4a63-b9b0-9fbebda99f2f)
* $f(n)$의 값은 $n$이 매우 커지게 되면 결국은 $g(n)$보다 작거나 같게 된다. 따라서 이 정의는 $g(n)$이 $f(n)$의 상한값이라는 것을 의미한다.
* 빅 오 표기법을 사용하면 시간복잡도 함수의 증가에 별로 기여하지 못하는 항을 생략함으로써 시간복잡도를 간단하게 표시할 수 있다.
* 빅 오 표기법을 얻는 간단한 방법은 기본 연산의 횟수가 다항식으로 표현되었을 경우 다항식이 최고차항만을 남기고 다른 항들과 상수항을 버리는 것이다. 최고차항의 계수도 버리고 단지 최고차항의 차수만을 사용한다.
## 빅 오 표기법의 예
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/c45c5197-8ba8-4c92-9a50-f777f59840c5)

## 빅 오 표기법의 종류
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f73aebcf-7507-447f-8a21-f4384cfaa776)
## 빅 오 표기법
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/e767a53b-3c8a-4cd0-917d-6a5a65d709a4)
## 빅 오 표기법 이외읭 표기법
### 빅 오메가 표기법
* 모든 $n>=n_0$에 대하여 $|f(n)|>=c(g(n))|$을 만족하는 2개의 상수 c와 $n_0$이 존재하면 $f(n)=\Omega(g(n))$이다.
* 빅 오메가는 함수의 하한을 표시한다.
* (예) $n>=5$이면 $2n+1<10n$이므로 $n=\Omega(n)$
### 빅 세타 표기법
* 모든 $n>=n_0$에 대하여 $c_1|g(n)|<=|f(n)|<=c_2|g(n)|$을 만족하는 3개의 상수 $c_1, c_2$와 $n_0$가 존재하면 $f(n)=\theta(g(n))$이다.
* 빅 세타는 함수의 하한인 동시에 상한을 표시한다.
* $(f(n)=O(g(n))) \wedge (f(n)=\Omega(g(n)))=(f(n)=\theta(n))$
* (예) $n>=1$이면 $n<=2n+1<=3n$이므로 $2n+1=\theta(n)$
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/38ae5a28-9282-445d-8e99-01b45b1a600b)

## 최선, 평균, 최악의 경우
* 알고리즘의 수행 시간은 입력 자료 집합에 따라 다를 수 있다.
* **최선의 경우**: 수행시간이 가장 빠른 경우, 의미가 없는 경우가 많다.
*  **평균의 경우**: 수행시간이 평균적인 경우, 계산하기가 상당히 어렵다.
*  **최악의 경우**: 수행시간이 가장 늦은 경우, 가장 널리 사용된다. 계산하기 쉽고 응용에 따라서 중요한 의미를 가질수도 있다.
