#ifndef LINKS_H
#define LINKS_H

#include "game.h"

extern int movr[8];
extern int movc[8];

int haslink(int r1, int c1, int r2, int c2, char p);
int willcut(int r1, int c1, int r2, int c2);
void makelinks(int r, int c, char p);

#endif