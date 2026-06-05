#include "win.h"

void clearreach(){
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            reach[i][j] = 0;
        }
    }
}

int didwin(char p){
    int i,j;
    int changed;
    int row1,col1,row2,col2;
    
    clearreach();
    
    if(p == 'R'){
        for(j=1;j<SIZE-1;j++){
            if(grid[0][j] == 'R')
                reach[0][j] = 1;
        }
    }
    else{
        for(i=1;i<SIZE-1;i++){
            if(grid[i][0] == 'B')
                reach[i][0] = 1;
        }
    }
    
    changed = 1;
    while(changed){
        changed = 0;
        
        for(i=0;i<numlinks;i++){
            if(alllinks[i].p != p) 
                continue;
            
            row1 = alllinks[i].r1;
            col1 = alllinks[i].c1;
            row2 = alllinks[i].r2;
            col2 = alllinks[i].c2;
            
            if(reach[row1][col1] && !reach[row2][col2]){
                reach[row2][col2] = 1;
                changed = 1;
            }
            if(reach[row2][col2] && !reach[row1][col1]){
                reach[row1][col1] = 1;
                changed = 1;
            }
        }
    }
    
    if(p == 'R'){
        for(j=1;j<SIZE-1;j++){
            if(reach[SIZE-1][j])
                return 1;
        }
    }
    else{
        for(i=1;i<SIZE-1;i++){
            if(reach[i][SIZE-1])
                return 1;
        }
    }
    return 0;
}