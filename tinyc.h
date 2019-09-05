#ifndef A_TINY_C_INTEPRETER_HEADER
#define A_TINY_C_INTEPRETER_HEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

int token;              // current token
char *src, *old_src;    // pointer to source code string
int poolsize;           // default size of text/data/stack
int line;               // line number

void scanning(void);
void expr(int level);
void parsing(void);
int eval(void);

#endif