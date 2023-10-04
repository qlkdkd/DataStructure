#include<stdio.h>
int main() {
	char* pc;
	int* pi;
	double* pd;

	pc = (char*)10000;
	pi = (int*)10000;
	pd = (double*)10000;
	printf("증가전 pc: %d, pi: %d, pd: %d\n", pc, pi, pd);

	pc++;
	pi++;
	pd++;

	printf("증가 후 pc: %d, pi: %d, pd: %d\n", pc, pi, pd);

	return 0;
}

/*
증가전 pc: 10000, pi: 10000, pd: 10000
증가 후 pc: 10001, pi: 10004, pd: 10008
*/