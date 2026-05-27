#include <stdio.h>
#include "game.h"

int main(){
    int ch;
    
    while(1){
        menushow();
        
        if(scanf("%d",&ch) != 1){
            printf("please enter a valid number\n");
            while(getchar()!='\n');
            continue;
        }
        
        if(ch == 2){
            printf("exiting,thanks for playing\n");
            return 0;
        }
        else if(ch == 1){
            startgame();
        }
        else{
            printf("enter either 1 or 2\n");
        }
    }
    return 0;
}