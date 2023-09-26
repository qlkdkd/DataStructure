#include<stdio.h>

double slow_power(double x, int n)
{
	int i;
	double result = 1.0;

	for (i = 0; i < n; i++)
		result = result * x;
	return result;
}

double power(double x, int n) {
	if (n == 0)
		return 1;
	else if (n % 2 == 0) {
		return power(x*x, n / 2);
	}
	else if (n % 2 != 0) {
		return x * power(x * x, (n - 1) / 2);
	}
}

int main() {
	printf("slow_power(%lf, %d): %lf\n",2.0, 10, slow_power(2.0, 10));
	printf("power(%lf, %d): %lf\n",2.0, 10, power(2.0, 10));

	return 0;
}