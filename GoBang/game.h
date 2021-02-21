#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 16
#define COL 16

//#define K '@'
//#define W 'O'

char sel_playermark();
char sel_computermark(char P);
void init_board(char board[ROW][COL]);
void disp_board(char board[ROW][COL]);
char who_first();
void start_game(char board[ROW][COL], char input, char P, char C);