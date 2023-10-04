#include<stdio.h>

void set_pointer(char** pointer, int index) {
    if (index == 0) {
        *pointer = "Hello";
    }
    else if (index == 1) {
        *pointer = "World";
    }
    else {
        pointer = NULL;
    }
}

int main() {
    char strings[2][10] = { "Hello", "World" };
    char* p;

    set_pointer(&p, 0);
    printf("%s \n", p);
    set_pointer(&p, 1);
    printf("%s \n", p);
    return 0;
}