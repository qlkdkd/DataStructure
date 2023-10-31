#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {//노드 타입
	element data;
	struct ListNode* link;
}ListNode;

//오류 처리 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//첫 노드 삽입 연산
ListNode* insert_first(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//
    p->link = head;//(3)
    head = p;//(4)
    return head;//(5)
}

//노드 pre뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//(2)
    p->link = pre->link;//(3)
    p->link = p;//(4)
    return head;//(5)
}

//첫 노드 삭제
ListNode* delete_first(ListNode* head) {
    ListNode* removed;
    if (head == NULL) return NULL;
    removed = head;//(1)
    head = removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}

//pre가 가리키는 노드의 다음 노드 삭제
ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre->link;//(1)
    pre->link = removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}

//연결 리스트 출력
void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}



//테스트 프로그램
int main() {
    ListNode* head = NULL;
    
    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i);//insert_first()가 반환된 헤드 포인터를 head에 대입
        print_list(head);
    }
    for (int i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }

    return 0;
}