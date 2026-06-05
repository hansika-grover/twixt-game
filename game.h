#ifndef GAME_H
#define GAME_H

#define SIZE 24
#define MAXLINK 3000

typedef struct {
    int r1, c1;
    int r2, c2;
    char p;
} link;

extern link alllinks[MAXLINK];
extern int numlinks;
extern char grid[SIZE][SIZE];
extern int reach[SIZE][SIZE];

void menushow();
void gamemenu();
void startgame();
void putpeg(char *player);

#endif