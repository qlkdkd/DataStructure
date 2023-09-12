#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define N_DATA 8
int data[N_DATA] = { 12,23, 98, 45, 11, 92, 56, 79 };

void print_data(int list[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

int find_min(int data[], int start, int n)
{
	int i, least;

	least = start;
	for (i = start + 1; i < n; i++) {
		if (data[i] < data[least])
			least = i;
	}
	return least;
}

int main()
{
	int i, n, tmp;
	printf("정렬 전: ");
	print_data(data, N_DATA);

	for (i = 0; i < N_DATA; i++) {
		n = find_min(data, i, N_DATA);

		tmp = data[i];
		data[i] = data[n];
		data[n] = tmp;
	}

	printf("정렬 후: ");
	print_data(data, N_DATA);
	return 0;
}
