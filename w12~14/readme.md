# 트리

# 트리의 개념
* 선형 자료 구조(linear data structure): 자료들이 선형으로 나열되어있는 구조(리스트, 스택, 큐 등)
* 트리: 계층적 자료 구조. 부모-자식 관계의 노드들로 이루어짐
* 트리의 응용분야
    * 계층적 조직 표현
    * 컴퓨터 디스크의 디렉토리 구조
    * 인공지능에서의 결정 트
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/5e801464-8867-4fa7-8cbc-83e5f4b7d072)
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/b2c99792-bb2d-45a1-ac27-5ddc102e5519)
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/22660573-167b-4af3-958f-a383d03f6d26)

## 트리의 용어
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/5e02e524-ba0f-4b55-8d2b-f77ca4c563a6)
* 노드: 트리의 구성 요소(A, B, C, D, E, F, G, H, I, J)
    * 트리는 한 개 이상의 노드로 이루어진 유한 집합
* 루트: 부모가 없는 노드(A), 계층적 구조에서 가장 높은 곳에 위치함
* 서브트리: 루트를 제외한 나머지 노드
    * A는 루트 노드이고, 나머지 {B, E, F, G}, {C, H}, {D, I, J}는 총 3개의 집합으로 나누어지는데 이들을 A의 서브트리라 한다.
    * 다시 서브트리인 {B, E, F, G}의 루트는 B가 되고 나머지 노드들은 다시 3개의 서브트리, 즉 E, F, G로 나누어진다.
    * {C, H}와 {D, I, J}도 같은 식으로 다시 루트와 서브트리로 나누어질 수 있다.
* 간선(edge): 루트와 서브트리를 잇는 선
    * 노드들 간에 부모관계, 형제관계, 조손관계가 존재: 인간의 관계와 동일
        * A는 B의 부모 노드, B는 A의 자식 노드
        * B와 C와 D는 형제 관계
    * 조상노드: 루트 노드에서 임의의 노드까지 경로를 이루고 있는 노드들
    * 후손 노드: 임의의 노드 하위에 연결된 모든 노드들을 의미
        * 즉 어떤 노드의 서브트리에 속하는 모든 노드들은 후손노드
* 단말 노드: 자식 노드가 없는 노드
* 비단말 노드: 단말 노드의 반댓말

![image](https://github.com/qlkdkd/DataStructure/assets/71871927/4d32a3f3-50b3-4579-bfd8-fba2d8fae3ec)
* 차수: 노드가 가지고 있는 자식 노드의 개수: 위 그림에서는 루트 노드의 경우 자식 노드가 3개이기 때문에 차수가 3이다.
    * 트리의 차수는 트리가 가지고 있는 노드의 차수 중에서 가장 큰 값: 위 그림에서는 A와 B의 차수가 3으로 가장 크므로 해당 트리의 차수는 3
* 레벨: 트리의 각층에 번호를 매기는 것. 루트의 레벨은 1이고 B의 레벨은 2이다.
* 높이: 트리가 가지고 있는 최대 레벨
    * 해당 트리의 높이는 3이다
* 포레스트(forest): 트리의 집합

### 트리 예제
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/1b67ccef-dfab-4832-b902-bc5301583fef)
* A는 루트 노드이다.
* B는 D와 E의 부모노드이다.
* C는 B의 형제 노드이다.
* D와 E는 B의 자식 노드이다.
* B으 차수는 2이다.
* 위의 트리의 높이는 4이다.

## 트리의 종류
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/3c6591f5-3010-4610-84c7-d372aa25c8f5)
* 일반 트리: 트리를 프로그램 안에서 표현하는 가장 일반적인 방법. 각 노드가 데이터를 저장하는 데이터 필드와 자식 노드를 가리키는 링크 필드를 가지게 하는 것
    * 일반 트리에서 n은 자식 노드의 개수, 즉 노드의 차수
    * 일반적인 트리에서 각 노드들은 서로 다른 개수의 자식 노드를 가지므로 노드에 따라서 링크 필드의 개수가 달라짐
* 이진 트리: 자식 노드의 개수가 2개인 트리
    * 일반 트리의 경우 노드의 크기가 고정되지 않으면 프로그램이 복잡해짐.

# 이진 트리
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/da6cc91e-0a04-45aa-96c6-3057909ba508)
* 이진 트리: 모든 노드가 2개의 서브 트리를 가지고 있는 트리
* 이진 트리의 노드에는 최대 2개까지의 자식 노드가 존재
* 모든 노드의 차수는 2 이하
* 이진 트리에는 서브 트리간의 순서가 존재: 왼쪽 서브트리와 오른쪽 서브트리는 서로 구별

> 이진 트릐의 정의
> 1. 공집합이거나
> 2. 루트와 왼쪽 서브트리, 오른쪽 서브트리로 구성된 노드들의 유한 집합으로 정의됨. 이진트리의 서브트리들은 모두 이진트리여야 한다.

## 이진 트리 검증
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/0f5756f8-a35e-4eb9-a5cc-c787ce5218ad)
* SUB3는 하나의 노드 D로만 이루어져 있음. 만약 노드 D를 SUB3의 루트라고 생각하면 SUB3의 서브 트리는 공집합
   * 정의 (1)에 의하여 공집합도 이진 트리
   * 정의 (2)에 의하여 SUB3는 루트와 공집합 서브 트리 2개를 가지는 어엿한 이진 트리
* 같은 식으로 SUB2도 루트와 공집합 서브트리 2개를 가지는 이진 트리.
* SUB1은 SUB1의 루트 노드 B와 서브트리 SUB3와 공집합 서브트리를 가지고 있으므로 역시 이진트리

* 최종적으로 전체 트리는 루트 노드 A와 SUB1, SUB2의 2개의 서브트리를 가지고 있는데 이 두개의 서브트리가 이진 트리이므로 전체 트리도 이진트리라고 결론내릴 수 있다.

> 이진 트리와 일반 트리의 차이점
> * 이진 트리의 모든 노드는 차수가 2 이하. 즉 자식 노드의 개수가 2 이하. 반면 일반 트리는 자식 노드의 개수에 제한 없음
> * 일반 트리와는 달리 이진 트리는 노드를 하나도 갖지 않을 수도 있다.
> * 서브 트리간에 순서가 존재한다는 점도 다른 점이다. 따라서 왼쪽 서브트리와 오른쪽 서브트리를 구별한다.

## 이진 트리의 성질
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/a1040080-e2a9-4adb-b320-6265a57a3865)

* 노드의 개수가 n개이면 간선의 개수는 $n-1$
   * 이진트리에서의 노드는 루트를 제외하면 정확하게 하나의 부모 노드를 가짐
   * 부모와 자식간에는 정확하게 하나의 간선만이 존재함
   * 따라서 간선의 개수는 n-1

 ![image](https://github.com/qlkdkd/DataStructure/assets/71871927/e755feb2-d26a-4897-bf88-abf71e3aee45)
* 높이가 $h$인 이진트리의 경우, 최소 $h$개의 노드를 가지며 최대 $2^h-1#개의 노드를 가짐
   * 한 레벨에는 적어도 하나의 노드는 존재해야 하므로 높이가 h인 이진트리는 적어도 $h$개의 노드를 가짐
   * 또 하나의 노드는 최대 2개의 자식을 가질 수 있으므로 레벨 $i$에서의 노드의 최대 개수는 $2^{i-1}$이 됨
   * 따라서 전체 노드의 개수는 $\sum_{i=1}^{h} 2^{i-1}=2^h-1$이 된다.

![image](https://github.com/qlkdkd/DataStructure/assets/71871927/5e74c638-70af-4ab2-b460-681d19286154)
* $n$개의 노드를 가지는 이진트리의 높이는 최대 $n$이거나 최소 $[log_2(n+1)]$이 된다.
   * 레벨 당 최소한 하나의 노드는 있어야 하므로 높이가 n을 넘을 수 없다.
   * 높이 $h$의 이진 트리가 가질 수 있는 노드의 최대값은 $2^h-1$이다.
   * 따라서 $n<=2^h-1$의 부등식이 성립하고 양변에 $log$를 취하여 정리하면 $h>=log_2(n+1)$이 된다.
   * $h$는 정수이여야 하므로 $h>=[log_2(n+1)]$이 된다.([..]는 가우스 기호)
 
## 이진트리의 분류
* 포화 이진트리
* 완전 이진트리
* 기타 이진트리
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/2dfde377-9961-4d81-a9b6-57559e8e7a00)

### 포화 이진트리
* 트리의 각 레벨에 노드가 꽉 차있는 이진 트리
* 높이 $k$인 포화 이진트리는 정확하게 $2^k-1$개의 노드를 가짐
* 일반적으로 포화 이진트리에서의 노드의 개수의 계산
$$전체 노드 개수: 2^{1-1}+2^{2-1}+2^{3-1}+...+2^{k-1}=\sum_{i=0}^{k-1}2^i=2^k-1$$
* 포화 이진트리에는 각 노드에 번호를 붙일 수 있다.
   * 노드에 번호를 부여하는 방법은 레벨 단위로 왼쪽에서 오른쪽으로 번호를 붙이면 된다.

### 완전 이진트리
* 완전 이진트리: 높이가 $k$일 때 레벨 1부터 $k-1$까지는 노드가 모두 채워져 있고 마지막 레벨 $k$에서는 왼쪽부터 오른쪽으로 노드가 순서대로 채워져 이있는 이진트리
* 마지막 레벨에서는 노드가 꽉 차있지 않아도 되지만 중간에 빈 곳이 있어서는 안된다.
* 따라서 포화 이진 트리는 항상 완전 이진트리 이지만 그 역은 성립할 수 없음
* 포화 이진트리의 노드 번호와 완전 이진트리의 노드번호는 1대1로 대응한다.
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/893f6440-059b-4732-9f34-ab72ec1cbf6c)

# 이진 트리의 표현
* 배열을 이용하는 방법
* 포인터를 이용하는 방법

## 배열 표현법
* 배열 표현법: 모든 이진트리를 포화 이진트리라고 가정하고 이진트리의 높이가 $k$이면 최대 $2^k-1$개의 공간을 연속적으로 할당한 다음, 완전 이진 트리의 번호대로 노드들을 저장
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/8f1e8f41-f8ac-49e0-bd47-2ebe1554afd8)
* (a). 완전 이진 트리의 경우
   * 노드 A는 노드 번호가 1이므로 배열의 인덱스 1에 저장
   * 노드 B는 노드 번호가 2이므로 배열의 인덱스 2에 저장
   * 인덱스 0은 사용하지 않음(0을 사용하지 않는게 간단함)
* (b). 경사 이진트리의 경우
   * 배열 표현을 사용할 수 있으나 기억 공간의 낭비가 심함

## 부모와 자식의 인덱스 관계
> * 노드 i의 부모 노드 인덱스=$\frac{i}{2}$
> * 노드 i의 왼쪽 자식 노드인덱스=$2i$
> * 노드 i의 오른쪽 자식 노드 인덱스=$2i+1$

* (a)에서 노드 B의 인덱스는 2이고 부모 노드인 A의 인덱스는 1이다
$$2=\frac{2}{2}=1$$
* 노드 B의 왼쪽 자식 노드인 노드 D의 인덱스는 4이고 오른쪽 자식 노드인 노드 E의 인덱스는 5이다.
$$4=2*2$$
$$5=2*2+1$$

## 링크 표현법
* 링크 표현법: 포인터를 이용하여 부모노드가 자식노드를 가리키게 하는 방법
   * 트리에서의 노드가 구조체로 표현
   * 각 노드가 포인터를 가지고 있어서 이 포인터를 이용하여 노드와 노드를 연결
   * 하나의 노드가 3개의 필드를 가짐
      * 포인터필드: 왼쪽 자식과 오른쪽 자식을 가리킴
      * 중간: 데이터 필드
   * 2개의 포인터 필드를 이용하여 부모노드와 자식노드를 연결
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/b14f1f8b-3fd3-49ae-b9ba-ea6745ae3a33)

## 링크의 구현
* 노드는 구조체로 표현
* 링크는 포인터로 표현
```c
typedef struct TreeNode{
   int data;
   struct TreeNode *left, *right;
}
```
* 링크법으로 표현된 트리는 루트 노드를 가리키는 포인터만 있으면 트리 안의 모든 노드들에 접근할 수 있음
* 연결리스트와 유사: 연결 리스트도 포인터에 의하여 연결된 구조
   * 연결 리스트: 1차원적인 연결된 구조
   * 링크법으로 표현된 이진 트리: 2차원적으로 연결된 구현

## 링크 표현법 프로그램
```c
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int main() {
	TreeNode* n1, * n2, * n3;

	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));

	//첫번째 노드 설정
	n1->data = 10;
	n1->left = n2;
	n1->right = n3;

	//2번째 노드 설정
	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;

	//3번째 노드 설정
	n3->data = 30;
	n3->left = NULL;
	n3->right = NULL;

	free(n1); free(n2); free(n3);
	return 0;
}
```

---

# 이진 트리의 순회
* 순회: 이진트리에 속하는 모든 노드를 한 번씩 방문하여 노드가 가지고 있는 데이터를 목적에 맞춰 처리하는 것을 의미
   * 사용목적: 트리의 노드에 자료를 저장하고 필요에 따라서 이 자료를 처리하기 위함
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/b92e12cf-1139-4d34-8159-fafbc7f87adf)

## 이진 트리 순회방법
* 전위, 중위, 후위 3가지 방법
* 루트, 왼쪽 서브트리, 오른쪽 서브트리 중에서 루트를 언제 방문하느냐에 따라 구문됨
* 루트를 서브트리에 앞서서 먼저 방문-> 전위순회
* 루트를 왼쪽과 오른쪽 서브트리 중간에 방문-> 중위순회
* 루트를 서브트리 방문 후에 방문-> 후위순회
* (항상 왼쪽 서브트리를 오른쪽 서브트리에 앞서서 방문함)

> 루트: V, 왼쪽 서브트리: L, 오른쪽 서브트리: R라고 할 때
> 전위순회: VRL
> 중위순회: LVR
> 후위순회: LRV
## 전위순회
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/b4511a10-eff2-42a8-a996-1ffcf80e9fa7)

* 전위순회: 루트를 먼저 방문하고 그 다음에 왼쪽 서브트리를 방문하고 오른쪽 서브트리를 마지막으로 방문하는 것이다.
1. 루드노트 방문
2. 왼쪽 서브트리 방문
3. 오른쪽 서브트리 방문

### 트리 전회순위 알고리즘
```
preorder(x):
	if x!=null:
		print Data(x);
		preorder(Left(x));
		preorder(Right(x));
```

> 알고리즘 설명
> 1. 노드 x가 NULL이면 더이상 순환호출을 하지 않음
> 2. x의 데이터 출력
> 3. x의 왼쪽 서브트리 순환호출하여 방문
> 4. x의 오른쪽 서브트리 순환호출하여 방문

* 방문 순서: 왼쪽 서브트리의 루트 방문-> 왼쪽 서브트리의 왼쪽 서브트리 방문-> 왼쪽 서브트리의 오른쪽 방문

## 중위순회
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/cf0d7677-bd53-47ee-a4a7-b45fb30399ab)
* 왼쪽 서브트리-> 루트노드-> 오른쪽 서브트리 순으로 방문

### 트리 중위순회 알고리즘
```
	inorder(x)
	if x!=NULL:
		inorder(Left(x));
		print Data(x);
		inorder(Right(x));
```
> 알고리즘 설명
> 1. 노드 x가 NULL이면 더이상 순환호출 하지 않음
> 2. x의 왼쪽 서브트리 순환호출하여 방문
> 3. x의 데이터 출력
> 4. x의 오른쪽 서브트리 순환호출하여 방문

## 후위순회
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/8e79c096-5256-494c-9194-b948c937cbd3)
* 왼쪽 서브트리-> 오른쪽서브트리-> 루트노드 순으로 방문

### 트리 후위순회 알고리즘
```
postorder(x):
	if x!=NULL:
		postorder(Left(x));
		postorder(Right(x));
		print Data(x);
```
> 알고리즘 설명
> 1. 노드 x가 NULL이면 순환호출 x
> 2. x의 왼쪽 서브트리 순환호출하여 방문
> 3. x의 오른쪽 서브트리 순환호출하여 방문
> 4. x의 데이터 출력

## 전체 프로그램
```c
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

//중위순회
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

//전위순회
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//후위순회
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int main() {
	printf("중위순회= ");
	inorder(root);
	printf("\n");

	printf("전위순회= ");
	preorder(root);
	printf("\n");

	printf("후위순회= ");
	postorder(root);
	printf("\n");

	return 0;
}
```

## 반복적 순회
* 앞에서는 순환호출을 이용해 순환을 하였고 이게 일반적이지만, 반복을 이용해 트리순회를 할 수 있
