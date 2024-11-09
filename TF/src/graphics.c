// graphics.c
#include <SDL2/SDL.h>
#include "graphics.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

bool graphics_init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Conecta 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erro ao criar renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
    return true;
}

void graphics_draw_board() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Fundo azul
    SDL_RenderClear(renderer);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            SDL_Rect cell = { j * 80, i * 80, 80, 80 };
            if (board[i][j] == RED) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            } else if (board[i][j] == YELLOW) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            SDL_RenderFillRect(renderer, &cell);
        }
    }
    SDL_RenderPresent(renderer);
}

void graphics_cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}   