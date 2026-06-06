#include <stdio.h>
#include "game.h"

int main(){
    int ch;
    
    while(1){
        menushow();
        
        int r = scanf("%d",&ch);
        if(r == EOF){
            printf("\nno more input, exiting\n");
            return 0;
        }
        if(r != 1){
            printf("please enter a valid number\n");
            int c; while((c=getchar())!='\n' && c!=EOF);
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