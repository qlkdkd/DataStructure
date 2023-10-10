#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int x[10];
int* ptr;

int main() {
	ptr = malloc(sizeof(int)*10);  //int ptr[10]
	*(ptr + 0) = 70;//ptr[0]
	*(ptr + 1) = 80;//ptr[1]
	*(ptr + 2) = 90;//ptr[2]
	for (int i = 0; i < 10; i++) {
		ptr[i] = 70 + i*10;
		printf("%d ", ptr[i]);
	}

	return 0;
}