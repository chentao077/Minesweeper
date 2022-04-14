#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
void PrintBoard(char board[ROWS][COLS], int row, int col);
void SetMyboard(char board[ROWS][COLS], int row, int col);
void FindMyboard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);