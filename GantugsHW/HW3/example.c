#include<stdio.h>
int main(){
    printf("x %d a",getpid());
    fork();
    printf("y %d b",getpid());
return 0;
}
