#include "tinyc.h"

void parsing(void) {
    scanning();
    while (token > 0) {
        printf(msg[9], token);
        scanning();
    }
}