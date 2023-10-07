다음과 같이 0이 아닌 요소들만을 나타내는 방법으로 표현된 두 개의 행렬을 

(난이도 A) 해당 배열의 정보를 출력하는 프로그램을 작성하시오. (만점 6/10점)

(난이도 B) 배열의 전체 요소를 표현하는 행렬로 변환하고 변환된 행렬을 곱해서 출력하는 프로그램을 작성하여 제출하시오. (만점 10/10점)

```c
#include <stdio.h>
#define  MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} element;
typedef struct SparseMatrix {
    element data[MAX_TERMS];
    int rows; // 행의 개수
    int cols; // 열의 개수
    int terms; // 항의 개수
} SparseMatrix;

SparseMatrix x1 = { {{1,1,5},{2,2,9}}, 3, 3, 2};
SparseMatrix y1 = { {{0,0,5},{2,2,9}}, 3, 3, 2};

SparseMatrix x2 = { {{0,0,1},{0,1,2},{0,2,3},{1,0,1},{1,1,2},{1,2,3},{2,0,1},{2,1,2},{2,2,3}}, 3, 3, 9};
SparseMatrix y2 = { {{0,0,1},{0,1,1},{0,2,1},{1,0,1},{1,1,1},{1,2,1},{2,0,1},{2,1,1},{2,2,1}}, 3, 3, 9};

SparseMatrix x3 = { {{0,0,7},{0,2,2},{1,2,3},{2,0,7}}, 3, 3, 4};
SparseMatrix y3 = { {{0,1,5},{0,2,8},{1,2,4},{2,0,4},{2,2,1}}, 3, 3, 5};
```
동작화면
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/a53ad84f-8893-421c-adb2-a7e9dc64b140)

[GPT 코드](https://github.com/qlkdkd/DataStruct/blob/main/H2/Homework2_GPTver/Homework2_GPTver/FileName.c) 
