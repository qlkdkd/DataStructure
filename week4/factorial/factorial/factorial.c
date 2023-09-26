#include<stdio.h>

int original_factorial(int x) {
	int result = 0;
	for (int i = 0; i < x; i++) {
		result *= i;
	}
	return result;
}

int factorial_circulation(int n) {
	if (n <= 1)return 1;
	else return(n * factorial_circulation(n - 1));
}

int factorial_c2(int n) {
	if (n <= 1)return 1;
	else return n * facorial_c2(n - 1);
}

int main() {
	int n = 5;
	printf("factorial_original: %d\n", original_factorial);
	printf()

}