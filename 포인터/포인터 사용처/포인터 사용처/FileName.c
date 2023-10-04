#include<stdio.h>

void sub(int* ptr) {
	printf("%d\n", ptr[10]);
}

int main() {
	int large_data[20];
	for (int i = 0; i < 20; i++)
		large_data[i] = i + 1;
	sub(large_data);
	return 0;
}