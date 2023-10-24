#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int mystrcmp(const char* str1, const char* str2) {
	if (*str1 == *str2)
		return 0;
	else if (*str1 > *str2)
		return 1;
	else return -1;
}

int main() {
	char a = "호호호", b = "하하하", b2 = "하하";
	char b3 = "하하하하", c = "안녕";

	printf("호호호-호호호=%d\n" ,mystrcmp(&a, &a));
	printf("하하하-하하하=%d\n", mystrcmp(&b, &b2));
	printf("하하하-하하하하=%d\n", mystrcmp(&b, &b3));
	printf("호호호-안녕=%d\n", mystrcmp(&a, &c));

	return 0;
}
