#include<stdio.h>

int main() {
	int a[] = { 10, 20, 30, 40, 50 };
	int* p;

	p = a;
	printf("배열의 값: \n");
	for (int i = 0; i < 5; i++) {
		printf("a[%d]=%d ", i, a[i]);
	}
	printf("\n");

	printf("배열의 주소: \n");
	for (int i = 0; i < 5; i++) {
		printf("p[%d]=%d ", i, p[i]);
	}
	printf("\n");

	return 0;
}