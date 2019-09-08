#include "tinyc.h"

int tst[20] = {0};
void test(void) {
    int i = 0;

    tst[i++] = IMM;
    tst[i++] = 10;
    tst[i++] = PUSH;
    tst[i++] = IMM;
    tst[i++] = 20;
    tst[i++] = ADD;
    tst[i++] = PUSH;
    tst[i++] = EXIT;

    pc = tst;
    // printf("pc = tst: %u\n", pc);
}