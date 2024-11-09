// game.c
#include <stdio.h>
#include "game.h"
#include "graphics.h"
#include "board.h"
#include "player.h"

static Player player1, player2;
static Player *currentPlayer;

void game_init() {
    board_init();
    player_init(&player1, &player2);
    currentPlayer = &player1;
}

void game_loop() {
    bool running = true;
    int col;

    while (running) {
        graphics_draw_board();

        printf("Jogador %d, escolha uma coluna (0 a 6): ", currentPlayer->color);
        scanf("%d", &col);

        if (col < 0 || col >= COLS || !board_insert_piece(col, currentPlayer->color)) {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        if (board_check_win(currentPlayer->color)) {
            graphics_draw_board();
            printf("Jogador %d venceu!\n", currentPlayer->color);
            running = false;
        } else {
            currentPlayer = player_next_turn(currentPlayer);
        }
    }
}

void game_cleanup() {
    graphics_cleanup();
}