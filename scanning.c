#include "tinyc.h"

void scanning(void) {
    char *last_pos;
    int hash;

    // '=' here is not a fault
    while (token = *src) {
        ++src;

        // parse token
        if (token == '\n') {
            line++;
        } else if (token == '#') {    // Skip macro, cause it's not supported
            while (*src != 0 && *src != '\n')
                src++;
        }

    }

    return;
}