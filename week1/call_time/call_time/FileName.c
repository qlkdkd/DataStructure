#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	clock_t start, stop;
	double duration;
	start = clock();//측정 시작
	for (int i = 0; i < 1000000; i++)//의미 없는 반복 루프
		;
	stop = clock();
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("수행시간: %f\n", duration);
	return 0;
}