# 1. 자료구조와 알고리즘

## 일상생활에서의 사물의 조직화
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/39c0eb66-ad6e-44a3-8e8e-6ab3233f4bea)
## 일상생활과 자료구조의 비교
(표 1-1) 일상생활과 자료구조의 유사성
**일상생활에서의 예**|**해당하는 자료구조**
---|---
그릇을 쌓아서 보관하는 것|스택
마트 계산대의 줄|큐
버킷 리스트|리스트
영어사전|사전
지도|그래프
컴퓨터의 디렉토리 구조|트리

## 자료구조와 알고리즘
### 프로그램: 자료구조 + 알고리즘
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/951a1f76-1798-4bd8-8402-94553a1e31f1)
```c
#define MAX_ELEMENTS 100
int score[MAX_ELEMENTS];//자료구조
int get_max_score(int n){//학생의 숫자는 n
  int i, largest;
  largest=scores[0];
  for(i=1; i<n; i++){
    if(scores[i]>largest){
      largest=scores[i];
    }
  }
  return largest;
}
```
