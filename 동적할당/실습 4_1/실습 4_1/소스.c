#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct student_info {
    char name[10];
    int height;
    float weight;
} student_info;    

struct student_info* ptr;//struct student_info_ptr[10];

int main() {
    ptr=(student_info*)malloc(sizeof(student_info) * 4);
    for (int i = 0; i < 4; i++) {
        printf("이름: ");
        scanf("%s", ptr[i].name);
        printf("키: ");
        scanf("%d", &ptr[i].height);
        printf("몸무게: ");
        scanf("%f", &ptr[i].weight);
    }

    for (int i = 0; i < 4; i++) {
        printf("이름: %s, 키: %d, 몸무게: %f\n", ptr[i].name, ptr[i].height, ptr[i].weight);
    }

    free(ptr);
    return 0;
}