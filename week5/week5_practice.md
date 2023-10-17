[이론](https://github.com/qlkdkd/DataStruct/blob/main/week5/readme.md)

# (실습 4) 동적 메모리할당

내용: 아래와 같은 구조체를 사용하여 다음의 작업을 하시오.
```
typedef struct student_info {
    char name[10];
    int height;
    float weight;
} student_info;
```


1) 동적할당으로 4명의 학생정보를 저장할 공간을 할당 받으시오.

2) 사용자로부터 4명의 학생정보를 입력받아서 할당받은 공간에 저장하시오.

- 4명의 학생 정보
"이순신", 172, 83.4 / "홍길동", 167, 72.5 / "김유신", 159, 70.8 / "유관순", 163, 58.4
 ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/df79742a-b955-4372-a44f-5f93b7be8515)

3) 학생이름으로 정렬하여 출력하시오.  
(문자열 비교하는 함수: strcmp(str1, str2) 와 문자열 copy 함수: strcpy(dest, src) 이용)
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f3288370-0d93-43ca-840a-d2f3588df0d7)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	 N_STUDENTS	4
typedef struct student_info {
	char name[10];
	int height;
	float weight;
} student_info;

void swap(student_info s[], int i, int j)
{
	student_info tmp;
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

void selection_sort_byname(student_info s[], int n) {
	int i, j, least;

	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(s[j].name, s[least].name) < 0)
				least = j;
		}
		swap(s, i, least);
	}
}

int main(void)
{
	int i;
	student_info* s;

	s = (student_info*)malloc(sizeof(student_info) * N_STUDENTS);
	if (s == (student_info*)NULL) {
		fprintf(stderr, "malloc fail!!!\n");
		exit(1);
	}

	for (i = 0; i < N_STUDENTS; i++) {
		printf("이름: ");
		scanf("%s", s[i].name);
		printf("키: ");
		scanf("%d", &s[i].height);
		printf("몸무게: ");
		scanf("%f", &s[i].weight);
	}

	selection_sort_byname(s, N_STUDENTS);

	for (i = 0; i < N_STUDENTS; i++) {
		printf("%s %d %f \n", s[i].name, s[i].height, s[i].weight);
	}

	free(s);	// 메모리 할당 해제

	return 0;
}

```
 

(실습 4) up/down 게임 프로그램

- 컴퓨터가 1~100까지의 임의의 수 하나를 선택한다.
- 사용자는 1~100까지의 수 중에서 추측한 수를 입력한다.
- 컴퓨터는 사용자가 추측한 수가 컴퓨터가 선택한 수보다 작으면 UP, 크면 DOWN이라고 알려준다.
- 사용자가 컴퓨터가 선택한 수를 맞추면 게임은 끝난다.
- 게임이 끝나면 사용자가 추측했던 수를 모두 보여준다.
  (이 때 사용자가 추측했던 수를 저장하는 배열을 malloc으로 크기 100개 정수로 할당하시오.)

    (참고) 메모리 할당: malloc() 함수 사용  (#include <malloc.h> 해야함)
            무작위 수 발생: rand() 함수 사용 (#include <stdlib.h> 해야함)       
                 무작위 수 발생 씨앗 값 설정: srand(씨앗 값) 이용
                 실행할 때마다 다른 무작위 수 발생: srand(time(NULL))  이용 (#include <time.h> 해야함)
            특정 범위의 수 발생: % 연산자 사용  
            ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f79ac262-2610-4f86-80ce-3cc6aa2b71ab)
            ![image](https://github.com/qlkdkd/DataStruct/assets/71871927/f28dcd86-4ce8-4865-96fc-28f207be342a)


```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, j, *user;
	int	num_computer;

	srand(time(NULL));
	num_computer = rand() % 100 + 1;
	user = (int *) malloc(sizeof(int)*100);
	if(user == (int *) NULL) {
		fprintf(stderr,"malloc fail !!! \n");
		exit(1);
	}
	
	printf("---------------------------------------\n");
	printf("              UP/DOWN 게임             \n");
	printf("---------------------------------------\n");
	printf(" 1~100 사이의 숫자 하나를 선택했습니다 \n");
	printf(" 맞춰보세요~~~ \n");
	printf("---------------------------------------\n");

	for(i=0; ;i++) {
		printf("숫자: ");
		scanf("%d",&user[i]);

		if(user[i] > num_computer) 
			printf("DOWN \n");
		else if(user[i] < num_computer)
			printf("UP \n");
		else {
			printf("%d번 만에 맞췄습니다.\n",i+1);
			printf("입력숫자: ");
			for(j=0; j<=i ; j++) {
				printf("%d ",user[j]);
			}
			printf("\n");
			break;
		}
	}
	free(user); // 메모리 할당 해제
}

```

 

 


 
