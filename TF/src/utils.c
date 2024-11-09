// utils.c
#include <stdbool.h> // Adiciona esta linha
#include "utils.h"

bool utils_check_four_in_a_row(Piece piece) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Verifica linhas, colunas e diagonais
            if (j + 3 < COLS &&
                board[i][j] == piece &&
                board[i][j + 1] == piece &&
                board[i][j + 2] == piece &&
                board[i][j + 3] == piece)
                return true;

            if (i + 3 < ROWS &&
                board[i][j] == piece &&
                board[i + 1][j] == piece &&
                board[i + 2][j] == piece &&
                board[i + 3][j] == piece)
                return true;

            if (i + 3 < ROWS && j + 3 < COLS &&
                board[i][j] == piece &&
                board[i + 1][j + 1] == piece &&
                board[i + 2][j + 2] == piece &&
                board[i + 3][j + 3] == piece)
                return true;

            if (i - 3 >= 0 && j + 3 < COLS &&
                board[i][j] == piece &&
                board[i - 1][j + 1] == piece &&
                board[i - 2][j + 2] == piece &&
                board[i - 3][j + 3] == piece)
                return true;
        }
    }
    return false;
}