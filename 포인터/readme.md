# 포인터
### 포인터란?
* 포인터(pointer): 주소를 가지고 있는 변수

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/4ac61cc3-bb07-450a-924b-9a6b75f135a0)


### 메모리의 구조
* 변수는 메모리에 저장된다.
* 메모리는 바이트 단위로 엑세스된다.
* 첫번째 바이트의 주소는 0, 두번째 바이트는 1...

![image](https://github.com/qlkdkd/DataStruct/assets/71871927/8c327d08-bc90-40bf-a086-12478f23dbb9)

### 변수와 메모리
* 변수의 크기에 따라서 차지하는 메모리 공간이 달라진다.
* `char`형 변수: `1`바이트, `int`형 변수: `4`바이트,...

```c
int main(){
  int i=10;
  char c=69;
  float f=12.3;
  return 0;
}
```
![Uploading image.png…]()
