(실습 4) 동적 메모리할당

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




 

 


 
