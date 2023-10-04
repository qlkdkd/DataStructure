#include<stdio.h>

int add(int x, int y, int *sum) {
	*sum = x + y;
}

int main() {
	int x = 4, y = 5, sum;
	add(x, y, &sum);

	printf("sum=%d\n", sum);

	return 0;
}