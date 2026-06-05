#include <stdio.h>
#include "links.h"
#include "board.h"
#include "geom.h"

int movr[8] = {1,1,2,2,-1,-1,-2,-2};
int movc[8] = {2,-2,1,-1,2,-2,1,-1};

int haslink(int r1,int c1,int r2,int c2,char p){
    int i;
    for(i=0;i<numlinks;i++){
        if(alllinks[i].p != p) 
            continue;
        if((alllinks[i].r1==r1 && alllinks[i].c1==c1 && alllinks[i].r2==r2 && alllinks[i].c2==c2))
            return 1;
        if((alllinks[i].r1==r2 && alllinks[i].c1==c2 && alllinks[i].r2==r1 && alllinks[i].c2==c1))
            return 1;
    }
    return 0;
}

int willcut(int r1,int c1,int r2,int c2){
    int i;
    link curr;
    
    for(i=0;i<numlinks;i++){
        curr = alllinks[i];
        
        if((r1==curr.r1 && c1==curr.c1) || (r1==curr.r2 && c1==curr.c2))
            continue;
        if((r2==curr.r1 && c2==curr.c1) || (r2==curr.r2 && c2==curr.c2))
            continue;
        
        if(dotheycut(r1,c1,r2,c2,curr.r1,curr.c1,curr.r2,curr.c2)){
            return 1;
        }
    }
    return 0;
}

void makelinks(int r, int c, char p){
    int count = 0;
    int k,newr,newc;
    
    for(k=0;k<8;k++){
        newr = r + movr[k];
        newc = c + movc[k];
        
        if(!inrange(newr,newc)) 
            continue;
        if(grid[newr][newc] != p) 
            continue;
        if(haslink(r,c,newr,newc,p)) 
            continue;
        if(willcut(r,c,newr,newc)) 
            continue;
        
        if(numlinks >= MAXLINK){
            printf("reached max links\n");
            break;
        }
        
        alllinks[numlinks].r1 = r;
        alllinks[numlinks].c1 = c;
        alllinks[numlinks].r2 = newr;
        alllinks[numlinks].c2 = newc;
        alllinks[numlinks].p = p;
        numlinks++;
        count++;
    }
    
    if(count > 0){
        printf("made %d new links\n", count);
    }
}