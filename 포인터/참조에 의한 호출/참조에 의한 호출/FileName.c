#include<stdio.h>

void modify(int* ptr) {
	*ptr = 99;//매개변수를 통하여 원본을 변경한다.
}

int main() {
	int number = 1;

	modify(&number);//주소를 계산해서 보낸다.
	printf("number=%d\n");

	return 0;
}