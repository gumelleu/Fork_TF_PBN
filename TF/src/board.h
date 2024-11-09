// board.h
#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include "types.h" // Inclui types.h para reconhecer 'Piece'

#define ROWS 6
#define COLS 7

void board_init();
bool board_insert_piece(int col, Piece piece);
void board_draw();
bool board_check_win(Piece piece);

extern Piece board[ROWS][COLS];

#endif