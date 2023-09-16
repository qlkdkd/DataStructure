#include <stdio.h>
#include <string.h>

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

void selectionSort(student_info arr[], int n, char key) {//key검색 알고리즘을 활용하여 정렬할 방법 찾기
    int i, j, min_idx;
    student_info tmp;
   
    //정렬 방법 검색하기
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (key == 'n' && strcmp(arr[j].name, arr[min_idx].name) < 0) {
                min_idx = j;//이름순으로 정렬하는 방법이므로 strcmp 함수 사용
            }
            else if (key == 'h' && arr[j].height < arr[min_idx].height) {
                min_idx = j;
            }
            else if (key == 'w' && arr[j].weight < arr[min_idx].weight) {
                min_idx = j;
            }
        }

        //정렬하기
        tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

void printStudents(student_info arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("이름: %s, 키: %d, 몸무게: %.1f\n", arr[i].name, arr[i].height, arr[i].weight);
    }
}

int main() {
    printf("원본 데이터:\n");
    printStudents(students, N_STUDENTS);

    printf("\n학생 이름으로 정렬:\n");
    selectionSort(students, N_STUDENTS, 'n');//key값을 n(이름)으로 설정하여 이름순으로 정렬하기
    printStudents(students, N_STUDENTS);

    printf("\n키로 정렬:\n");
    selectionSort(students, N_STUDENTS, 'h');//key값을 h(키)로 설정하여 키순으로 정렬하기
    printStudents(students, N_STUDENTS);

    printf("\n몸무게로 정렬:\n");
    selectionSort(students, N_STUDENTS, 'w');//key값을 w(몸무게)로 설정하여 몸무게순으로 정렬하기
    printStudents(students, N_STUDENTS);

    return 0;
}