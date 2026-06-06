#include <stdio.h>
#include "game.h"
#include "board.h"
#include "valid.h"
#include "links.h"
#include "win.h"
#include "input.h"

link alllinks[MAXLINK];
int numlinks = 0;
char grid[SIZE][SIZE];
int reach[SIZE][SIZE];

void menushow(){
    printf("\nWelcome,Choose an option:\n");
    printf("1. start new game\n");
    printf("2. quit\n");
    printf("your choice: ");
}

void gamemenu(){
    printf("\nwhat would you like to do?\n");
    printf("1. put a peg\n");
    printf("2. see all links\n");
    printf("3. go back to menu\n");
    printf("choose: ");
}

int putpeg(char *player){
    int row,col;
    printf("which spot? enter row then column: ");
    
    int r = read_two_ints(&row, &col);
    if(r == EOF){
        printf("\nno more input\n");
        return 0;
    }
    if(r == 0){
        printf("incorrect, give two numbers\n");
        return 0;
    }
    
    if(checkpeg(row,col,*player)){
        grid[row][col] = *player;
        printf("peg placed!\n");
        
        makelinks(row,col,*player);
        
        if(*player == 'R')
            *player = 'B';
        else
            *player = 'R';
        return 1;
    }
    return 0;
}

void startgame(){
    setupgrid();
    numlinks=0;
    char current = 'R';
    int choice;
    int pegs_placed =0;
    
    while(1){
        showgrid();
        
        if(didwin('R')){
            printf("\nPlayer R has won the game!\n");
            printf("going back...\n");
            break;
        }
        if(didwin('B')){
            printf("\nPlayer B has won the game!\n");
            printf("going back...\n");
            break;
        }
        if(pegs_placed >= MAX_PEGS){
            printf("\nThe board is full - the game is a draw!\n");
            printf("going back...\n");
            break;
        }

        
        printf("its player %c turn now\n", current);
        gamemenu();
        
        int r = read_int(&choice);
        if(r == EOF){
            printf("\nno more input, returning to menu\n");
            break;
        }
        if(r == 0){
            printf("please enter valid input\n");
            continue;
        }
        
        if(choice == 1){
            if(putpeg(&current))pegs_placed++;
        }
        else if(choice == 2){
            showlinks();
        }
        else if(choice == 3){
            printf("returning back\n");
            break;
        }
        else{
            printf("not a valid choice\n");
        }
    }
}