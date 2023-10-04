#include<stdio.h>
#include<stdlib.h>

char strings[2][10]={"Hello", "World"};

void set_pointer(char **p, int n){
    *p=strings[n];
}

int main(){
    char *p;
    set_pointer(&p, 0);
    printf("%s\n", p);
    set_pointer(&p, 1);
    printf("%s\n", p);
    return 0;
}
