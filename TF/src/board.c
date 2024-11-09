// board.c
#include <stdbool.h> // Adiciona esta linha
#include <stdio.h>    // Adiciona esta linha
#include "board.h"
#include "utils.h"
#include "types.h" 

Piece board[ROWS][COLS];

void board_init() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = NONE;
        }
    }
}

bool board_insert_piece(int col, Piece piece) {
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == NONE) {
            board[row][col] = piece;
            return true;
        }
    }
    return false;
}

void board_draw() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] == RED ? 'R' : (board[i][j] == YELLOW ? 'Y' : '.'));
        }
        printf("\n");
    }
}

bool board_check_win(Piece piece) {
    return utils_check_four_in_a_row(piece);
}