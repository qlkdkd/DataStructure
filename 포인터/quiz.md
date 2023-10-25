1
```c
#include<stdio.h>
#define size 10

int data[size]={1, 2, 3,4,5,6,7,8, 9};

void printArray(int *A, int n){
    int i=0;
    printf("배열 출력\n");
    for(i=0; i<n; i++){
        printf("%d ", *(A+i));
    }
    printf("\n");
}

int getArraySum(int *A, int n){
    int i=0;
    int sum=0;
    for(i=0; i<n; i++){
        sum+=*(A+i);
    }
    return sum;
}

int main(){
    printArray(data, size);
    printf("배열의 합: %d\n", getArraySum(data, size));
    
    return 0;
}
```
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/347ce9f8-d2da-4012-a576-2f119c8c3867)

2
```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define size 5

void revercePrint(int* a, int n) {
    for (int i = size-1; i >= 0; i--) {
        printf("%d ", *(a + i));
    }
    printf("\n");
}
int main() {
    int data[size];

    //데이터 입력
    for (int i = 0; i < size; i++) {
        printf("%d번째 데이터 입력: ", i + 1);
        scanf("%d", &data[i]);
    }

    revercePrint(&data, size);
    return 0;
}
```

3
```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void quadratic(int a, int b, int c, double* xplus, double* xminus) {
	*xminus = (-b - sqrt(b * b - 4 * a * c) / (2 * a));
	*xplus = (-b + sqrt(b * b - 4 * a * c) / (2 * a));
}

int main() {
	int a, b, c;
	printf("a, b, c입력: ");
	scanf("%d %d %d", &a, &b, &c);
	double xplus, xminus;
	quadratic(a, b, c, &xplus, &xminus);

	printf("양의 실근: %lf\n", xplus);
	printf("음의 실근: %lf\n", xminus);

	return 0;
}
```
