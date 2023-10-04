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