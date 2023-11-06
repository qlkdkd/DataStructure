#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//영화를 구조체로 표현
struct movie {
	char title[100];//영화 제목
	double rating;//영화 평점
};

int main() {
	struct movie* ptr;
	int i, n;
	printf("영화의 개수: ");
	scanf("%d", &n);
	getchar();//줄바꿈 문자 제거

	ptr = (struct movie*)malloc(n * sizeof(struct movie));

	if (ptr == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}

	for (i = 0; i < n; i++) {
		printf("영화 제목: ");
		gets_s(ptr[i].title, 100);//중간에 공백이 있는 제목도 받을 수 있어야 한다.
		printf("영화 평점: ");
		scanf("%lf", &ptr[i].rating);
	}

	printf("======================\n");
	for (i = 0; i < n; i++) {
		printf("영화제목: %s\n", ptr[i].title);
		printf("영화 평점: %lf\n", ptr[i].rating);
	}
	printf("=====================\n");

	free(ptr);
	return 0;
}