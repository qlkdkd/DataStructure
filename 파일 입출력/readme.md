# 12. 파일 입출력

 ## 1. 스트림
 * 입출력 장치들은 상당히 다양한 방식으로 데이터를 주고 받지만, C에서는 스트림(stream)이라는 개념을 사용하여 동일한 방법으로 입출력
 * C에서는 동일한 라이브러리 함수로 입출력
 * 스트림: 모든 입력과 출력을 바이트(byte)들의 흐름으로 생각하는 것

 * 스트림의 장점: 독립성
    * 입출력 장치에 상관 없이 우리는 동일한 함수를 사용하여 프로그램을 작성할 수 있음
    * 예) fget()라고 하는 함수는 키보드의 하나의 문자를 받을 수 있고 하드 디스크에 있는 파일에서도 하나의 문자를 읽을 수 있다.
  
### 표준 입출력 스트림
* 표준 입출력 스트림: 프로그램의 동작에 필수적인 몇 개의 기본적인 스트림은 프로그램 실행 시 자동으로 실행됨
* 이들 스트림은 프로그램 실행 시에 자동으로 만들어지고 프로그램 종료 시 자동으로 없어짐

* 표준 입출력 스트림

이름|스트림|연결 장치
---|---|---
stdin|표준 입력 스트림|키보드
stdout|표준 출력 스트림|모니터의 화면
stderr|표준 오류 스트림|모니터의 화면

* 스트림의 개수는 일반적으로 100개 이상이지만 보통 위 3개가 가장 많이 쓰임
* stdin: scanf()를 사용하면 stdin스트림 사용하게 됨
* stdout: printf()를 사용하면 stdout스트림 사용하게 됨
* stderr: 오류 메시지 출력하기 위하여 만들어진 스트림

![image](https://github.com/qlkdkd/DataStructure/assets/71871927/bf4788db-44e2-408f-9669-5df239b19905)

### 파일도 스트림에 연결시킬 수 있다.
* c에서 파일은 곧 스트림
* 운영 체제에서는 하나의 프로세스 당 100여개의 스트림이 지원되고 스트림 중에서 0번, 1번, 2번 스트림은 stdin, stdout, stderr로 미리 정의됨

--

## 2. 파일의 기초
* 실제 응용 프로그램에서는 데이터나 현재의 설정 정보를 저장하기 위하여 디스크에 저장되는 파일을 많이 사용함
* 데이터는 변수에 저장되고, 변수는 메모리에 저장되는데, 메모리는 영구적인 저장장치가 아님
    * 전원이 꺼지면 메모리에 있었던 데이터는 사라짐
    * 데이터를 영구적으로 보관하기 위해 디스크에 파일을 생성시켜 보관
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/3fbd3806-e623-4992-adbc-f3785ee487a3)

### 파일의 개변
* c에서 모든 입출력은 스트림을 통해 이루어짐
* 파일도 스트림으로 취급-> 파일도 일련의 연속된 바이트
* 파일에 대한 입출력도 표준 입출력과 동일한 함수들로 이루어짐
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/0353138e-cbe8-4c77-974e-1370e9b59a1c)

### 파일의 유형
1. 텍스트 파일
    * 사람이 읽을 수 있는 텍스트가 들어있는 파일
    * c프로그램 소스 파일이나 메모장 파일이 텍스트 파일의 예
    * 텍스트 파일은 아스키 코드를 이용하여 저장: 텍스트 파일은 모니터, 키보드, 프린터 등이 모두 문자 데이터만을 처리함
    * 텍스트 파일은 연속적인 라인들로 구성
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/551db2b3-4c9c-484d-8044-9c8d48e5c470)

2. 이진 파일
    * 사람이 읽을 수는 없으나 컴퓨터는 읽을 수 있는 파일-> 이진 데이터가 직접 저장되어 있는 파일
    * 텍스트 파일과는 달리 라인들로 분류되지 않음
    * 모든 문자들은 특별한 의미를 가지지 않고 데이터로 취급됨
    * 이진 파일은 특정 프로그램에 의해서만 판독 가능
    * 예) c프로그램 실행 파일, 사운드 파일, 이미지 파일
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/f0f55ad2-d34e-43b0-902e-0b53042c2147)

### 파일 처리의 개요
* 파일을 연다(open): 파일에서 데이터를 읽거나 쓸 수 있도록 모든 준비를 마치는 것. 내부적으로는 파일과 연결된 스트림을 만들게 됨
* 파일을 사용한 후에는 파일을 닫아야함
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/a7e9b3ae-091a-4c12-9f46-fe5080bb6fbf)

#### 파일 열기
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/00a13b1b-d95f-49c6-81f5-9008d77216e6)
* fopen()은 주어진 파일 이름을 가지고 파일을 생성하여 이 파일을 가리키는 FILE포인터를 반환
* FIlE구조체에는 파일의 열기, 읽기, 쓰기, 닫기에 관련된 모든 상태 정보가 들어 있음
```c
//형식
int fopen(const char *name, const char *mode);
//예
FILE *fp;
fp=fopen("text.txt", "w");
//설명: name이라는 이름을 가지는 파일을 mode에 지정된 모드로 연다. FILE포인터를 반환한다.
```

#### 파일 모드
모드|설명
---|---
"r"|읽기 모드로 파일을 연다.
"w"|쓰기 모드로 파일을 생성한다. 만약 파일이 존재하지 않으면 파일이 생성된다. 파일이 이미 존재하면 기존의 내용이 지워진다.
"a"|추가 모드로 파일을 연다. 만약 똑같은 이름의 기존의 파일이 있으면 데이터가 파일의 끝에 추가된다. 파일이 없으면 새로운 파일을 만든다.

![image](https://github.com/qlkdkd/DataStructure/assets/71871927/60c0f231-fe83-436d-85dc-bf9982571344)

#### 파일 닫기
* 사용이 끝나면 반드시 파일을 닫아야 한다. 파일을 닫는 함수는 fclose()이다. fclose()는 stdio.h에 정의되어 있다.
```c
//형식
int fclose(FILE *stream);
//예
fclose(fp);
//설명: stream에 의하여 지정된 파일을 닫는다.
```

### 파일 입출력 예제
```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    FILE* fp = NULL;
    fp = fopen("sample.txt", "w");
    if (fp == NULL)printf("파일 열기 실패\n");
    else printf("파일 읽기 성공\n");

    fclose(fp);
    return 0;
}
```

## 3. 문자 단위 입출력
### 한 글자씩 쓰기
* fputc(c, fp): 문자 c를 fp에 쓴다. fp는 FILE의 포인터이다.
```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	FILE* fp = NULL;

	fp = fopen("alphabet.txt", "w");//파일을 쓰기 모드로 연다
	if (fp == NULL) {
		fprintf(stderr, "파일 alphabet.txt를 열 수 없음\n");
		exit(1);
	}

	char c;
	for (c = 'a'; c <= 'z'; c++)
		fputc(c, fp);
	fclose(fp);
	return 0;
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/ee84cbf6-6d79-482c-bd29-0d0dd52e0ccd)

### 한 글자씩 읽기
* fget(fp): fp에서 하나의 문자를 읽어서 반환. fp는 FILE의 포인터
* EOF(End Of File): 파일의 끝을 나타내는 특수문자
```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	FILE* fp = NULL;
	int c;//정수 변수에 주의

	fp = fopen("alphabet.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "원본 파일 alphabet.txt를 찾을 수 없습니다.\n");
		exit(1);
	}
	while ((c = fgetc(fp))!= EOF)
		putchar(c);
	fclose(fp);
	return 0;
}
```
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/74f48cf6-6f2a-425f-85b8-e770ecdfe71c)

### 한 줄씩 읽고 쓰기
* fputs(s, fp): 문자열 s를 fp에 쓴다. fp는 FILE포인터이다.
* fgets(fp): fp에서 한 줄을 읽어서 반환
```c

```
