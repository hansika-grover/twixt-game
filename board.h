#ifndef BOARD_H
#define BOARD_H

#include "game.h"

void setupgrid();
int inrange(int r, int c);
void drawline();
void showgrid();
void showlinks();

#endif