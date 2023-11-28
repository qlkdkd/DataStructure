# 연결 리스트2
# 원형 연결 리스트
* 원형 연결 리스트: 마지막 노드가 첫 번째 노드를 가리키는 리스트
    * 마지막 노드의 링크 필드가 널(NULL)이 아니라 첫 번째 노드 주소가 되는 리스트이다.
* 원형 연결 리스트에서는 하나의 노드에서 다른 모든 노드로의 접근이 가능하다.
    * 삭제나 삽입 시에는 항상 선행 노드를 가리키는 포인터가 필요하다.
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/2331c5fa-0f88-4b6d-91ae-c3464628055e)

* 일반 리스트의 경우 보통 헤드포인터가 마지막 노드를 가리키게끔 구성하면 리스트의 처음이나 마지막에 노드를 삽입하는 연산이 단순 연결 리스트에 비하여 용이
* ![image](https://github.com/qlkdkd/DataStructure/assets/71871927/2038dee6-7af2-40e6-a8d0-8e7e1b2c7984)

## 원형 연결 리스트 정의
```c
listNode *head;
```

## 원형 리스트의 처음 삽입
* 먼저 새로운 노드의 링크인  node->link가 첫 번째 노드를 가리키게 함
* 그 다음 마지막 노드의 링크가 node를 가리키게 하면 됨.
* 헤드 포인터인 head가 마지막 노드를 가리킴
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/73ab4cb3-485c-4fe5-88b1-2a8a44b9b35c)

```c
ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL) {//노드의 링크인 node->link를 첫 번째 노드를 가리키게 하기
		head = node;
		node->link = head;
	}
	else {//마지막 노드의 링크가 node를 가리키게 하기
		node->link = head->link;
		head->link = node;
	}
	return head;
}
```
