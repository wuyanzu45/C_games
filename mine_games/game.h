#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define S '?'

#define ROW 6
#define COL 6

#define ROWS ROW+2
#define COLS COL+2

#define NUMBER 34

void init_board(char board[][COLS], char set);
void disp_board(char board[][COLS]);
void setmine(char board[][COLS]);
void searchmine(char mine[][COLS], char show[][COLS]);