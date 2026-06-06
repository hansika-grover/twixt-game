#include <stdio.h>
#include "input.h"

/* Discard the rest of the current input line (stops safely at EOF). */
static void flush_line(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF)
        ;
}

int read_int(int *out){
    int r = scanf("%d", out);
    if(r == EOF) return EOF;
    if(r != 1){ flush_line(); return 0; }
    return 1;
}

int read_two_ints(int *a, int *b){
    int r = scanf("%d %d", a, b);
    if(r == EOF) return EOF;
    if(r != 2){ flush_line(); return 0; }
    return 1;
}