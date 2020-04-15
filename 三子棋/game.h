#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include <time.h>
#include <windows.h> 

#define ROW 3
#define COL 3 

#define player 'X'
#define computer 'O'




void Showboard(char board[][COL], int row, int col);
char Judge(char board[][COL], int row, int col);
void ComputerMove(char board[][COL], int row, int col);
void game();



#endif 

