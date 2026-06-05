#include <stdio.h>
#include "game.h"
#include "board.h"
#include "valid.h"
#include "links.h"
#include "win.h"

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

void putpeg(char *player){
    int row,col;
    printf("which spot? enter row then column: ");
    
    if(scanf("%d %d", &row, &col) != 2){
        printf("incorrect, give two numbers\n");
        while(getchar()!='\n');
        return;
    }
    
    if(checkpeg(row,col,*player)){
        grid[row][col] = *player;
        printf("peg placed!\n");
        
        makelinks(row,col,*player);
        
        if(*player == 'R')
            *player = 'B';
        else
            *player = 'R';
    }
}

void startgame(){
    setupgrid();
    char current = 'R';
    int choice;
    
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
        
        printf("its player %c turn now\n", current);
        gamemenu();
        
        if(scanf("%d",&choice) != 1){
            printf("please enter valid input\n");
            while(getchar()!='\n');
            continue;
        }
        
        if(choice == 1){
            putpeg(&current);
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