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
