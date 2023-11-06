#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int* p;
	int i, items;

	printf("항목 개수 입력: ");
	scanf("%d", &items);
	p = (int*)malloc(sizeof(int) * items);

	for (i = 0; i < items; i++) {
		printf("항목 입력: ");
		scanf("%d", &p[i]);
	}

	printf("입력된 항목들\n");
	for (i = 0; i < items; i++)
		printf("%d ", p[i]);
	printf("\n");
	free(p);

	return 0;
}