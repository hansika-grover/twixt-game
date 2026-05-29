#include <stdio.h>
#include "board.h"

void setupgrid() {
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            grid[i][j] = '.';
        }
    }
    numlinks = 0;
}

int inrange(int r,int c){
    if(r >= 0 && r < SIZE && c >= 0 && c < SIZE)
        return 1;
    return 0;
}

void drawline() {
    int w = 4 + SIZE * 3;
    int i;
    for(i=0;i<w;i++)
        printf("-");
    printf("\n");
}

void showgrid() {
    int i,j;
    drawline();
    printf("R goes top to bottom, B goes left to right\n");
    drawline();

    printf("    ");
    for(j=0;j<SIZE;j++)
        printf("%2d ", j);
    printf("\n");

    for(i=0;i<SIZE;i++) {
        printf("%2d  ", i);
        for(j=0;j<SIZE;j++)
            printf(" %c ", grid[i][j]);
        printf("\n");
    }
    drawline();
}

void showlinks(){
    int i;
    int rcount = 0;
    int bcount = 0;
    
    drawline();
    printf("here are all the links made so far:\n");
    drawline();
    
    printf("\nRed player links:\n");
    for(i=0;i<numlinks;i++){
        if(alllinks[i].p == 'R'){
            printf("  %d. from (%d,%d) to (%d,%d)\n", rcount+1,
                   alllinks[i].r1, alllinks[i].c1, alllinks[i].r2, alllinks[i].c2);
            rcount++;
        }
    }
    if(rcount == 0) 
        printf("  no links yet\n");
    
    printf("\nBlack player links:\n");
    for(i=0;i<numlinks;i++){
        if(alllinks[i].p == 'B'){
            printf("  %d. from (%d,%d) to (%d,%d)\n", bcount+1,
                   alllinks[i].r1, alllinks[i].c1, alllinks[i].r2, alllinks[i].c2);
            bcount++;
        }
    }
    if(bcount == 0) 
        printf("  no links yet\n");
    
    drawline();
}