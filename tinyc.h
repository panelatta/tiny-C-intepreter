#ifndef A_TINY_C_INTEPRETER_HEADER
#define A_TINY_C_INTEPRETER_HEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <fcntl.h>
#include <io.h>
#include <process.h>

void scanning(void);
void expr(int level);
void parsing(void);
int eval(void);
void test(void);

// list of messages
char *msg[] = {
    "#0: Information: Compilation completed successfully.\n",

    "#1: Error: Could not open file(%s)\n.",
    "#2: Error: Unknown instruction(%d).\n",  
    "#3: Error: Could not malloc(%d) for source area.\n",
    "#4: Error: Reading failed. read() returned %d.\n",

    "#5: Error: Could not malloc(%d) for text segment area.\n",
    "#6: Error: Could not malloc(%d) for data segment area.\n",
    "#7: Error: Could not malloc(%d) for stack segment area.\n",

    "#8: Information: exit(%d).\n",
    "#9: Information: token is %c.\n"
};

// virtual machine instructions
enum {
        LEA,        // LEA <offset>, LOAD ADDRESS OF ARGUMENTS
        IMM,        // IMM <num>, LOAD <num> INTO AX
        JMP,        // JMP <addr>, JUMP TO THE <addr>
        CALL,       // CALL <addr>, CALL SUBROUTINE
        JZ,         // JZ, JUMP IF AX = 0
        JNZ,        // JNZ, JUMP IF AX != 0
        ENT,        // ENT <size>, MAKE NEW STACK FRAME
        ADJ,        // ADJ <size>, REMOVE ARGUMENTS FROM FRAME
        LEV,        // LEV, RESTORE CALL FRAME AND PC
        LI,         // LI, LOAD INT INTO AX, ADDRESS IN AX
        LC,         // LC, LOAD CHAR INTO AX, ADDRESS IN AX
        SI,         // SI, SAVE INT TO ADDRESS, VALUE IN AX, ADDRESS ON STACK 
        SC,         // SC, SAVE CHAR TO ADDRESS, VALUE IN AX, ADDRESS ON STACK
        PUSH,       // PUSH, PUSH THE VALUE IN AX ONTO STACK

                    // **FOR ALL OPERATOR INSTURCTIONS**
                    // **PLEASE SET ARG1 ONTO STACK, ARG2 IN AX**
                    // **AFTER CALC, RESULT STORED IN AX, STACK POPPED**
        OR,         // OR
        XOR,        // XOR
        AND,        // AND
        EQ,         // EQ, EQUAL
        NE,         // NE, NOT EQUAL
        LT,         // LT, LESS
        GT,         // GT, GREATER
        LE,         // LE, LESS OR EQUAL
        GE,         // GE, GREATER OR EQUAL
        SHL,        // SHL, LOGICALLY SHIFT LEFT
        SHR,        // SHR, ARITHMETICALLY SHIFT RIGHT
        ADD,        // ADD
        SUB,        // SUB
        MUL,        // MUL
        DIV,        // DIV, INTEGER DIVISION
        MOD,        // MOD

        OPEN,
        READ,
        CLOS,
        PRTF,
        MALC,
        MSET,
        MCMP,
        EXIT
};

#define true        (int)(1)
#define false       (int)(0)

extern int          token;                  // current token
extern char         *src, *old_src;         // pointer to source code string
extern size_t       poolsize;               // default size of text/data/stack
extern int          line;                   // line number

extern unsigned     *text,                  // text segment
                    *old_text,              // for dump text segmnet
                    *stack;
char                *data;                  // data segment
                                    
                                            // virtual machine registers
extern unsigned     *pc,                    
                    *sp,
                    *bp;
extern int          ax,
                    cycle;

#endif