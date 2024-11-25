#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#define ROWS 6
#define COLUMNS 7

typedef enum {
    EMPTY,
    PLAYER1,
    PLAYER2
} Cell;

typedef struct {
    Cell board[ROWS][COLUMNS];
    int currentPlayer;
} Game;

void game_init(Game* game);
void game_handle_input(Game* game, int x, int y);
void game_update(Game* game);
void game_render(Game* game, SDL_Renderer* renderer, SDL_Texture* boardTexture, SDL_Texture* redTexture, SDL_Texture* yellowTexture);

#endif