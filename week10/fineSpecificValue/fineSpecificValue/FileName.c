#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {//노드 타입
    element data;
    struct ListNode* link;
}ListNode;


//첫 노드 삽입 연산
ListNode* insert_first(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//
    p->link = head;//(3)
    head = p;//(4)
    return head;//(5)
}
//연결 리스트 출력
void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

//탐색 함수
ListNode* search_list(ListNode* head, element x) {
    ListNode* p = head;

    while (p != NULL) {
        if (p->data == x)return p;
        p = p->link;
    }
    return NULL;//탐색 실패
}


//테스트 프로그램
int main() {
    ListNode* head = NULL;

    head = insert_first(head, 10);
    print_list(head);

    head = insert_first(head, 20);
    print_list(head);

    head = insert_first(head, 30);
    print_list(head);

    if (search_list(head, 30) != NULL)
        printf("리스트에서 30을 찾았습니다.\n");
    else
        printf("리스트에서 30을 찾지 못했습니다.\n");
    
    return 0;
}