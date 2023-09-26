프로그래밍 과제 #1
아래의 난이도 A, B 중에 선택하여 프로그램하고 제출하시오!!!

다음과 같은 구조체를 갖는 학생정보 배열을 이용하여 

(난이도 A) 해당 배열의 정보를 출력하는 프로그램을 작성하시오. (만점 6/10점)

(난이도 B) 해당 배열을 학생이름, 키, 몸무게를 기준으로 정렬하여 출력하는 프로그램을 작성하시오. (단 정렬하는 방법은 실습시간에 배운 선택정렬을 이용할 것) (만점 10/10점)

```c
#include <stdio.h>

#define N_STUDENTS  4

typedef struct student_info {
    char    name[10];
    int     height;
    float   weight;
} student_info;

student_info students[N_STUDENTS] = {
    {"이순신", 172, 83.4},
    {"홍길동", 167, 72.5},
    {"김유신", 159, 70.8},
    {"유관순", 163, 58.4}
};
```

제출 파일 내용  (한글 혹은 워드 파일로 정리하여 제출)
프로그램 소스
동작 화면을 캡춰한 그림
동작화면 클릭
과제중 발생한 문제, 해결방법, 배운 것, 느낀점을 포함할 것
주의사항: 이름으로 정렬할 때는 strcmp() 함수를 이용하여 비교할 것    

[답안](https://github.com/qlkdkd/DataStruct/blob/main/Homework1/Homework1/Homework1.c)
