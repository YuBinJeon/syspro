#include <stdio.h>
#include <stdlib.h>

/* 모든 명령줄 인수를 출력한다. */
int main(int argc, char *argv[]) {
    int i;

    for (i = 0; i < argc; i++) {
        printf("argv[%d]: %s \n", i, argv[i]); /* 모든 명령줄 인수 출력 */
    }

    exit(0);
}
