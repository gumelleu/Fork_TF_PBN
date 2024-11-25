#include "game.h"
#include <stdio.h>

void game_init(Game* game) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            game->board[i][j] = EMPTY;
        }
    }
    game->currentPlayer = PLAYER1;
}

void game_handle_input(Game* game, int x, int y) {
    int column = x / 100; // Ajustar com base na largura do tabuleiro
    if (column < 0 || column >= COLUMNS) return;

    for (int row = ROWS - 1; row >= 0; --row) {
        if (game->board[row][column] == EMPTY) {
            game->board[row][column] = game->currentPlayer;
            game->currentPlayer = (game->currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
            break;
        }
    }
}

void game_update(Game* game) {
    // Atualizações do estado do jogo podem ser feitas aqui
}

void game_render(Game* game, SDL_Renderer* renderer, SDL_Texture* boardTexture, SDL_Texture* redTexture, SDL_Texture* yellowTexture) {
    SDL_Rect boardRect = {50, 50, 700, 500}; // Ajustar dimensões
    SDL_RenderCopy(renderer, boardTexture, NULL, &boardRect);

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (game->board[i][j] != EMPTY) {
                SDL_Texture* pieceTexture = (game->board[i][j] == PLAYER1) ? redTexture : yellowTexture;
                SDL_Rect pieceRect = {50 + j * 100, 50 + i * 100, 90, 90}; // Ajustar tamanhos
                SDL_RenderCopy(renderer, pieceTexture, NULL, &pieceRect);
            }
        }
    }
}