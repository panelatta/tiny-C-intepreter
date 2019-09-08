#include    <stdio.h>

int         token;                  // current token
char        *src, *old_src;         // pointer to source code string
size_t      poolsize;               // default size of text/data/stack
int         line;                   // line number

unsigned    *text,                  // text segment
            *old_text,              // for dump text segmnet
            *stack;
char        *data;                  // data segment
                                    
                                    // virtual machine registers
unsigned    *pc,                    
            *sp,
            *bp;
int         ax,
            cycle;