#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int add(int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	int* num;
	num = (int*)malloc(sizeof(int) * 10);

	if (num == (int*)NULL) {
		fprintf(stderr, "malloc fail!\n");
		exit(1);
	}

	//1부터 100까지의 무작위 정수 할당
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		num[i] = rand() % 100 + 1;
	}

	//배열의 값을 출력
	printf("배열 값: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");

	//add함수 호출하여 배열의 합 구하기
	int result = add(num, 10);

	printf("배열의 합: %d\n", result);

	free(num);
	return 0;
}