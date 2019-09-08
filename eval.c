#include "tinyc.h"

// Running Virtual Machine
int eval() {
    int op, *tmp;

    while (true) {
        // virtual machine instructions
        if      (op == IMM)     {ax = *pc++;}       
        else if (op == LC)      {ax = *(char *)ax;}
        else if (op == LI)      {ax = *(int *)ax;}
        else if (op == SC)      {*(char *)*sp++ = ax;}
        else if (op == SI)      {*(int *)*sp++ = ax;}
        else if (op == PUSH)    {*--sp = ax;}

        else if (op == JMP)     {pc = (unsigned *)*pc;}
        else if (op == JZ)      {pc = (ax ? pc + 1 : (unsigned *)*pc);}
        else if (op == JNZ)     {pc = (ax ? (unsigned *)*pc : pc + 1);}

        else if (op == CALL)    {*--sp = (unsigned)(pc + 1); pc = (unsigned *)*pc;}
        else if (op == ENT)     {*--sp = (int)bp; bp = sp; sp = sp - *pc++;}
        else if (op == ADJ)     {sp = sp + *pc++;}
        else if (op == LEV)     {sp = bp; bp = (unsigned *)*sp++; pc = (unsigned *)*sp++;}
        else if (op == LEA)     {ax = (int)(bp + *pc++);}

        else if (op == OR)      {ax = (*sp++ |  ax);}
        else if (op == XOR)     {ax = (*sp++ ^  ax);}
        else if (op == AND)     {ax = (*sp++ &  ax);}
        else if (op == EQ)      {ax = (*sp++ == ax);}
        else if (op == NE)      {ax = (*sp++ != ax);}
        else if (op == LT)      {ax = (*sp++ <  ax);}
        else if (op == LE)      {ax = (*sp++ <= ax);}
        else if (op == GT)      {ax = (*sp++ >  ax);}
        else if (op == GE)      {ax = (*sp++ >= ax);}
        else if (op == SHL)     {ax = (*sp++ << ax);}
        else if (op == SHR)     {ax = (*sp++ >> ax);}
        else if (op == ADD)     {ax = (*sp++ +  ax);}
        else if (op == SUB)     {ax = (*sp++ -  ax);}
        else if (op == MUL)     {ax = (*sp++ *  ax);}
        else if (op == DIV)     {ax = (*sp++ /  ax);}
        else if (op == MOD)     {ax = (*sp++ %  ax);}

        // built-in instructions
        else if (op == EXIT)    {printf(msg[8], *sp); return *sp;}
        else if (op == OPEN)    {ax = open((char *)sp[1], sp[0]);}
        else if (op == CLOS)    {ax = close(*sp);}
        else if (op == READ)    {ax = read(sp[2], (char *)sp[1], *sp);}
        else if (op == PRTF)    {tmp = sp + pc[1];
                                 ax = printf((char *)tmp[-1], tmp[-2], tmp[-3],
                                             tmp[-4], tmp[-5], tmp[-6]);}
        else if (op == MALC)    {ax = (int)malloc(*sp);}
        else if (op == MSET)    {ax = (int)memset((char *)sp[2], sp[1], *sp);}
        else if (op == MCMP)    {ax = memcmp((char *)sp[2], (char *)sp[1], *sp);}

        // unknown instruction
        else                    {printf(msg[2], op); exit(2);}
    }

    return 0;
}