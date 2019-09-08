#include "tinyc.h"

int main(int argc, char **argv) {
    argc--;
    argv++;

    poolsize = 256 * 1024;  // arbitrary size
    line = 1;

    // open source file
    int fp;
    if((fp = open(*argv, 0)) < 0) {
        printf(msg[1], *argv);
        exit(1);
    }
    // apply for memory
    if(!(src = old_src = (char *)malloc(poolsize))) {
        printf(msg[3], poolsize);
        exit(3);
    }
    // read in source file
    int end_offset;
    if((end_offset = read(fp, src, poolsize - 1)) <= 0) {
        printf(msg[4], end_offset);
        exit(4);
    }
    src[end_offset] = '\0';
    close(fp);
    
    char *src_addr = src;

    // allocate and clear memory for virtual machine
    if(!(text = old_text = (unsigned *)malloc(poolsize))) {
        printf(msg[5], poolsize);
        exit(5);
    }
    if(!(data = (char *)malloc(poolsize))) {
        printf(msg[6], poolsize);
        exit(6);
    }
    if(!(stack = (unsigned *)malloc(poolsize))) {
        printf(msg[7], poolsize);
        exit(7);
    }
    memset(text, 0, poolsize);
    memset(data, 0, poolsize);
    memset(stack, 0, poolsize);

    // initialing virtual machine registers
    bp = sp = (unsigned *)((unsigned)stack + poolsize);
    ax = 0;

    test();

    parsing();
    int res = eval();
    free(src_addr);
    return res;
}