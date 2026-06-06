#include <stdio.h>
#include "game.h"
#include "input.h"


int main(){
    int ch;
    
    while(1){
        menushow();
        
        int r = read_int(&ch);
        if(r == EOF){
            printf("\nno more input, exiting\n");
            return 0;
        }
        if(r == 0){
            printf("please enter a valid number\n");
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