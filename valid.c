#include <stdio.h>
#include "valid.h"
#include "board.h"

int checkpeg(int r, int c, char player){
    if(!inrange(r,c)){
        printf("oops, thats outside the board\n");
        return 0;
    }
    
    if(grid[r][c] != '.'){
        printf("peg already placed\n");
        return 0;
    }
    
    if((r == 0 && c == 0) || (r == 0 && c == SIZE-1) ||
       (r == SIZE-1 && c == 0) || (r == SIZE-1 && c == SIZE-1)){
        printf("cant use corner spots\n");
        return 0;
    }
    
    if(player == 'R'){
        if(c == 0 || c == SIZE-1){
            printf("red player cant use left and right edges\n");
            return 0;
        }
    }
    
    if(player == 'B'){
        if(r == 0 || r == SIZE-1){
            printf("black player cant use top and bottom edges\n");
            return 0;
        }
    }
    
    return 1;
}