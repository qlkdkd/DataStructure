#include<stdio.h>

void modify(int value) {
	value = 99;
}

int main() {
	int number = 1;

	modify(number);
	printf("number=%d\n", number);
	return 0;
}