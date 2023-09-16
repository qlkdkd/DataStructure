#include <stdio.h>

#define	N_DATA	4
char data[N_DATA][10] = { "홍길동", "이순신", "강감찬", "유관순" };

void print_data(char list[][10], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%s ", list[i]);
	}
	printf("\n");
}


int find_min(char data[][10], int start, int n)
{
	int i, least;

	least = start;
	for (i = start + 1; i < n; i++) {
		if (strcmp(data[i], data[least]) < 0)
			least = i;
	}
	return least;
}

int main(void)
{
	int i, n;
	char tmp[10];

	printf("정렬 전:");
	print_data(data, N_DATA);

	for (i = 0; i < N_DATA; i++) {
		n = find_min(data, i, N_DATA);

		strcpy(tmp, data[i]);
		strcpy(data[i], data[n]);
		strcpy(data[n], tmp);
	}

	printf("정렬 후:");
	print_data(data, N_DATA);

}