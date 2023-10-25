#define MAX_LIST_SIZE 100
#include<stdio.h>

typedef int element;//항목의 정의

typedef struct {
	element array[MAX_LIST_SIZE];//배열의 정의
	int size;//현재 리스트에 저장된 항목들의 개수
}ArrayListType;


//오류처리 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


//리스트 초기화 함수
void init(ArrayListType* L) {
	return L->size == 0;
}

//리스트가 비어있으면 1을 반환
//그렇지 않으면 0을 반환
int is_empty(ArrayListType* L) {
	return L->size == 0;
}


//리스트가 가득 차 있으면 1을 반환
//그렇지 않으면 0을 반환
int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}


//리스트 출력
void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}
	printf("\n");
}

//맨 끝에 항목 추가
void insert_last(ArrayListType *L, element item){
	if(L->size>=MAX_LIST_SIZE){
		error("리스트 오버플로우");
	}
	L->array[L->size++]=item;
}


//pos위치에 항목 추가
void insert(ArrayListType *L, int pos, element item){
	if(!is_full(L) && (pos>=0) && (pos<=L->size)){
		for(int i=(L->size-1); i>=pos; i--)
			L->array[i+1]=L->array[i];
		L->array[pos]=item;
		L->size++;
	}
}
