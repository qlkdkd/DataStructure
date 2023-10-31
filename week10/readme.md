# w10. 9주차 이어서

## 단순 연결 리스트의 연산

우리는 앞 절에서 노드를 하나씩 만들어서 서로 연결하였다. 작은 리스트이면 이렇게 만들어도 되지만 리스트가 커지면 추상 데이터 타입에 정의된 전용 함수들을 통하여 노드를 추가하는 것이 편하다.

* insert_first(): 리스트의 시작 부분에 항목을 삽입하는 함수
* insert(): 리스트의 중간 부분에 항목을 삽입하는 함수
* delete_first(): 리스트의 중간 항목을 삭제하는 함수
* delete(): 리스트의 중간 항목을 삭제하는 함수(도전 문제)
* print_list(): 리스트를 방문하여 모든 항목을 출력하는 함수

## 단순 연결 리스트_삽입연산(insert_first())
 단순 연결 리스트의 경우, 리스트의 처음이나 끝에 새로운 노드를 추가하는 경우가 많다. 여기서는 리스트의 첫 부분에 새로운 노드를 추가하는 함수 insert_first()를 작성해 보자.
 여기서 매개변수head는 헤드 포인터이고 value는 새롭게 추가되는 데이터이다.

 head가 첫 번째 노드를 가리키디 때문에 리스트의 시작 부분에 노드를 추가하는 것은 비교적 쉽다. 새로운 노드를 하나 생성하고 새로운 노드의 link에 현재의 head값을 저장한 후에,
 head를 변경하여 새로 만든 노드를 가리키도록 하면 된다. insert_first()은 변경된 헤드포인터를 반환한다. 따라서 반환된 값을 헤드포인트에 저장하여야 한다.

 ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/608c93b3-9d0f-442e-a19c-1e03972a9406)

```c
ListNode *insert_first(ListNode *head, int value){
    ListNode *p=(ListNode*)malloc(sizeof(ListNode));//(1)
    p->data=value;//(2)
    p->link=head;//(3)
    head=p;//(4)
    return head;//(5)
}
```

### 알고리즘 설명

1. 동적 메모리 할당을 통하여 새로운 노드 p를 생성한다.
2. p->data에 value를 저장한다.
3. p->link를 현재의 head값으로 변경한다.
4. head를 p값으로 변경한다.
5. 변경된 헤드 포인터 반환


## 삽입 연산(insert())
insert()는 가장 일반적인 경우로서 연결 리스트의 중간에 새로운 노드를 추가한다. 이때는 반드시 삽입되는 위치의 선행 노드를 알아야 삽입이 가능한다.
선행 노드를 pre가 가리키고 있다고 가정하자.
예를 들어서 아래 그림에서 20과 40 사이에 30을 삽입하여 보자. 다음과 같은 절차가 필요하다.

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/3bb69379-d11c-4d95-ac31-80ae3c023790)

```c
ListNode *insert(ListNode *head, ListNode *pre, element value){
    ListNode *p=(ListNode*)malloc(sizeof(ListNode));//(1)
    p->data=value;//(2)
    p->link=pre->link;//(3)
    p->link=p;//(4)
    return head;//(5)
}
```

### 알고리즘 설명
1. 새로운 노드를 생성하여 변수 p로 가리킨다.
2. p의 데이터 필드에 20을 저장한다.
3. p의 링크 필드가 노드 30을 가리키게 변경한다.
4. 10의 링크 필드가 20을 가리키도록 한다.
5. 변경된 헤드포인터 반환

## 단순 연결 리스트_삭제연산(delete_first())
첫 번째 노드를 삭제하는 함수 delete_first는 다음과 같은 원형을 가진다.
```c
ListNode *delete_first(ListNode *head)
```

시작부분 노드 삭제 절차
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/dd97e054-2769-4337-94b1-1866a63b0e0f)

```c
ListNode *delete_first(ListNode *head){
    ListNode *removed;
    if(head==NULL) return NULL;
    removed=head;//(1)
    head-removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}
```

### 알고리즘 설명
1. 헤드포인터의 값을 removed에 복사한다.
2. 헤트포인터 값을 head->link로 변경한다.
3. removed가 가리키는 동적 메모리를 반환한다.
4. 변경된 헤드포인터를 반환한다.


## 삭제 연산(delete())
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/04e0ee24-932a-46c0-a5c8-29f353819d68)
```c
ListNode *delete(ListNode *head, ListNode *pre){
    ListNode *removed;
    removed=pre->link;//(1)
    pre->link=removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}
```

### 알고리즘 설명
1. 삭제할 노드를 찾는다.
2. 노드 10의 링크필드가 노드 30을 가리키게 한다.
3. 삭제할 노드의 동적 메모리를 반납한다.
4. 변경된 헤드포인터를 반환한다.


## 방문 연산 코드(print_list())
우리는 연결 리스트의 노드를 방문하면서 노드를 대상으로 다양한 작업을 할 수 있다. 예를 들면 노드를 방문하면서 노드의 데이터를 화면에 출력할 수 있다.
