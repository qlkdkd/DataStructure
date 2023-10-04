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
